# New ports collection makefile for:	bg5pdf
# Date created:		17 June 1998
# Whom:					Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	bg5pdf
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	chinese print
MASTER_SITES=	http://students.washington.edu/cschin/bg5ps/bg5pdf/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/bg5pdf/

MAINTAINER=	statue@freebsd.sinica.edu.tw

LIB_DEPENDS=    pdf.4:${PORTSDIR}/print/pdflib

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bg5pdf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gbpdf ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bg5pdflib.so ${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/test.big5 ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.big5.pdf ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/genTest.py ${EXAMPLESDIR}

.include <bsd.port.mk>
