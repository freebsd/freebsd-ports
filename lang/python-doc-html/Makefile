# New ports collection makefile for:    python-doc
# Date created:         12 May 1999
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	python-doc-${DOCFORMAT}
PORTVERSION=	${PYTHON_PORTVERSION}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYTHON}
MASTER_SITE_SUBDIR=	ftp/python/doc/${PORTVERSION} \
			ftp/python/doc/current
DISTNAME=	python-${PORTVERSION}-docs-${DOCFORMAT}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Documentation for the Python programming language

PORTSCOUT=	ignore:1

NO_BUILD=	yes
USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_VERSION}
PLIST=		${WRKDIR}/pkg-plist.${DOCFORMAT}

DOCFORMAT?=	html

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 260
.  if ${DOCFORMAT} == "html" || ${DOCFORMAT} == "text"
.    if ${PYTHON_REL} == 260
WRKSRC=		${WRKDIR}/python-docs-${DOCFORMAT}
.    else
WRKSRC=		${WRKDIR}/${DISTNAME}
.    endif
.  else
WRKSRC=		${WRKDIR}/docs-pdf
.  endif
.  if ${DOCFORMAT} != "html" && ${DOCFORMAT} != "pdf-a4" && ${DOCFORMAT} != "pdf-letter" && ${DOCFORMAT} != "text"
IGNORE=		invalid value for DOCFORMAT: "${DOCFORMAT}", possible values are: text, html, pdf-a4, pdf-letter
.  endif
.else
DISTNAME=	${DOCFORMAT}-${PORTVERSION}
WRKSRC=		${WRKDIR}/Python-Docs-${PORTVERSION}
.  if ${DOCFORMAT} != "html" && ${DOCFORMAT} != "pdf-a4" && ${DOCFORMAT} != "pdf-letter" && ${DOCFORMAT} != "postscript-a4" && ${DOCFORMAT} != "postscript-letter"
IGNORE=		invalid value for DOCFORMAT: "${DOCFORMAT}", possible values are: html, pdf-a4, pdf-letter, postscript-a4, postscript-letter
.  endif
.endif

pre-install:
	@cd ${WRKSRC} && \
		(${FIND} . -type f | ${SED} -e 's|^\./|%%DOCSDIR%%/|' | ${SORT}; \
		${FIND} * -type d | ${SED} -e 's|^|@dirrm %%DOCSDIR%%/|' | ${SORT} -r; \
		${ECHO_CMD} "@dirrmtry %%DOCSDIR%%") > ${PLIST}

do-install:
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${DOCSDIR}

.include <bsd.port.post.mk>
