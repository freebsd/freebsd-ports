# New ports collection makefile for:    python-doc
# Version required:     1.5.2
# Date created:         12 May 1999
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	${DOCFORMAT}-${VERSION}
PKGNAME=        python-doc-${DOCFORMAT}-${VERSION}
CATEGORIES=	lang python
MASTER_SITES=	ftp://www.python.org/pub/python/doc/1.5.2/ \
		ftp://ftp.cwi.nl/pub/python/doc/1.5.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.org

DIST_SUBDIR=	python
NO_BUILD=	yes
PLIST=		${PKGDIR}/PLIST_${DOCFORMAT}

VERSION=	1.5.2
DOCDIR=		${PREFIX}/share/doc/python

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

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@(cd ${DOCDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTFILES} ${EXTRACT_AFTER_ARGS})
.endif

.include <bsd.port.mk>
