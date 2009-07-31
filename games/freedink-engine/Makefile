# New ports collection makefile for:	syncterm
# Date created:		3 October 2006
# Whom:			shurd
#
# $FreeBSD$
#

PORTNAME=	freedink
PORTVERSION=	1.08.${PORTVER}
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	freedink
PKGNAMESUFFIX=	-engine

MAINTAINER=	shurd@sasktel.net
COMMENT=	Dink Smallwood RPG and RPG Construction Set

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \

USE_GMAKE=	yes
USE_SDL=	sdl gfx ttf image mixer
GNU_CONFIGURE=	yes
PORTVER=	20080920
CONFIGURE_ARGS=	--disable-static --disable-upx

MAN6=		freedink.6 freedinkedit.6 dink.6 dinkedit.6

OPTIONS=	EMBEDDED	"Enable Embedded Resources"	on

.include <bsd.port.pre.mk>

.ifdef WITHOUT_EMBEDDED
CONFIGURE_ARGS+=	--enable-embedded-resources
LIB_DEPENDS+=	libzip.0:${PORTSDIR}/archivers/libzip
.else
CONFIGURE_ARGS+=	--disable-embedded-resources
.endif

.include <bsd.port.post.mk>
