PORTNAME=	bass
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/scummvm/extras/Beneath%20a%20Steel%20Sky/ \
		https://downloads.scummvm.org/frs/extras/Beneath%20a%20Steel%20Sky/
DISTNAME=	bass-cd-1.2

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Beneath a Steel Sky: a post-apocalyptic futuristic graphical adventure
WWW=		https://www.scummvm.org/games/ #games-sky

LICENSE=	BASS
LICENSE_NAME=	Beneath a Steel Sky License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	scummvm:games/scummvm

USES=		desktop-file-utils zip

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	bass.desktop

OPTIONS_DEFINE=	DOCS

post-extract:
	@${TAIL} -n +86 ${WRKSRC}/readme.txt | ${SED} -e '1G;9G' | ${FMT} -p > ${WRKSRC}/LICENSE

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sky.dnr ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sky.dsk ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sky.cpt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/bass.desktop ${STAGEDIR}${PREFIX}/share/applications

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
