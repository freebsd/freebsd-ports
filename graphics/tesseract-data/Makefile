PORTNAME=	tesseract-data
PORTVERSION=	4.1.0
CATEGORIES=	graphics

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Trained language data for the Tesseract OCR engine

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	tesseract-ocr
GH_PROJECT=	tessdata

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/tessdata
PORTDATA=	*

BROKEN_sparc64=		Fails to install: runaway process

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for l in ${PORTDATA}
	@${CP} ${WRKSRC}/*.traineddata ${STAGEDIR}${DATADIR}/
.endfor
	@cd ${STAGEDIR}${DATADIR} ; ${CHMOD} ${BINMODE} ${PORTDATA}

.include <bsd.port.mk>
