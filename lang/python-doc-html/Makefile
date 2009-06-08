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
MASTER_SITE_SUBDIR=	ftp/python/doc/${PORTVERSION}
DISTNAME=	${DOCFORMAT}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Documentation for the Python programming language

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_BZIP2=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist_${DOCFORMAT}

WRKSRC=		${WRKDIR}/Python-Docs-${PORTVERSION}
DOCDIR=		${PREFIX}/share/doc/${PYTHON_VERSION}

DOCFORMAT?=	html

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 260
.if ${DOCFORMAT} != "html" && ${DOCFORMAT} != "pdf-a4" && ${DOCFORMAT} != "pdf-letter" && ${DOCFORMAT} != "postscript-a4" && ${DOCFORMAT} != "postscript-letter"
IGNORE=	invalid value for DOCFORMAT: "${DOCFORMAT}", possible values are: html, pdf-a4, pdf-letter, postscript-a4, postscript-letter
.endif
.else # ${PYTHON_REL} >= 260
.if ${DOCFORMAT} != "html" && ${DOCFORMAT} != "pdf-a4" && ${DOCFORMAT} != "pdf-letter" && ${DOCFORMAT} != "text"
IGNORE=	invalid value for DOCFORMAT: "${DOCFORMAT}", possible values are: text, html, pdf-a4, pdf-letter
.endif

.if ${PYTHON_REL} < 260
DISTNAME=	python-docs-${DOCFORMAT}
.else
DISTNAME=	python-${PORTVERSION}-docs-${DOCFORMAT}
.endif
DIST_SUBDIR=	python${PYTHON_REL}

.if ${DOCFORMAT} == "html"
WRKSRC=		${WRKDIR}/${DISTNAME}
.elif ${DOCFORMAT} == "text"
WRKSRC=		${WRKDIR}/${DISTNAME}
.else
WRKSRC=		${WRKDIR}/docs-pdf
.endif # ${DOCSFORMAT} == "html"
.endif # ${PYTHON_REL} < 260

pre-install:
	@cd ${WRKSRC} && (${FIND} . -type f | \
		${SED} -e 's,^\.,share/doc/${PYTHON_VERSION},' | ${SORT} \
			> ${PLIST})
	@cd ${WRKSRC} && (${FIND} * -type d | \
		${SED} -e 's,^,@dirrm share/doc/${PYTHON_VERSION}/,' | \
			${SORT} -r) >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry share/doc/%%PYTHON_VERSION%%" >> ${PLIST}

do-install:
	@${MKDIR} ${DOCDIR}
	@${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${DOCDIR} -xf -

.include <bsd.port.post.mk>
