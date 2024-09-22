PORTNAME=	libshairport
PORTVERSION=	1.2.0.20310
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://mirrors.xbmc.org/build-deps/darwin-libs/
DISTNAME=	libshairport-${PORTVERSION}_lib

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	Airport Extreme Emulator
WWW=		https://github.com/amejia1/libshairport

DEPRECATED=	Abandonware, project removed upstream and hasn't seen development since 2011
EXPIRATION_DATE=2024-10-31

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf gmake libtool ssl
USE_LDCONFIG=	yes

CPPFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
