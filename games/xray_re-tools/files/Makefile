CXXFLAGS+=	-Wall -Wextra
CPPFLAGS+=	-Ixray_re -Iutils/converter/opcode -I3rd-party/nvtt -I$(LOCALBASE)/include
LDFLAGS+=	-L$(LOCALBASE)/lib

xray_re_OBJS=	xray_re/xr_ai_cross_table.o \
		xray_re/xr_ai_graph.o \
		xray_re/xr_ai_way.o \
		xray_re/xr_blender.o \
		xray_re/xr_bone.o \
		xray_re/xr_build_err.o \
		xray_re/xr_build_lights.o \
		xray_re/xr_cform.o \
		xray_re/xr_cl_parser.o \
		xray_re/xr_clsid.o \
		xray_re/xr_d3d_light.o \
		xray_re/xr_details.o \
		xray_re/xr_dm.o \
		xray_re/xr_entity.o \
		xray_re/xr_entity_factory.o \
		xray_re/xr_entity_la.o \
		xray_re/xr_entity_script.o \
		xray_re/xr_entity_zenobian.o \
		xray_re/xr_envelope.o \
		xray_re/xr_envelope_eval.o \
		xray_re/xr_file_system.o \
		xray_re/xr_file_system_posix.o \
		xray_re/xr_game_graph.o \
		xray_re/xr_game_spawn.o \
		xray_re/xr_gamemtls_lib.o \
		xray_re/xr_geom_buf.o \
		xray_re/xr_guid.o \
		xray_re/xr_image.o \
		xray_re/xr_image_bmp.o \
		xray_re/xr_image_dds.o \
		xray_re/xr_image_tga.o \
		xray_re/xr_influence.o \
		xray_re/xr_ini_file.o \
		xray_re/xr_level.o \
		xray_re/xr_level_ai.o \
		xray_re/xr_level_cform.o \
		xray_re/xr_level_details.o \
		xray_re/xr_level_dm.o \
		xray_re/xr_level_env_mod.o \
		xray_re/xr_level_fog_vol.o \
		xray_re/xr_level_game.o \
		xray_re/xr_level_gct.o \
		xray_re/xr_level_gct_v9.o \
		xray_re/xr_level_geom.o \
		xray_re/xr_level_glows.o \
		xray_re/xr_level_graph.o \
		xray_re/xr_level_hom.o \
		xray_re/xr_level_lights.o \
		xray_re/xr_level_ltx.o \
		xray_re/xr_level_portals.o \
		xray_re/xr_level_ps_static.o \
		xray_re/xr_level_sectors.o \
		xray_re/xr_level_shaders.o \
		xray_re/xr_level_snd_env.o \
		xray_re/xr_level_snd_static.o \
		xray_re/xr_level_som.o \
		xray_re/xr_level_spawn.o \
		xray_re/xr_level_visuals.o \
		xray_re/xr_level_wallmarks.o \
		xray_re/xr_log.o \
		xray_re/xr_lzhuf.o \
		xray_re/xr_matrix.o \
		xray_re/xr_mesh.o \
		xray_re/xr_mesh_builder.o \
		xray_re/xr_mesh_vbuf.o \
		xray_re/xr_motion.o \
		xray_re/xr_name_gen.o \
		xray_re/xr_obj_motion.o \
		xray_re/xr_object.o \
		xray_re/xr_ogf.o \
		xray_re/xr_ogf_v3.o \
		xray_re/xr_ogf_v4.o \
		xray_re/xr_packet.o \
		xray_re/xr_quaternion.o \
		xray_re/xr_reader.o \
		xray_re/xr_reader_scrambler.o \
		xray_re/xr_scene.o \
		xray_re/xr_scene_ai_map.o \
		xray_re/xr_scene_details.o \
		xray_re/xr_scene_glows.o \
		xray_re/xr_scene_groups.o \
		xray_re/xr_scene_lights.o \
		xray_re/xr_scene_objects.o \
		xray_re/xr_scene_part.o \
		xray_re/xr_scene_particles.o \
		xray_re/xr_scene_portals.o \
		xray_re/xr_scene_revision.o \
		xray_re/xr_scene_sectors.o \
		xray_re/xr_scene_shapes.o \
		xray_re/xr_scene_sound_envs.o \
		xray_re/xr_scene_sound_srcs.o \
		xray_re/xr_scene_spawns.o \
		xray_re/xr_scene_visuals.o \
		xray_re/xr_scene_wallmarks.o \
		xray_re/xr_scene_ways.o \
		xray_re/xr_scrambler.o \
		xray_re/xr_shaders_lib.o \
		xray_re/xr_shaders_xrlc_lib.o \
		xray_re/xr_skeleton.o \
		xray_re/xr_skl_motion.o \
		xray_re/xr_sound_thumbnail.o \
		xray_re/xr_surface.o \
		xray_re/xr_texture_thumbnail.o \
		xray_re/xr_vector3.o \
		xray_re/xr_writer.o

converter_OBJS=	utils/converter/batch_helper.o \
		utils/converter/converter.o \
		utils/converter/db_tools.o \
		utils/converter/dds_tools.o \
		utils/converter/dm_tools.o \
		utils/converter/fancy_tools.o \
		utils/converter/level_aux_mesh.o \
		utils/converter/level_mesh.o \
		utils/converter/level_mesh_commit.o \
		utils/converter/level_mesh_ladders.o \
		utils/converter/level_mesh_materials.o \
		utils/converter/level_mesh_terrain.o \
		utils/converter/level_tools.o \
		utils/converter/level_tools_ai_map.o \
		utils/converter/level_tools_debug_cform.o \
		utils/converter/level_tools_details.o \
		utils/converter/level_tools_glows.o \
		utils/converter/level_tools_hom.o \
		utils/converter/level_tools_lights.o \
		utils/converter/level_tools_particles.o \
		utils/converter/level_tools_portals.o \
		utils/converter/level_tools_sectors.o \
		utils/converter/level_tools_som.o \
		utils/converter/level_tools_sound_envs.o \
		utils/converter/level_tools_sound_srcs.o \
		utils/converter/level_tools_spawns.o \
		utils/converter/level_tools_visuals.o \
		utils/converter/level_tools_wallmarks.o \
		utils/converter/level_tools_ways.o \
		utils/converter/object_tools.o \
		utils/converter/ogf_tools.o \
		utils/converter/ogg_tools.o \
		utils/converter/opcode/Ice/IceAABB.o \
		utils/converter/opcode/Ice/IceContainer.o \
		utils/converter/opcode/Ice/IceHPoint.o \
		utils/converter/opcode/Ice/IceMatrix4x4.o \
		utils/converter/opcode/Ice/IcePoint.o \
		utils/converter/opcode/Ice/IceRandom.o \
		utils/converter/opcode/OPC_AABBTree.o \
		utils/converter/opcode/OPC_BaseModel.o \
		utils/converter/opcode/OPC_Collider.o \
		utils/converter/opcode/OPC_MeshInterface.o \
		utils/converter/opcode/OPC_Model.o \
		utils/converter/opcode/OPC_OptimizedTree.o \
		utils/converter/opcode/OPC_TreeBuilders.o \
		utils/converter/opcode/OPC_TreeCollider.o \
		utils/converter/xrdemo_tools.o

.cpp.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

.cxx.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

all: converter

converter: $(xray_re_OBJS) $(converter_OBJS)
	$(CXX) $(LDFLAGS) -llzo2 -lnvcore -lnvimage -lnvtt -lvorbisfile -lz -o $@ $>

.PHONY: all
