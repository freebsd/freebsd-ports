PORTNAME=	neo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	games

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	cmatrix clone with 32-bit color and Unicode support

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	st3w

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/neo \
		share/man/man6/neo.6.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/neo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/neo.6 ${STAGEDIR}${MANPREFIX}/share/man/man6

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
