PORTNAME=	sdlpop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.23
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open-source port of Prince of Persia
WWW=		https://github.com/NagyD/SDLPoP

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	SDLPoP-1.18.1/src/types.h:54:2: This program is not (yet) prepared for big endian CPUs, please contact the author.

USES=		cmake localbase:ldflags sdl

USE_GITHUB=	yes
GH_ACCOUNT=	NagyD
GH_PROJECT=	SDLPoP

WRKSRC_SUBDIR=	src
USE_SDL=	image2 sdl2
PORTDOCS=	*

CFLAGS+=	-I${LOCALBASE}/include/SDL2

DESKTOP_ENTRIES=	"Prince" "Open-Source port of Prince of Persia" \
		"${DATADIR}/icon.png" "prince"  "Game;" false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/lighting.c
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/seg009.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../prince ${STAGEDIR}/${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/../data ; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} \
		${WRKSRC}/../doc/ChangeLog.txt \
		${WRKSRC}/../doc/mod.ini \
		${WRKSRC}/../doc/Readme.txt \
		${WRKSRC}/../SDLPoP.ini \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
