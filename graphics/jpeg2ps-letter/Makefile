# New ports collection makefile for:	jpeg2ps (letter)
# Date created:		30 December 2000
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
#
# $FreeBSD$
#

PORTNAME=	jpeg2ps
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.pdflib.com/products/more/jpeg2ps/
PKGNAMESUFFIX=	-${PAPERSIZE}

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.de
COMMENT=	Converter for JPEG compressed images to PostScript Level 2

PAPERSIZE?=	letter

INSTALL_TARGET=

MAN1=           jpeg2ps.1

.if ${PAPERSIZE} == a4
post-patch:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.input
	${SED} "s%CCFLAGS=-O -c%CCFLAGS=-O -c -DA4%" ${WRKSRC}/Makefile.input > ${WRKSRC}/Makefile
	${RM} -f ${WRKSRC}/Makefile.input
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jpeg2ps ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/jpeg2ps.txt ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/jpeg2ps.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.mk>
