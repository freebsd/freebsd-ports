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

USES=		python:env tar:bzip2

NO_ARCH=	yes
NO_BUILD=	yes

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_VERSION}
PLIST=		${WRKDIR}/pkg-plist.${DOCFORMAT}

DOCFORMATS=	html pdf-a4 pdf-letter text
DOCFORMAT?=	html

.if empty(DOCFORMATS:M${DOCFORMAT})
IGNORE=		invalid value for DOCFORMAT: "${DOCFORMAT}", possible values are: ${DOCFORMATS:ts,:S/,/, /g}
.endif

.if ${DOCFORMAT} != "html" && ${DOCFORMAT} != "text"
WRKSRC=		${WRKDIR}/docs-pdf
.endif

.if make(all_python_versions)
_VERS!=		${MAKE} -V _PYTHON_VERSIONS:O
.endif

all_python_versions:
.for v in ${_VERS}
	@${MAKE} -V PYTHON_PORTVERSION DEFAULT_VERSIONS=python=${v}
.endfor

.if make(makesum)
ALL_PYTHON_VERSIONS!=	${MAKE} all_python_versions
.endif

.if make(makesum)
MASTER_SITES=
.for v in ${ALL_PYTHON_VERSIONS}
MASTER_SITES+=	PYTHON/ftp/python/doc/${v}:${v:S/./x/g}
.for f in ${DOCFORMATS}
DISTFILES+=	python-${v}-docs-${f}${EXTRACT_SUFX}:${v:S/./x/g},DEFAULT
.endfor
.endfor
MASTER_SITES+=	PYTHON/ftp/python/doc/current
.endif

pre-install:
	@${FIND} ${WRKSRC} -type f | ${SED} -e 's|^${WRKSRC}|%%DOCSDIR%%|' | ${SORT} > ${PLIST}

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
