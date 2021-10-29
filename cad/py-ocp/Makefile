PORTNAME=	ocp
DISTVERSION=	7.5.2
CATEGORIES=	cad python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	Python wrapper for OCCT generated using pywrap

LICENSE=	APACHE20

EXTRACT_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cadquery-pywrap>0:devel/py-cadquery-pywrap@${PY_FLAVOR}
LIB_DEPENDS=	libTKernel.so:cad/opencascade \
		libvtksys-${VTKVER}.so:math/vtk9
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		pybind11>0:devel/pybind11 \
		rapidjson>0:devel/rapidjson \
		${PYTHON_PKGNAMEPREFIX}path>0:devel/py-path@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lief>0:devel/py-lief@${PY_FLAVOR}

USES=		python:3.6+ cmake gl compiler:c++11-lang
USE_GL=		gl glu glut

USE_GITHUB=	yes
GH_ACCOUNT=	CadQuery
GH_PROJECT=	OCP
GH_TAGNAME=	52c15d8

VTKVER=         9.0

CONFIG_FILE=	${WRKSRC}/ocp.toml

OCCT=           ${LOCALBASE}/include/OpenCASCADE

CMAKE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHON_CMD} \
		-DOPENCASCADE_INCLUDE_DIR=${OCCT} \
		-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-${VTKVER}/cmake/vtk-${VTKVER}
CMAKE_SOURCE_PATH=	${WRKSRC}/OCP

PLIST_FILES=    ${PYTHON_SITELIBDIR}/OCP.so

export CONDA_PREFIX=	${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e 's|input_folder = "./opencascade"|input_folder = "${OCCT}"|g' ${WRKSRC}/ocp.toml

pre-configure:
	# Generate the header files.
	(cd ${WRKSRC} && ${PYTHON_CMD} dump_symbols.py ${LOCALBASE})
	(cd ${WRKSRC} && CONDA_PREFIX=${LOCALBASE}; \
	 ${PYTHON_CMD} -m bindgen -n ${MAKE_JOBS_NUMBER} \
	 --libclang=${LOCALBASE}/llvm90/lib/libclang.so \
	 --include=${LOCALBASE}/include \
	 --include=${LOCALBASE}/include/vtk-${VTKVER} \
	 all ${CONFIG_FILE})

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_LIB} ${BUILD_WRKSRC}/OCP.cpython-${PYTHON_VER:S/.//}.so ${STAGEDIR}${PYTHON_SITELIBDIR}/OCP.so

.include <bsd.port.mk>
