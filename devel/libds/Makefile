# Created by: Peter Bozarov (kingofgib@users.sourceforge.net)
# $FreeBSD$

PORTNAME=	libds
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-2.1
DISTNAME=	libds-2.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ANSI Generic Data Structures Library

LICENSE=	BSD4CLAUSE

USE_LDCONFIG=	yes
ALL_TARGET=	gcc

HTML=		avltree.html heap.html parray.html set.html \
		hashtbl.html index.html queue.html stack.html

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/ds.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libds.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libds.so ${STAGEDIR}${PREFIX}/lib/libds.so.1
	${LN} -sf libds.so.1 ${STAGEDIR}${PREFIX}/lib/libds.so
	${INSTALL_MAN} ${WRKSRC}/libds.3 ${STAGEDIR}${MANPREFIX}/man/man3

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${HTML}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
