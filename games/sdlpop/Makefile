# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	sdlpop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.20
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open-source port of Prince of Persia

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../doc/gpl-3.0.txt

NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe sparc64
NOT_FOR_ARCHS_REASON=	SDLPoP-1.18.1/src/types.h:54:2: This program is not (yet) prepared for big endian CPUs, please contact the author.

USES=		cmake localbase:ldflags sdl

USE_GITHUB=	yes
GH_ACCOUNT=	NagyD
GH_PROJECT=	SDLPoP

WRKSRC_SUBDIR=	src
USE_SDL=	sdl2 image2 mixer2
PORTDOCS=	*

DESKTOP_ENTRIES=	"Prince" "Open-Source port of Prince of Persia" \
		"${DATADIR}/icon.png" "prince"  "Game;" false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/seg009.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../prince ${STAGEDIR}/${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/../data ; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} \
		${WRKSRC}/../doc/bugs.txt \
		${WRKSRC}/../doc/ChangeLog.txt \
		${WRKSRC}/../doc/mod.ini \
		${WRKSRC}/../doc/Readme.txt \
		${WRKSRC}/../SDLPoP.ini \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
