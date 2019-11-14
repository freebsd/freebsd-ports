# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	adplay
PORTVERSION=	1.8
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AdLib player using adplug library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libadplug.so:audio/libadplug \
		libbinio.so:devel/libbinio

USES=		autoreconf libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	adplug
GH_PROJECT=	${PORTNAME}-unix
GH_TUPLE=	adplug:database:${DBVERSION}:database/database-${DBVERSION}

DBFILE=		adplug.db
DBVERSION=	v1.0

CONFIGURE_ARGS+=	--sharedstatedir=${DATADIR}

OPTIONS_DEFINE=	ALSA SDL

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_WITH=	alsa-prefix=${LOCALBASE}/lib
ALSA_CONFIGURE_OFF=	--disable-output-alsa
ALSA_CFLAGS+=		`pkg-config --cflags alsa`

SDL_CONFIGURE_OFF=	--disable-output-sdl
SDL_USES=		sdl
SDL_USE=		SDL=sdl,mixer

PLIST_FILES=	bin/adplay %%DATADIR%%/adplug.db man/man1/adplay.1.gz

post-patch:
	@${RM} ${WRKSRC}/src/getopt.h

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/database-${DBVERSION}/${DBFILE} \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
