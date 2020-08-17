# $FreeBSD$

PORTNAME=	ocp
DISTVERSION=	7.4-RC2
CATEGORIES=	cad
# Direct access to github is needed because the release added an extra archive which
# we need to build from, rather than the initial release.
MASTER_SITES=	https://github.com/CadQuery/OCP/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	OCP_src_Linux

MAINTAINER=	ports@nicandneal.net
COMMENT=	Python wrapper for OCCT generated using pywrap

LICENSE=	APACHE20

PATCH_DEPENDS=	${LOCALBASE}/include/OpenCASCADE/OpenGl_HaltonSampler.hxx:cad/opencascade
LIB_DEPENDS=	libTKernel.so:cad/opencascade
BUILD_DEPENDS=	${LOCALBASE}/share/cmake/pybind11/pybind11Config.cmake:devel/pybind11 \
		${PYTHON_SITELIBDIR}/pybind11:devel/py-pybind11@${PY_FLAVOR}

USES=		cmake compiler:c++11-lang gl python:3.6+ zip
USE_GL=		gl glu glut

WRKSRC=		${WRKDIR}/OCP_src_Ubuntu-16.04

OCCT=		${LOCALBASE}/include/OpenCASCADE
OCCT_LOCAL=	${WRKSRC}/OCCT

CMAKE_ARGS=	-DOPENCASCADE_INCLUDE_DIR=${OCCT} \
		-DPYTHON_EXECUTABLE=${PYTHON_CMD}

USE_PYTHON=	flavors

PLIST_FILES=	${PYTHON_SITELIBDIR}/OCP.so

pre-patch:
# Copy and patch a header file with a troublesome C++ standard mismatch.
	${MKDIR} ${OCCT_LOCAL}
	${CP} ${OCCT}/OpenGl_HaltonSampler.hxx ${OCCT_LOCAL}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_LIB} ${BUILD_WRKSRC}/OCP.so ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
