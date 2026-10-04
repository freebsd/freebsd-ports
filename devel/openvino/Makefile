PORTNAME=	openvino
DISTVERSION=	2026.1.2
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Open-source toolkit for optimizing and deploying AI inference
WWW=		https://docs.openvino.ai

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jax>=0.4.2:math/py-jax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tensorflow>0:science/py-tensorflow@${PY_FLAVOR} \
		computelibrary>0:devel/computelibrary \
		patchelf>0:sysutils/patchelf

LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
		libtbb.so:devel/onetbb

USES=		cmake pkgconfig python

USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	openvinotoolkit
GH_PROJECT=	openvino
GH_TUPLE=	herumi:xbyak:0d67fd1530016b7c56f3cd74b3fca920f4c3e2b4:xbyak_/thirdparty/xbyak \
		madler:zlib:51b7f2a:zlib/thirdparty/zlib/zlib \
		zeux:pugixml:ee86beb:pugixml/thirdparty/pugixml \
		gflags:gflags:e171aa2:gflags/thirdparty/gflags/gflags \
		openvinotoolkit:googletest:99760ac:gtest/thirdparty/gtest/gtest \
		KhronosGroup:OpenCL-ICD-Loader:5907ac1:icd/thirdparty/ocl/icd_loader \
		KhronosGroup:OpenCL-Headers:4ea6df1:head/thirdparty/ocl/cl_headers \
		KhronosGroup:OpenCL-CLHPP:c7b4ade:clhpp/thirdparty/ocl/clhpp_headers \
		onnx:onnx:e709452:onnx/thirdparty/onnx/onnx \
		protocolbuffers:protobuf:f0dc78d:protobuf/thirdparty/protobuf/protobuf \
		pybind:pybind11:f5fbe86:pybind/src/bindings/python/thirdparty/pybind11 \
		intel:ittapi:ca45fef:ittapy/thirdparty/ittapi/ittapi \
		nithinn:ncc:63e59ed:ncc/cmake/developer_package/ncc_naming_style/ncc \
		oneapi-src:level-zero:d562046:zero/thirdparty/level_zero/level-zero \
		nlohmann:json:9cca280:json/thirdparty/json/nlohmann_json \
		google:flatbuffers:595bf00:flatbuffers/thirdparty/flatbuffers/flatbuffers \
		google:snappy:2c94e11:snapppy/thirdparty/snappy \
		intel:level-zero-npu-extensions:42768cc:npu/src/plugins/intel_npu/thirdparty/level-zero-ext \
		jbeder:yaml-cpp:da82fd9:yaml/src/plugins/intel_npu/thirdparty/yaml-cpp \
		openvinotoolkit:telemetry:8abddc3:telemetry/thirdparty/telemetry \
		libxsmm:libxsmm:13df674:libxsmm/src/plugins/intel_cpu/thirdparty/libxsmm \
		openvinotoolkit:oneDNN:6b6492b:onednn_/src/plugins/intel_cpu/thirdparty/onednn \
		ARM-software:kleidiai:7d82645:kleidiai/src/plugins/intel_cpu/thirdparty/kleidiai \
		herumi:xbyak_riscv:07139a6:xbyak/src/plugins/intel_cpu/thirdparty/xbyak_riscv \
		openvinotoolkit:mlas:d1bc25e:mlas/src/plugins/intel_cpu/thirdparty/mlas \
		oneapi-src:oneDNN:470e87e:onednn/src/plugins/intel_gpu/thirdparty/onednn_gpu

CMAKE_ARGS=	-DARM_COMPUTE_INCLUDE_DIR=${LOCALBASE}/include/computelibrary \
		-DARM_COMPUTE_LIB_DIR=${LOCALBASE}/lib \
		-DCMAKE_INSTALL_PREFIX=${STAGEDIR}${PREFIX} \
		-DDNNL_GPU_RUNTIME:STRING=OCL \
		-DONEDNN_ENABLE_PRIMITIVE:STRING=ALL \
		-DTBB_DIR="${LOCALBASE}/lib/cmake/TBB/"

CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_OV_IR_FRONTEND ENABLE_OV_ONNX_FRONTEND \
		ENABLE_OV_PADDLE_FRONTEND ENABLE_OV_PYTORCH_FRONTEND \
		ENABLE_OV_TF_LITE_FRONTEND ENABLE_PKGCONFIG_GEN \
		ENABLE_PLUGINS_XML ENABLE_PYTHON ENABLE_SYSTEM_TBB \
		ENABLE_INTEL_NPU ENABLE_INTEL_NPU_COMPILER
CMAKE_OFF=	ENABLE_JS ENABLE_ONEDNN_FOR_GPU ENABLE_OV_JAX_FRONTEND  \
		ENABLE_SAMPLES ONEDNN_BUILD_GRAPH # broken NPU API

do-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	cd ${WRKSRC}/src/bindings/python/src/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/bindings/c/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/core/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/frontend
	cd ${WRKSRC}/src/frontends/common/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/ir/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/onnx/frontend/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/pytorch/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/tensorflow/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/tensorflow_lite/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/inference/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/bin/intel64/Release/libopenvino*  ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/openvino
	${INSTALL_DATA} ${BUILD_WRKSRC}/OpenVINOConfig-version.cmake ${STAGEDIR}${PREFIX}/lib/cmake/openvino
	${INSTALL_DATA} ${BUILD_WRKSRC}/OpenVINOConfig.cmake ${STAGEDIR}${PREFIX}/lib/cmake/openvino
	${INSTALL_DATA} ${BUILD_WRKSRC}/OpenVINOTargets.cmake ${STAGEDIR}${PREFIX}/lib/cmake/openvino

post-install:
	${RM} ${STAGEDIR}${PREFIX}/setupvars.sh
	${RM} -rf ${STAGEDIR}${PREFIX}/install_dependencies
	${RM} -rf ${STAGEDIR}${PREFIX}/licenses

.include <bsd.port.mk>
