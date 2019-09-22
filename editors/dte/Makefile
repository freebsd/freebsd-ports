# $FreeBSD$

PORTNAME=	dte
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9
CATEGORIES=	editors

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Small and easy to use console text editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		iconv gmake ncurses

MAKEFILE=	${WRKSRC}/GNUmakefile
MAKE_ARGS=	V=1 prefix=${PREFIX} mandir=${PREFIX}/man

USE_GITHUB=	yes
GH_ACCOUNT=	craigbarnes

TEST_TARGET=	check

PLIST_FILES=	bin/dte \
		man/man1/dte.1.gz \
		man/man5/dte-syntax.5.gz \
		man/man5/dterc.5.gz \

PORTDOCS=	README.md keys.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dte

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/keys.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
