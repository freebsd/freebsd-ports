PORTNAME=	kodi-platform
DISTVERSION=	20190726
PORTREVISION=	12
CATEGORIES=	devel

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Kodi platform support library
WWW=		https://github.com/xbmc/kodi-platform

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/lib/kodi/cmake/KodiConfig.cmake:multimedia/kodi
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libp8-platform.so:devel/p8-platform

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	809c5e9

USE_LDCONFIG=	yes

.include <bsd.port.mk>
