# Created by: andy
# $FreeBSD$

PORTNAME=	ici
PORTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://atrn.org/ici/distfiles

MAINTAINER=	atrn@zeta.org.au
COMMENT=	An interpretive language with C's feel and high level data types

MAKEFILE=	Makefile.bsd

ALL_TARGET=	all ici.h
ICIHDRS=	ici.h icistr-setup.h
ICIDOCS=	doc/ici.pdf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ici ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libici4.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/*.gz ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/ici4
	${INSTALL_DATA} ${WRKSRC}/ici4core.ici ${STAGEDIR}${PREFIX}/lib/ici4
	${INSTALL_DATA} ${WRKSRC}/ici4core1.ici ${STAGEDIR}${PREFIX}/lib/ici4
	${INSTALL_DATA} ${WRKSRC}/ici4core2.ici ${STAGEDIR}${PREFIX}/lib/ici4
	${INSTALL_DATA} ${WRKSRC}/ici4core3.ici ${STAGEDIR}${PREFIX}/lib/ici4
	${MKDIR} ${STAGEDIR}${PREFIX}/include
.for f in ${ICIHDRS}
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${PREFIX}/include
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ici4
.for f in ${ICIDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${STAGEDIR}${PREFIX}/share/doc/ici4
.endfor
.endif

.include <bsd.port.mk>
