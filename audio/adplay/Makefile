# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	adplay
PORTVERSION=	1.8.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AdLib player using adplug library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libadplug.so:audio/libadplug \
		libbinio.so:devel/libbinio

USES=		autoreconf compiler:c++11-lang libtool pkgconfig
USE_GITHUB=	yes

GH_ACCOUNT=	adplug
GH_PROJECT=	${PORTNAME}-unix
GH_TUPLE=	adplug:database:${DBVERSION}:database/database-${DBVERSION}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sharedstatedir=${DATADIR}

PLIST_FILES=	${DATADIR}/adplug.db \
		bin/adplay \
		man/man1/adplay.1.gz

OPTIONS_DEFINE=	ALSA SDL

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=	--disable-output-alsa
ALSA_CONFIGURE_WITH=	alsa-prefix=${LOCALBASE}/lib
ALSA_CFLAGS+=		`pkg-config --cflags alsa`

SDL_USES=		sdl
SDL_USE=		SDL=mixer,sdl
SDL_CONFIGURE_OFF=	--disable-output-sdl

DBFILE=		adplug.db
DBVERSION=	v1.0

post-patch:
	@${RM} ${WRKSRC}/src/getopt.h

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/database-${DBVERSION}/${DBFILE} \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
