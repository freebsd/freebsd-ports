PORTNAME=	cmatrix
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Show a scrolling 'Matrix' like screen
WWW=		https://www.asty.org/cmatrix/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	abishekvashok

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/cmatrix \
		share/man/man1/cmatrix.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmatrix ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cmatrix.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
