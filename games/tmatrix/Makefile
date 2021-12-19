PORTNAME=	tmatrix
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4
CATEGORIES=	games

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Terminal based replica of the digital rain from The Matrix

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	M4444
GH_PROJECT=	TMatrix

PLIST_FILES=	bin/tmatrix \
		share/bash-completion/completions/tmatrix \
		share/man/man6/tmatrix.6.gz \
		share/zsh/site-functions/_tmatrix
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
