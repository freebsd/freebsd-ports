# New ports collection makefile for:	pdf2djvu
# Date created:			7 Mar 2008
# Whom:					Denise H. G. <darcsis@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pdf2djvu
PORTVERSION=	0.4.5.1
CATEGORIES=	converters
MASTER_SITES=	http://pdf2djvu.googlecode.com/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}a${EXTRACT_SUFFIX}

MAINTAINER=	darcsis@gmail.com
COMMENT=	Pdf2djvu creates DjVu files from PDF files

BUILD_DEPENDS=	${LOCALBASE}/include/pstreams/pstream.h:${PORTSDIR}/devel/pstreams
LIB_DEPENDS=	poppler.2:${PORTSDIR}/graphics/poppler

USE_GMAKE=	yes
PLIST_FILES=	bin/pdf2djvu

.if exists(${LOCALBASE}/bin/djview)
DJVU_DIR?=	# empty
.else
DJVU_DIR?=	-nox11
.endif

LIB_DEPENDS+=	djvulibre.20:${PORTSDIR}/graphics/djvulibre${DJVU_DIR}

MAN1=	pdf2djvu.1
MANCOMPRESSED=	no

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
