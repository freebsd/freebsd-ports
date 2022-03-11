PORTNAME=	kodi-platform
PORTVERSION=	20190726
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Kodi platform support library

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/share/kodi/cmake/KodiConfig.cmake:multimedia/kodi
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libp8-platform.so:devel/p8-platform

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	809c5e9

USE_LDCONFIG=	yes

.include <bsd.port.mk>
