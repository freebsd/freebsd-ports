# Created by: SASAKI Shunsuke <ele@pop17.odn.ne.jp>
# $FreeBSD$

PORTNAME=	ne
PORTVERSION=	3.05
CATEGORIES=	japanese editors
MASTER_SITES=	http://hp.vector.co.jp/authors/VA018758/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VZ-like full-screen text editor with Japanese support

LICENSE=	GPLv2

USES=		ncurses
GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-error=return-type		# required for Clang
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ne ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/ne_en.1 ${STAGEDIR}${PREFIX}/man/man1/ne.1
	${INSTALL_MAN} ${WRKSRC}/src/ne.1 ${STAGEDIR}${PREFIX}/man/ja/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in key* nerc* term*
	${INSTALL_DATA} ${WRKSRC}/etc/${i} ${STAGEDIR}${ETCDIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in BUGS.jp CHANGES.jp HISTORY.jp INSTALL.jp README.jp TODO.jp
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
