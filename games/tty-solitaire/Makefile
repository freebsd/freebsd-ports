PORTNAME=	tty-solitaire
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Play solitaire in your terminal
WWW=		https://github.com/mpereira/tty-solitaire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	mpereira
TEST_TARGET=	test

MAKE_ARGS=	NCURSES="${NCURSESLIBS}"

PORTDOCS=	*
PLIST_FILES=	bin/ttysolitaire

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttysolitaire ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
