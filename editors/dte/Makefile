PORTNAME=	dte
DISTVERSION=	1.11.1
CATEGORIES=	editors
MASTER_SITES=	https://craigbarnes.gitlab.io/dist/${PORTNAME}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Small and easy to use console text editor
WWW=		https://craigbarnes.gitlab.io/dte/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils gmake iconv ncurses

MAKEFILE=	${WRKSRC}/GNUmakefile
MAKE_ARGS=	mandir=${PREFIX}/share/man \
		prefix=${PREFIX} \
		V=1

TEST_TARGET=	check

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dte

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
