# Created by: Stephen Hurd <shurd@sasktel.net>
# $FreeBSD$

PORTNAME=	freedink
PORTVERSION=	1.08.${PORTVER}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	freedink
PKGNAMESUFFIX=	-engine

MAINTAINER=	shurd@sasktel.net
COMMENT=	Dink Smallwood RPG and RPG Construction Set

LIB_DEPENDS=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig

USES=		gettext gmake
USE_SDL=	sdl gfx ttf image mixer
GNU_CONFIGURE=	yes
PORTVER=	20121209
CONFIGURE_ARGS=	--disable-static --disable-upx

MAN6=		freedink.6 freedinkedit.6 dink.6 dinkedit.6

OPTIONS_DEFINE=	EMBEDDED
EMBEDDED_DESC=	Embedded Resources

OPTIONS_DEFAULT=	EMBEDDED

post-patch:
	@${CHMOD} 0755 ${WRKSRC}/autotools/install-reloc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMBEDDED}
CONFIGURE_ARGS+=	--enable-embedded-resources
BUILD_DEPENDS+=		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS+=		zip:${PORTSDIR}/archivers/libzip
RUN_DEPENDS+=		zip:${PORTSDIR}/archivers/zip
.else
CONFIGURE_ARGS+=	--disable-embedded-resources
.endif

.include <bsd.port.mk>
