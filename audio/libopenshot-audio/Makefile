PORTNAME=	libopenshot-audio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	audio multimedia

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	OpenShot Audio Library

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libsysinfo.so:devel/libsysinfo
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	OpenShot
USE_LDCONFIG=	yes
CMAKE_OFF=	DOXYFILE_LATEX

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_USES=	python:3.6+,build
DOCS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen\
			CMAKE_DISABLE_FIND_PACKAGE_PythonInterp
DOCS_CMAKE_ON=	-DCMAKE_INSTALL_DOCDIR:PATH=${DOCSDIR_REL:Q}
DOCS_PORTDOCS=	*

do-build-DOCS-on:
	@(cd ${BUILD_WRKSRC}; if ! ${DO_MAKE_BUILD} doc; then \
		(${ECHO_CMD} "===> ${.TARGET} failed unexpectedly.") | ${FMT_80} ; \
		${FALSE}; \
		fi)

.include <bsd.port.mk>
