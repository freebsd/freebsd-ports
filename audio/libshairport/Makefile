# Created by: Manuel Creach <manuel.creach@icloud.com>
# $FreeBSD$

PORTNAME=	libshairport
PORTVERSION=	1.2.0.20310
CATEGORIES=	audio
MASTER_SITES=	http://mirrors.xbmc.org/build-deps/darwin-libs/
DISTNAME=	libshairport-${PORTVERSION}_lib

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	An Airport Extreme Emulator

FETCH_ARGS=	-pRr
USES=		gmake
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes

CPPFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
