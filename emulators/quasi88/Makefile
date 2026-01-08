PORTNAME=	quasi88
DISTVERSION=	0.7.3
CATEGORIES=	emulators
MASTER_SITES=	http://www.eonet.ne.jp/~showtime/quasi88/release/

MAINTAINER=	mclay@astate.edu
COMMENT=	PC-8801 emulator for X
WWW=		https://www.eonet.ne.jp/~showtime/quasi88/

LICENSE=	BSD3CLAUSE

USES=		gmake sdl xorg zip
USE_SDL=	sdl2
USE_XORG=	x11 xext

DESKTOP_ENTRIES="Quasi88" "" "" "quasi88" "" ""

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quasi88 ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.rc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
