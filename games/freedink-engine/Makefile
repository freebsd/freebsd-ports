# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freedink
PORTVERSION=	1.08.${PORTVER}
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	freedink
PKGNAMESUFFIX=	-engine

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Dink Smallwood RPG and RPG Construction Set

LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USES=		gettext gmake pkgconfig
USE_SDL=	sdl gfx ttf image mixer
GNU_CONFIGURE=	yes
PORTVER=	20121209
CONFIGURE_ARGS=	--disable-static --disable-upx

OPTIONS_DEFINE=	EMBEDDED
OPTIONS_DEFAULT=EMBEDDED

EMBEDDED_DESC=			Embedded Resources
EMBEDDED_CONFIGURE_ENABLE=	embedded-resources
EMBEDDED_BUILD_DEPENDS=		zip:${PORTSDIR}/archivers/zip
EMBEDDED_LIB_DEPENDS=		libzip.so:${PORTSDIR}/archivers/libzip
EMBEDDED_RUN_DEPENDS=		zip:${PORTSDIR}/archivers/zip

post-patch:
	@${CHMOD} 0755 ${WRKSRC}/autotools/install-reloc

.include <bsd.port.mk>
