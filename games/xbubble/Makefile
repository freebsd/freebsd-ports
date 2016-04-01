# Created by: Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	xbubble
PORTVERSION=	0.5.8
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle Bobble clone for Unix/X11 platforms

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USE_XORG=	x11 xmu
GNU_CONFIGURE=	yes
USES=		gmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_LIBS=	-lintl

.include <bsd.port.mk>
