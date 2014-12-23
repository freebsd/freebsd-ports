# Created by: Manuel Creach <manuel.creach@icloud.com>
# $FreeBSD$

PORTNAME=	libshairport
PORTVERSION=	1.2.0.20310
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://mirrors.xbmc.org/build-deps/darwin-libs/
DISTNAME=	libshairport-${PORTVERSION}_lib

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	Airport Extreme Emulator

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
