# Created by: Shen Chuan-Hsing
# $FreeBSD$

PORTNAME=	bg5pdf
PORTVERSION=	1.0.0
PORTREVISION=	6
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/bg5pdf/ \
		LOCAL/chinsan

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Chinese-Big5 encoded files to PDF, using PDFlib

LIB_DEPENDS=	pdf.6:${PORTSDIR}/print/pdflib

CFLAGS+=	-fPIC
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,/usr/bin/python,python,g'  ${WRKSRC}/bg5pdf

do-build:
	${CC} ${CFLAGS} -shared ${WRKSRC}/bg5pdflib.c -I${PREFIX}/include \
		-I${PYTHON_INCLUDEDIR} -L${PREFIX}/lib -lpdf -o ${WRKSRC}/bg5pdflib.so

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bg5pdf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gbpdf ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bg5pdflib.so ${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/test.big5 ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.big5.pdf ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/genTest.py ${EXAMPLESDIR}

.include <bsd.port.mk>
