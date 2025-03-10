--- zeno/src/nodes/zeno_animation.cpp.orig	2024-11-30 18:56:29 UTC
+++ zeno/src/nodes/zeno_animation.cpp
@@ -0,0 +1,477 @@
+//
+// Created by zhouhang on 2024/3/28.
+//
+#include <zeno/zeno.h>
+#include <zeno/types/PrimitiveObject.h>
+#include <zeno/types/NumericObject.h>
+#include <zeno/types/UserData.h>
+#include <zeno/extra/GlobalState.h>
+#include <zeno/utils/log.h>
+#include <zeno/utils/fileio.h>
+#include <glm/glm.hpp>
+#include <glm/gtc/matrix_transform.hpp>
+#include <glm/gtx/transform.hpp>
+#include <glm/gtx/quaternion.hpp>
+#include <numeric>
+namespace zeno {
+struct ReadNeoxModel : INode {
+    virtual void apply() override {
+        auto path = get_input2<std::string>("path");
+        auto prim = std::make_shared<PrimitiveObject>();
+        auto reader = BinaryReader(file_get_binary(path));
+        reader.skip(8);
+        auto bone_exist = reader.read_LE<int32_t>();
+        std::vector<int> parent_nodes;
+        std::vector<std::string> bone_names;
+        std::vector<glm::mat4> bone_bind_matrix;
+
+        if (bone_exist) {
+            if (bone_exist > 1) {
+                auto count = reader.read_LE<uint8_t>();
+                reader.skip(2);
+                reader.skip(count * 4);
+            }
+            auto bone_count = reader.read_LE<uint16_t>();
+            for (auto i = 0; i < bone_count; i++) {
+                auto parent_node = int(reader.read_LE<uint8_t>());
+                if (parent_node == 255) {
+                    parent_node = -1;
+                }
+                parent_nodes.push_back(parent_node);
+            }
+            for (auto i = 0; i < bone_count; i++) {
+                auto bone_name = reader.read_string(32);
+                bone_names.push_back(bone_name);
+            }
+            auto bone_extra_info = reader.read_LE<uint8_t>();
+            if (bone_extra_info) {
+                reader.skip(28 * bone_count);
+            }
+            for (auto i = 0; i < bone_count; i++) {
+                auto bind_matrix = reader.read_LE<glm::mat4>();
+                bone_bind_matrix.push_back(bind_matrix);
+            }
+            auto _flag = reader.read_LE<uint8_t>();
+            if (_flag != 0) {
+                zeno::log_error("assert error");
+            }
+        }
+        prim->userData().set2("boneName_count", int(bone_names.size()));
+        for (auto i = 0; i < bone_names.size(); i++) {
+            prim->userData().set2(format("boneName_{}", i), bone_names[i]);
+        }
+        std::vector<vec4i> meshes;
+        {
+            auto _offset = reader.read_LE<uint32_t>();
+            while (true) {
+                auto flag = reader.read_LE<uint16_t>();
+                if (flag == 1) {
+                    break;
+                }
+                reader.skip(-2);
+                auto mesh_vertex_count = reader.read_LE<uint32_t>();
+                auto mesh_face_count = reader.read_LE<uint32_t>();
+                auto uv_layers = reader.read_LE<uint8_t>();
+                auto color_len = reader.read_LE<uint8_t>();
+                meshes.emplace_back(mesh_vertex_count, mesh_face_count, uv_layers, color_len);
+            }
+        }
+        auto vertex_count = reader.read_LE<uint32_t>();
+        auto face_count = reader.read_LE<uint32_t>();
+        prim->verts.resize(vertex_count);
+        for (auto i = 0; i < vertex_count; i++) {
+            prim->verts[i] = reader.read_LE<vec3f>() * vec3f(-1, 1, 1);
+        }
+        auto &nrm = prim->verts.add_attr<vec3f>("nrm");
+        for (auto i = 0; i < vertex_count; i++) {
+            nrm[i] = reader.read_LE<vec3f>();
+        }
+        auto flag = reader.read_LE<uint16_t>();
+        if (flag) {
+            reader.skip(vertex_count * 12);
+        }
+        prim->tris.resize(face_count);
+        for (auto i = 0; i < face_count; i++) {
+            auto f0 = int(reader.read_LE<uint16_t>());
+            auto f1 = int(reader.read_LE<uint16_t>());
+            auto f2 = int(reader.read_LE<uint16_t>());
+            prim->tris[i] = {f0, f2, f1};
+        }
+        for (auto [mesh_vertex_count, mesh_face_count, uv_layers, color_len]: meshes) {
+            reader.skip(mesh_vertex_count * 8 * uv_layers);
+        }
+        for (auto [mesh_vertex_count, mesh_face_count, uv_layers, color_len]: meshes) {
+            reader.skip(mesh_vertex_count * 4 * color_len);
+        }
+
+        int start = reader.current();
+        if (bone_exist) {
+            auto &bi = prim->verts.add_attr<vec4i>("boneName");
+            for (auto i = 0; i < prim->verts.size(); i++) {
+                auto _0 = int(reader.read_LE<uint8_t>());
+                auto _1 = int(reader.read_LE<uint8_t>());
+                auto _2 = int(reader.read_LE<uint8_t>());
+                auto _3 = int(reader.read_LE<uint8_t>());
+                bi[i] = {_0, _1, _2, _3};
+                for (auto j = 0; j < 4; j++) {
+                    if (bi[i][j] == 255) {
+                        bi[i][j] = -1;
+                    }
+                }
+            }
+            auto &bw = prim->verts.add_attr<vec4f>("boneWeight");
+            for (auto i = 0; i < prim->verts.size(); i++) {
+                bw[i] = {
+                    reader.read_LE<float>(),
+                    reader.read_LE<float>(),
+                    reader.read_LE<float>(),
+                    reader.read_LE<float>(),
+                };
+            }
+        }
+
+        set_output("prim", prim);
+        auto bones = std::make_shared<PrimitiveObject>();
+
+        bones->verts.resize(bone_names.size());
+        auto &transform_r0 = bones->verts.add_attr<vec3f>("transform_r0");
+        auto &transform_r1 = bones->verts.add_attr<vec3f>("transform_r1");
+        auto &transform_r2 = bones->verts.add_attr<vec3f>("transform_r2");
+        for (auto i = 0; i < bones->verts.size(); i++) {
+            auto bind_matrix = bone_bind_matrix[i];
+            glm::mat4 m(1);
+            m[0][0] = -1;
+            bind_matrix = m * bind_matrix;
+            transform_r0[i] = {bind_matrix[0][0], bind_matrix[0][1], bind_matrix[0][2]};
+            transform_r1[i] = {bind_matrix[1][0], bind_matrix[1][1], bind_matrix[1][2]};
+            transform_r2[i] = zeno::cross(transform_r0[i], transform_r1[i]);
+            auto pos = bind_matrix[3];
+            bones->verts[i] = {pos[0], pos[1], pos[2]};
+        }
+        std::vector<int> loops;
+        for (auto i = 0; i < parent_nodes.size(); i++) {
+            if (parent_nodes[i] != -1) {
+                loops.push_back(parent_nodes[i]);
+                loops.push_back(i);
+            }
+        }
+        bones->loops = loops;
+        bones->polys.resize(loops.size() / 2);
+        for (auto i = 0; i < bones->polys.size(); i++) {
+            bones->polys[i] = {i * 2, 2};
+        }
+
+        bones->userData().set2("boneName_count", int(bone_names.size()));
+        for (auto i = 0; i < bone_names.size(); i++) {
+            bones->userData().set2(format("boneName_{}", i), bone_names[i]);
+        }
+        set_output("bones", bones);
+    }
+};
+
+ZENDEFNODE(ReadNeoxModel, {
+    {
+        {"readpath", "path"},
+    },
+    {
+        "prim",
+        "bones",
+    },
+    {},
+    {"Neox"},
+});
+
+struct BoneTran {
+    glm::vec3 pos;
+    glm::quat rot;
+    glm::vec3 scale;
+    glm::mat4 to_matrix() {
+        glm::mat4 matTrans = glm::translate(pos);
+        glm::mat4 matQuat  = glm::toMat4(rot);
+        glm::mat4 matScal  = glm::scale( scale);
+        return matTrans * matQuat * matScal;
+    }
+};
+struct AnimInfo {
+    uint32_t fps;
+    uint8_t is_loop;
+    uint8_t has_scaled;
+    uint16_t prs_flags;
+    uint32_t accum_flags;
+    uint8_t pack_prs_flags;
+    uint8_t bone_separate_flags;
+    void read_from_reader(BinaryReader &reader) {
+        fps = reader.read_LE<uint32_t>();
+        is_loop = reader.read_LE<uint8_t>();
+        has_scaled = reader.read_LE<uint8_t>();
+        prs_flags = reader.read_LE<uint16_t>();
+        accum_flags = reader.read_LE<uint32_t>();
+        pack_prs_flags = reader.read_LE<uint8_t>();
+        bone_separate_flags = reader.read_LE<uint8_t>();
+    }
+};
+struct ReadNeoxAnimation : INode {
+    virtual void apply() override {
+        auto path = get_input2<std::string>("path");
+        auto anim = std::make_shared<PrimitiveObject>();
+        auto reader = BinaryReader(file_get_binary(path));
+        reader.skip(4);
+        auto _version = reader.read_LE<uint32_t>();
+        auto anim_count = reader.read_LE<uint16_t>();
+        anim->userData().set2("anim_count", int(anim_count));
+        auto bone_count = reader.read_LE<uint32_t>();
+        anim->userData().set2("boneName_count", int(bone_count));
+        std::vector<std::string> bone_names;
+        for (auto i = 0; i < bone_count; i++) {
+            auto bone_name = reader.read_string(32);
+            bone_names.push_back(bone_name);
+        }
+        anim->userData().set2("boneName_count", int(bone_names.size()));
+        for (auto i = 0; i < bone_names.size(); i++) {
+            anim->userData().set2(format("boneName_{}", i), bone_names[i]);
+        }
+        std::vector<BoneTran> bone_transs;
+        for (auto i = 0; i < bone_count; i++) {
+            BoneTran bone_trans;
+            bone_trans.pos = reader.read_LE<glm::vec3>();
+            bone_trans.rot = reader.read_LE<glm::quat>();
+            bone_trans.scale = reader.read_LE<glm::vec3>();
+            bone_transs.push_back(bone_trans);
+        }
+        auto separate_storage = reader.read_LE<uint16_t>();
+        auto _base_size = reader.read_LE<uint16_t>();
+        if (separate_storage > 0) {
+            reader.read_LE<uint32_t>();
+        }
+        for (auto i = 0; i < anim_count; i++) {
+            auto anim_name = reader.read_string(32);
+            anim->userData().set2(format("anim_name_{}", i), anim_name);
+            auto anim_root_name = reader.read_string(32);
+            anim->userData().set2(format("anim_root_name_{}", i), anim_root_name);
+            auto bone_count = reader.read_LE<uint16_t>();
+            reader.skip(1020);
+            AnimInfo animInfo;
+            animInfo.read_from_reader(reader);
+            reader.skip(8);
+        }
+
+        set_output("anim", anim);
+    }
+};
+
+ZENDEFNODE(ReadNeoxAnimation, {
+    {
+        {"readpath", "path"},
+    },
+    {
+        "anim",
+    },
+    {},
+    {"Neox"},
+});
+glm::vec3 read_half3(BinaryReader &reader) {
+    auto x = glm::detail::toFloat32(reader.read_LE<int16_t>());
+    auto y = glm::detail::toFloat32(reader.read_LE<int16_t>());
+    auto z = glm::detail::toFloat32(reader.read_LE<int16_t>());
+    return {x, y, z};
+}
+glm::quat read_half_quat(BinaryReader &reader) {
+    auto x = glm::detail::toFloat32(reader.read_LE<int16_t>());
+    auto y = glm::detail::toFloat32(reader.read_LE<int16_t>());
+    auto z = glm::detail::toFloat32(reader.read_LE<int16_t>());
+    auto w = glm::detail::toFloat32(reader.read_LE<int16_t>());
+    return {w, x, y, z};
+}
+struct ReadNeoxSubAnimation : INode {
+    void search(int ci, std::vector<glm::mat4> &matrixs, std::map<int, int> &c2p, std::map<int, glm::mat4> &result) {
+        zeno::log_info("{}", ci);
+        if (result.count(ci)) {
+            zeno::log_info("result found");
+            return;
+        }
+        if (c2p.count(ci) == 0) {
+            zeno::log_info("not parent");
+            result[ci] = matrixs[ci];
+            zeno::log_info("use matrixs");
+        }
+        else {
+            auto pi = c2p[ci];
+            if (result.count(pi) == 0) {
+                search(pi, matrixs, c2p, result);
+            }
+            result[ci] = result[pi] * matrixs[ci];
+        }
+    }
+    virtual void apply() override {
+        int frameid;
+        if (has_input("frameid")) {
+            frameid = std::lround(get_input2<float>("frameid"));
+        } else {
+            frameid = getGlobalState()->frameid;
+        }
+        auto path = get_input2<std::string>("path");
+        auto anim = std::make_shared<PrimitiveObject>();
+        auto reader = BinaryReader(file_get_binary(path));
+        auto anim_name = reader.read_string(32);
+        anim->userData().set2("anim_name", anim_name);
+
+        auto anim_root_name = reader.read_string(32);
+        auto bone_count = reader.read_LE<uint16_t>();
+        std::vector<std::string> bone_names;
+        for (auto i = 0; i < bone_count; i++) {
+            auto bone_name = reader.read_string(32);
+            bone_names.push_back(bone_name);
+        }
+        anim->userData().set2("boneName_count", int(bone_names.size()));
+        for (auto i = 0; i < bone_names.size(); i++) {
+            anim->userData().set2(format("boneName_{}", i), bone_names[i]);
+        }
+        AnimInfo animInfo;
+        animInfo.read_from_reader(reader);
+        auto key_count = reader.read_LE<uint16_t>();
+        frameid = zeno::clamp(frameid, 0, key_count - 1);
+        anim->userData().set2("key_count", int(key_count));
+        for (auto i = 0; i < key_count; i++) {
+            auto key_time = reader.read_LE<float>();
+        }
+        anim->verts.resize(bone_count);
+        auto &boneName = anim->verts.add_attr<int>("boneName");
+        std::iota(boneName.begin(), boneName.end(), 0);
+        auto &transform_r0 = anim->verts.add_attr<vec3f>("transform_r0");
+        auto &transform_r1 = anim->verts.add_attr<vec3f>("transform_r1");
+        auto &transform_r2 = anim->verts.add_attr<vec3f>("transform_r2");
+        auto &raw_pos = anim->verts.add_attr<vec3f>("raw_pos");
+        auto &raw_rot = anim->verts.add_attr<vec4f>("raw_rot");
+        auto &raw_scale = anim->verts.add_attr<vec3f>("raw_scale");
+        auto &_has_pos_keys = anim->verts.add_attr<int>("has_pos_keys");
+        auto &_has_rot_keys = anim->verts.add_attr<int>("has_rot_keys");
+        auto &_has_scale_keys = anim->verts.add_attr<int>("has_scale_keys");
+        std::vector<glm::mat4> matrixs;
+        for (auto i = 0; i < bone_count; i++) {
+            auto has_pos_keys = reader.read_LE<uint8_t>();
+            auto has_rot_keys = reader.read_LE<uint8_t>();
+            auto has_scale_keys = reader.read_LE<uint8_t>();
+            _has_pos_keys[i] = int(has_pos_keys);
+            _has_rot_keys[i] = int(has_rot_keys);
+            _has_scale_keys[i] = int(has_scale_keys);
+            auto euler_flags = reader.read_LE<uint8_t>();
+            BoneTran boneTran = {};
+            if (has_pos_keys) {
+                for (auto j = 0; j < key_count; j++) {
+                    auto pos = reader.read_LE<glm::vec3>();
+                    if (j == frameid) {
+                        boneTran.pos = pos;
+                    }
+                }
+            } else {
+                boneTran.pos = reader.read_LE<glm::vec3>();
+            }
+
+            if (has_rot_keys) {
+                for (auto j = 0; j < key_count; j++) {
+                    auto rot = read_half_quat(reader);
+                    if (j == frameid) {
+                        boneTran.rot = rot;
+                    }
+                }
+            } else {
+                boneTran.rot = read_half_quat(reader);
+            }
+            if (has_scale_keys) {
+                for (auto j = 0; j < key_count; j++) {
+                    auto scale = read_half3(reader);
+                    if (j == frameid) {
+                        boneTran.scale = scale;
+                    }
+                }
+            } else {
+                boneTran.scale = read_half3(reader);
+            }
+            for (auto j = 0; j < 3; j++) {
+                if (std::abs(boneTran.pos[j]) < 0.001) {
+                    boneTran.pos[j] = 0;
+                }
+                if (std::abs(boneTran.scale[j] - 1) < 0.001) {
+                    boneTran.scale[j] = 1;
+                }
+            }
+            for (auto j = 0; j < 4; j++) {
+                if (std::abs(boneTran.rot[j]) < 0.001) {
+                    boneTran.rot[j] = 0;
+                }
+                if (std::abs(boneTran.rot[j] - 1) < 0.001) {
+                    boneTran.rot[j] = 1;
+                }
+            }
+
+            auto matrix = boneTran.to_matrix();
+            matrixs.push_back(matrix);
+            transform_r0[i] = {matrix[0][0], matrix[0][1], matrix[0][2]};
+            transform_r1[i] = {matrix[1][0], matrix[1][1], matrix[1][2]};
+            transform_r2[i] = {matrix[2][0], matrix[2][1], matrix[2][2]};
+            auto pos = matrix[3];
+            anim->verts[i] = {pos[0], pos[1], pos[2]};
+            raw_pos[i] = other_to_vec<3>(boneTran.pos);
+            raw_rot[i] = other_to_vec<4>(boneTran.rot);
+            raw_scale[i] = other_to_vec<3>(boneTran.scale);
+        }
+        if (has_input("skeleton")) {
+            std::vector<int> loops;
+            std::map<int, int> c2p;
+            auto skeleton = get_input2<PrimitiveObject>("skeleton");
+            for (auto i = 0; i < skeleton->polys.size(); i++) {
+                auto p = skeleton->loops[i * 2 + 0];
+                auto c = skeleton->loops[i * 2 + 1];
+                auto pn = skeleton->userData().get2<std::string>(format("boneName_{}", p));
+                auto cn = skeleton->userData().get2<std::string>(format("boneName_{}", c));
+                auto pi = std::find(bone_names.begin(), bone_names.end(), pn) - bone_names.begin();
+                auto ci = std::find(bone_names.begin(), bone_names.end(), cn) - bone_names.begin();
+                if (pi != bone_names.size() && ci != bone_names.size()) {
+                    loops.push_back(pi);
+                    loops.push_back(ci);
+                    c2p[ci] = pi;
+                }
+            }
+            anim->loops = loops;
+            anim->polys.resize(loops.size() / 2);
+            for (auto i = 0; i < anim->polys.size(); i++) {
+                anim->polys[i] = {i * 2, 2};
+            }
+            std::map<int, glm::mat4> result;
+
+            for (auto i = 0; i < anim->polys.size(); i++) {
+                search(anim->loops[2 * i + 1], matrixs, c2p, result);
+            }
+            for (auto i = 0; i < anim->verts.size(); i++) {
+                auto matrix = matrixs[i];
+
+                if (result.count(i)) {
+                    matrix = result[i];
+                }
+                glm::mat4 m(1);
+                m[0][0] = -1;
+                matrix = m * matrix;
+                transform_r0[i] = {matrix[0][0], matrix[0][1], matrix[0][2]};
+                transform_r1[i] = {matrix[1][0], matrix[1][1], matrix[1][2]};
+                transform_r2[i] = zeno::cross(transform_r0[i], transform_r1[i]);
+                auto pos = matrix[3];
+                anim->verts[i] = {pos[0], pos[1], pos[2]};
+            }
+        }
+        set_output("anim", anim);
+    }
+};
+
+ZENDEFNODE(ReadNeoxSubAnimation, {
+    {
+        {"readpath", "path"},
+        {"frameid"},
+        "skeleton",
+    },
+    {
+        "anim",
+    },
+    {},
+    {"Neox"},
+});
+}
