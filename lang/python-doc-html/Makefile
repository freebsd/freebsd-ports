# New ports collection makefile for:    python-doc
# Date created:         12 May 1999
# Whom:                 Thomas Gellekum <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	python-doc-${DOCFORMAT}
PORTVERSION=	${PYTHON_PORTVERSION}
CATEGORIES=	lang python
MASTER_SITES=	http://www.python.org/ftp/python/doc/${PORTVERSION}/ \
		http://SunSITE.Informatik.RWTH-Aachen.DE/python/ftp/python/doc/${PORTVERSION}/
DISTNAME=	${DOCFORMAT}-${PORTVERSION}

MAINTAINER=	alane@FreeBSD.org

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_BZIP2=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist_${DOCFORMAT}

DOCDIR=		${PREFIX}/share/doc/${PYTHON_VERSION}
PLIST_DIFF=	${FILESDIR}/plist-${DOCFORMAT}-${PORTVERSION}.diff

DOCFORMAT?=	html

.if ${DOCFORMAT} != "html" && ${DOCFORMAT} != "pdf-a4" && ${DOCFORMAT} != "pdf-letter" && ${DOCFORMAT} != "postscript-a4" && ${DOCFORMAT} != "postscript-letter"
.BEGIN:
	@${ECHO} "ERROR: invalid value for DOCFORMAT: \"${DOCFORMAT}\""
	@${ECHO} "Possible values are:  html, pdf-a4, pdf-letter,"
	@${ECHO} "postscript-a4, postscript-letter."
	@${FALSE}
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}

pre-install:
	@${CP} ${PKGDIR}/pkg-plist_${DOCFORMAT} ${WRKDIR}
	@if [ -f ${PLIST_DIFF} ]; then \
		cd ${WRKDIR} && patch -p --quiet < ${PLIST_DIFF}; \
	fi

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@(cd ${DOCDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTFILES} ${EXTRACT_AFTER_ARGS})
.endif

.include <bsd.port.mk>
