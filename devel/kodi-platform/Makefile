# $FreeBSD$

PORTNAME=	kodi-platform
PORTVERSION=	20170306
CATEGORIES=	devel

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Kodi platform support library

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/lib/kodi/KodiConfig.cmake:multimedia/kodi
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libp8-platform.so:devel/p8-platform

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	36fb493

USE_LDCONFIG=	yes

.include <bsd.port.mk>
