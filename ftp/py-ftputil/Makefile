# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	ftputil
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	ftp python
MASTER_SITES=	# http://ftputil.sschwarzer.net/trac/attachment/wiki/Download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High-level FTP client library

USES=		python:2.7
USE_PYTHON=	distutils

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOC_FILES=	README.html README.txt ftputil.html ftputil.txt ftputil_ru_utf8.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	${FETCH_CMD} -o "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" "http://ftputil.sschwarzer.net/trac/attachment/wiki/Download/${DISTNAME}${EXTRACT_SUFX}?format=raw"
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
