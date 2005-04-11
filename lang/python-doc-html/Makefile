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

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Documentation for the Python programming language

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_BZIP2=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist_${DOCFORMAT}

WRKSRC=		${WRKDIR}/Python-Docs-${PORTVERSION}
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

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 220
PLIST_SUB+=	PYTHON22_ONLY="@comment "
.else
PLIST_SUB+=	PYTHON22_ONLY=""
.endif

.if ${PYTHON_REL} < 230
do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
.endif

pre-install:
.if ${PYTHON_REL} < 230
	@${CP} ${PKGDIR}/pkg-plist_${DOCFORMAT} ${WRKDIR}
	@if [ -f ${PLIST_DIFF} ]; then \
		cd ${WRKDIR} && patch -p --quiet < ${PLIST_DIFF}; \
	fi
.else
	@cd ${WRKSRC} && (${FIND} . -type f | \
		${SED} -e 's,^\.,share/doc/${PYTHON_VERSION},' | ${SORT} \
			> ${PLIST})
	@cd ${WRKSRC} && (${FIND} * -type d | \
		${SED} -e 's,^,@dirrm share/doc/${PYTHON_VERSION}/,' | \
			${SORT} -r) >> ${PLIST}
	@${ECHO_CMD} "@unexec rmdir %D/share/doc/%%PYTHON_VERSION%% 2>/dev/null || true" >> ${PLIST}
.endif

do-install:
	@${MKDIR} ${DOCDIR}
.if ${PYTHON_REL} < 230
	@(cd ${DOCDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTFILES} ${EXTRACT_AFTER_ARGS})
.else
	@${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${DOCDIR} -xf - 
.endif

.include <bsd.port.post.mk>
