# Created by: SASAKI Shunsuke <ele@pop17.odn.ne.jp>
# $FreeBSD$

PORTNAME=	ne
PORTVERSION=	3.05
CATEGORIES=	japanese editors
MASTER_SITES=	http://hp.vector.co.jp/authors/VA018758/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VZ like full-screen text editor with Japanese support

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-error=return-type

BROKEN_powerpc=	Does not compile on powerpc

OPTIONS_DEFINE=	DOCS

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} ne \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/src && ${INSTALL_MAN} ne_en.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/ne.1)
	(cd ${WRKSRC}/src && ${INSTALL_MAN} ne.1 \
		${STAGEDIR}${MANPREFIX}/man/ja/man1/ne.1)
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in key* nerc* term*
	(cd ${WRKSRC}/etc && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${ETCDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in BUGS.jp CHANGES.jp HISTORY.jp INSTALL.jp README.jp TODO.jp
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
