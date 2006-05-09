# $FreeBSD$

PARENTDIR?=	${.CURDIR:S|-reference$||}
REFERENCE_PORT=	${PKGORIGIN:S|-reference$||}

.include "${PARENTDIR}/Makefile"

.if !defined(DISTNAME)
DISTNAME:=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
.endif
.if !defined(DOCSDIR)
DOCSDIR:=	${PREFIX}/share/doc/${PORTNAME}
.endif
PORTNAME:=	${PORTNAME}-reference
.if defined(LATEST_LINK)
LATEST_LINK:=	${LATEST_LINK}-reference
.endif

COMMENT=	Programming reference for ${REFERENCE_PORT}

DESCR=		${WRKDIR}/pkg-descr
MD5_FILE=	${PARENTDIR}/distinfo

REFERENCE_SRC?=	${WRKSRC}/docs/reference
BOOKS?=		.

PORTDOCS=	*

.if !target(do-build)
do-build:
	@${DO_NADA}
.endif

pre-install: gnome-reference-pre-install

gnome-reference-pre-install:
	@${ECHO_CMD} "This port contains the programming reference for ${REFERENCE_PORT}." > ${DESCR}
	@${ECHO_CMD} "" >> ${DESCR}
	@${GREP} "^WWW:" ${PARENTDIR}/pkg-descr >> ${DESCR}

.if !target(do-install)
do-install:
.  if !defined(NOPORTDOCS)
.    for d in ${BOOKS}
	${MKDIR} ${DOCSDIR}/${d}
	cd ${REFERENCE_SRC}/${d}/html && \
	${FIND} * -type d ! -empty -exec ${MKDIR} "${DOCSDIR}/${d}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/${d}/{}" \;
.    endfor
.  endif
.endif

.include <bsd.port.mk>
