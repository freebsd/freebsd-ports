PORTNAME=	mirrormagic
DISTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://www.artsoft.org/RELEASES/linux/mirrormagic/
DISTNAME=	${PORTNAME}-${DISTVERSION}-linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade style game with stereo sound for X Window System
WWW=		https://www.artsoft.org/mirrormagic/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake perl5 sdl
USE_SDL=	sdl2 mixer2 image2 net2
USE_PERL5=	build
BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ARGS=	TARGET=sdl2 \
		BASE_PATH="${DATADIR}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="Mirror Magic" \
		"" \
		"${DATADIR}/graphics/gfx_mirrormagic/icons/icon.png" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} -r ${WRKSRC}/lib ${WRKSRC}/mirrormagic # linux binaries

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rocksndiamonds ${STAGEDIR}${PREFIX}/bin/mirrormagic
	cd ${WRKSRC} && ${COPYTREE_SHARE} "conf docs graphics levels music sounds" ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
