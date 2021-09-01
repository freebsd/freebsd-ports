PORTNAME=	libopenshot-audio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	audio multimedia

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	OpenShot Audio Library

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libsysinfo.so:devel/libsysinfo

USES=		cmake compiler:c++14-lang
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	OpenShot

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen\
		CMAKE_DISABLE_FIND_PACKAGE_PythonInterp

.include <bsd.port.mk>
