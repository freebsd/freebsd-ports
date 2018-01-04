# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exif
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyexif-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python library to extract EXIF metadata from JPEG and TIFF image files

USES=		python:2.7
WRKSRC=		${WRKDIR}/pyexif
DATADIR=	${PREFIX}/share/py-exif
DOCSDIR=	${PREFIX}/share/doc/py-exif

OPTIONS_DEFINE=	DOCS

post-patch:
.for pyfile in exiftool exifinfo.py
	@ cd ${WRKSRC}/bin && ${MV} ${pyfile} ${pyfile}.orig && \
	  ${SED} -e '1s|.*|#!${PYTHON_CMD}|' ${pyfile}.orig > ${pyfile}
.endfor

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f ${WRKSRC}/lib \
		-d ${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f ${WRKSRC}/lib \
		-d ${PYTHONPREFIX_SITELIBDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	cd ${WRKSRC}/lib && ${INSTALL_DATA} *.py *.pyc *.pyo \
		${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/exiftool ${STAGEDIR}${PREFIX}/bin/py-exiftool
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/share/exiftool && ${INSTALL_DATA} *.html *.txt \
		${STAGEDIR}${DATADIR}
post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
