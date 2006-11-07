# New ports collection makefile for:	jpeg2ps (letter)
# Date created:		30 December 2000
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
#
# $FreeBSD$
#

PORTNAME=	jpeg2ps
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.pdflib.com/fileadmin/pdflib/products/more/jpeg2ps/
PKGNAMESUFFIX=	-${PAPERSIZE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converter for JPEG compressed images to PostScript Level 2

MAKE_ARGS+=	CFLAGS="-c ${CFLAGS}" LD="${CC}"

MAN1=		jpeg2ps.1
PLIST_FILES=	bin/jpeg2ps

PAPERSIZE?=	letter

.if !defined(NOPORTDOCS)
PORTDOCS=	jpeg2ps.txt
.endif

.if ${PAPERSIZE} == a4
CFLAGS+=	-DA4
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jpeg2ps ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jpeg2ps.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/jpeg2ps.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
