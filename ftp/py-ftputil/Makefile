# New ports collection makefile for:	py-ftputil
# Date created:		2006-12-25
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	ftputil
PORTVERSION=	2.5
CATEGORIES=	ftp python
MASTER_SITES=	# http://ftputil.sschwarzer.net/trac/attachment/wiki/Download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High-level FTP client library

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOC_FILES=	README.html README.txt ftputil.html ftputil.txt ftputil_ru_utf8.txt
.endif

.include <bsd.port.pre.mk>

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	${FETCH_CMD} -o "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" "http://ftputil.sschwarzer.net/trac/attachment/wiki/Download/${DISTNAME}${EXTRACT_SUFX}?format=raw"
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
