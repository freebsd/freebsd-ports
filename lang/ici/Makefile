# New ports collection makefile for:   ici
# Date created:        18 December 1997
# Whom:                andy
#
# $FreeBSD$
#

PORTNAME=	ici
PORTVERSION=	4.1.1
CATEGORIES=	lang
MASTER_SITES=	http://www.zeta.org.au/~atrn/ici/distfiles/

MAINTAINER=	atrn@zeta.org.au
COMMENT=	An interpretive language with C's feel and high level data types

MAKEFILE=	Makefile.bsd

MAN1=		ici.1 icifuncs.1 icioo.1 iciops.1 icire.1\
		icistmt.1 icitypes.1

MANCOMPRESSED=	yes

ALL_TARGET=	all ici.h

ICIHDRS=	ici.h icistr-setup.h

ICIDOCS=	doc/ici.pdf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ici ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libici4.a ${PREFIX}/lib
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${f}.gz ${PREFIX}/man/man1
.endfor
	${MKDIR} ${PREFIX}/lib/ici4
	${INSTALL_DATA} ${WRKSRC}/ici4core.ici ${PREFIX}/lib/ici4
	${INSTALL_DATA} ${WRKSRC}/ici4core1.ici ${PREFIX}/lib/ici4
	${INSTALL_DATA} ${WRKSRC}/ici4core2.ici ${PREFIX}/lib/ici4
	${INSTALL_DATA} ${WRKSRC}/ici4core3.ici ${PREFIX}/lib/ici4
	${MKDIR} ${PREFIX}/include
.for f in ${ICIHDRS}
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/include
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ici4
.for f in ${ICIDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${PREFIX}/share/doc/ici4
.endfor
.endif

.include <bsd.port.mk>
