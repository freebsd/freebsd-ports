# New ports collection makefile for:	bg5pdf
# Date created:		17 June 1998
# Whom:					Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	bg5pdf
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	chinese print
MASTER_SITES=	http://cschin.yydolphin.net/bg5pdf/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/bg5pdf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Chinese-Big5 encoded files to PDF, using PDFlib

LIB_DEPENDS=	pdf.7:${PORTSDIR}/print/pdflib

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	-fPIC

post-patch:
	${REINPLACE_CMD} -e 's,%%PYTHON_INCLUDEDIR%%,${PYTHON_INCLUDEDIR},g' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bg5pdf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gbpdf ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bg5pdflib.so ${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/test.big5 ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.big5.pdf ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/genTest.py ${EXAMPLESDIR}

.include <bsd.port.mk>
