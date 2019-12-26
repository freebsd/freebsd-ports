# Created by: Shen Chuan-Hsing
# $FreeBSD$

PORTNAME=	bg5pdf
PORTVERSION=	1.0.0
PORTREVISION=	8
CATEGORIES=	chinese print
MASTER_SITES=	LOCAL/chinsan

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Chinese-Big5 encoded files to PDF, using PDFlib

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2

LIB_DEPENDS=	libpdf.so:print/pdflib

USES=		python:2.7 shebangfix
SHEBANG_FILES=	bg5pdf gbpdf
python_OLD_CMD=	"/usr/bin/env /usr/bin/python"

CFLAGS+=	-fPIC
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

post-extract:
	@${CP} ${FILESDIR}/gbpdf ${WRKSRC}

do-build:
	${CC} ${CFLAGS} -shared ${WRKSRC}/bg5pdflib.c -I${PREFIX}/include \
		-I${PYTHON_INCLUDEDIR} -L${PREFIX}/lib -lpdf -o ${WRKSRC}/bg5pdflib.so

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_LIB} ${WRKSRC}/bg5pdflib.so ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bg5pdf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gbpdf ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.big5 ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.big5.pdf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/genTest.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
