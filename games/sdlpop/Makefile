# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	sdlpop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18.1
CATEGORIES=	games

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Open-source port of Prince of Persia

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../doc/gpl-3.0.txt

USES=		cmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	NagyD
GH_PROJECT=	SDLPoP

WRKSRC_SUBDIR=	src
USE_SDL=	sdl2 image2 mixer2
PORTDOCS=	*

DESKTOP_ENTRIES=	"Prince" "Open-Source port of Prince of Persia" \
		"${DATADIR}/icon.png" "prince"  "Game;" false

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
