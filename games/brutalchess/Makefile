# Created by: Gustavo Perez Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	brutalchess
PORTVERSION=	0.5.2
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-alpha/${PORTNAME}-alpha-${PORTVERSION}
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}-src

LIB_DEPENDS=	libfreetype.so:print/freetype2

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	Nice looking OpenGL chess game

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XORG=	x11 xext xt xmu xi

GNU_CONFIGURE=	yes
USES=		dos2unix gmake libtool
USE_GL=		yes
USE_SDL=	sdl image
INSTALL_TARGET=	install-strip

pre-build:
	${CHMOD} 0755 ${WRKSRC}/install-sh

.include <bsd.port.mk>
