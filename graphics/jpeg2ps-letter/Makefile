# New ports collection makefile for:	jpeg2ps (letter)
# Date created:		30 December 2000
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
#
# $FreeBSD$
#

PORTNAME=	jpeg2ps
PORTVERSION=	1.8
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.pdflib.com/jpeg2ps/
PKGNAMESUFFIX=	-${PAPERSIZE}

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.de

PAPERSIZE?=	letter

INSTALL_TARGET=

.if ${PAPERSIZE} == a4
post-patch:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.input
	${SED} "s%CCFLAGS= -O -c%CCFLAGS= -O -c -DA4%" ${WRKSRC}/Makefile.input > ${WRKSRC}/Makefile
	${RM} -f ${WRKSRC}/Makefile.input
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jpeg2ps ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jpeg2ps
	${INSTALL_DATA} ${WRKSRC}/jpeg2ps.txt ${PREFIX}/share/doc/jpeg2ps
.endif

.include <bsd.port.mk>
