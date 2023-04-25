PORTNAME=	libopenshot-audio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	audio multimedia

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	OpenShot Audio Library
WWW=		https://www.openshot.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libsysinfo.so:devel/libsysinfo
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	OpenShot
USE_LDCONFIG=	yes
CMAKE_ON=	AUTO_INSTALL_DOCS
CMAKE_OFF=	APPIMAGE_BUILD

OPTIONS_DEFINE=	DOCS JACK
JACK_DESC=	JACK audio server support (experimental)
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CMAKE_BOOL=	ENABLE_AUDIO_DOCS
DOCS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen
DOCS_CMAKE_ON=	-DCMAKE_INSTALL_DOCDIR:PATH=${DOCSDIR_REL:Q}
DOCS_PORTDOCS=	*
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_USES=	pkgconfig
JACK_CMAKE_BOOL=	ENABLE_JACK

.include <bsd.port.mk>
