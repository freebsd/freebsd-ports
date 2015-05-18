# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python-doc-${DOCFORMAT}
PORTVERSION=	${PYTHON_PORTVERSION}
CATEGORIES=	lang python
MASTER_SITES=	PYTHON/ftp/python/doc/${PORTVERSION} \
		PYTHON/ftp/python/doc/current
DISTNAME=	python-${PORTVERSION}-docs-${DOCFORMAT}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Documentation for the Python programming language

PORTSCOUT=	ignore:1

NO_BUILD=	yes
USES=		python:build tar:bzip2

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_VERSION}
PLIST=		${WRKDIR}/pkg-plist.${DOCFORMAT}

DOCFORMAT?=	html

.include <bsd.port.pre.mk>

.  if ${DOCFORMAT} == "html" || ${DOCFORMAT} == "text"
WRKSRC=		${WRKDIR}/${DISTNAME}
.  else
WRKSRC=		${WRKDIR}/docs-pdf
.  endif
.  if ${DOCFORMAT} != "html" && ${DOCFORMAT} != "pdf-a4" && ${DOCFORMAT} != "pdf-letter" && ${DOCFORMAT} != "text"
IGNORE=		invalid value for DOCFORMAT: "${DOCFORMAT}", possible values are: text, html, pdf-a4, pdf-letter
.  endif

pre-install:
	@cd ${WRKSRC} && \
		(${FIND} . -type f | ${SED} -e 's|^\./|%%DOCSDIR%%/|' | ${SORT}) > ${PLIST}

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
