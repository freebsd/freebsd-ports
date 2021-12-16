PORTNAME=	neo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	4dd64a0.patch:-p1 # https://github.com/st3w/neo/issues/8

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	cmatrix clone with 32-bit color and Unicode support

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive

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
