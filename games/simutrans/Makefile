# $FreeBSD$

PORTNAME=	simutrans
DISTVERSION=	121-0
CATEGORIES=	games
MASTER_SITES=	SF/simutrans/simutrans/${DISTVERSION}
DISTNAME=	simutrans-src-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Transportation simulator

LICENSE=	ART10 MIT
LICENSE_COMB=	multi
LICENSE_FILE_ART10=	${WRKSRC}/simutrans/license.txt
LICENSE_FILE_MIT=	${WRKSRC}/simutrans/license_squirrel.txt

USES=		compiler:c11 gmake sdl zip
USE_SDL=	sdl2 mixer2

# Threading disabled because FreeBSD does not have a static initializer
# for recursive mutexes.
MAKE_ENV=	BACKEND=mixer_sdl2 \
		COLOUR_DEPTH=16 \
		MULTI_THREAD=0 \
		OSTYPE=freebsd \
		VERBOSE=1

NO_WRKSUBDIR=	yes

SUB_FILES=	simutrans

PLIST_FILES=	bin/simutrans libexec/simutrans
PORTDATA=	*
PORTDOCS=	change_request.txt \
		history.txt \
		problem_report.txt \
		readme.txt \
		thanks.txt

DESKTOP_ENTRIES=Simutrans "" "" simutrans "Game;Simulation;" false

OPTIONS_DEFINE=	DOCS
OPTIONS_MULTI=	PAKS
OPTIONS_MULTI_PAKS=	PAK64 PAK128 PAK128_GERMAN
OPTIONS_DEFAULT=PAK128

PAKS_DESC=			Graphics sets
PAK64_DESC=			Enable low resolution graphics set
PAK64_RUN_DEPENDS=		simutrans-pak64>=0:games/simutrans-pak64
PAK128_DESC=			Enable high resolution graphics set
PAK128_RUN_DEPENDS=		simutrans-pak128>=0:games/simutrans-pak128
PAK128_GERMAN_DESC=		Enable german graphics set
PAK128_GERMAN_RUN_DEPENDS=	simutrans-pak128.german>=0:games/simutrans-pak128.german

do-install:
	@cd ${WRKSRC}/simutrans && ${COPYTREE_SHARE} \
		"ai config font music script text themes" ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/build/default/sim \
		${STAGEDIR}${PREFIX}/libexec/simutrans
	${INSTALL_SCRIPT} ${WRKDIR}/simutrans ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/simutrans && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
