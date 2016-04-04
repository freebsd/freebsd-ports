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

LICENSE=	GPLv2

LIB_DEPENDS=	libpdf.so:print/pdflib

USES=		python:2

CFLAGS+=	-fPIC
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's,/usr/bin/python,python,g'  ${WRKSRC}/bg5pdf

do-build:
	${CC} ${CFLAGS} -shared ${WRKSRC}/bg5pdflib.c -I${PREFIX}/include \
		-I${PYTHON_INCLUDEDIR} -L${PREFIX}/lib -lpdf -o ${WRKSRC}/bg5pdflib.so

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bg5pdf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gbpdf ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bg5pdflib.so ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/test.big5 ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.big5.pdf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/genTest.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
