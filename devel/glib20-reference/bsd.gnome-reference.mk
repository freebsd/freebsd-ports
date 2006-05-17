# $FreeBSD$

PARENTDIR?=	${.CURDIR:S|-reference$||}
REFERENCE_PORT=	${PKGORIGIN:S|-reference$||}

.include "${PARENTDIR}/Makefile"

.if !defined(DOCSDIR)
DOCSDIR:=	${PREFIX}/share/doc/${PORTNAME}
.endif
.if !defined(EXAMPLESDIR)
EXAMPLESDIR:=	${PREFIX}/share/examples/${PORTNAME}
.endif
.if defined(DISTNAME)
DISTNAME:=	${DISTNAME}
.else
DISTNAME:=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
.endif
.if defined(MASTER_SITE_SUBDIR)
MASTER_SITE_SUBDIR:=	${MASTER_SITE_SUBDIR}
.endif
PORTNAME:=	${PORTNAME}-reference
.if defined(LATEST_LINK)
LATEST_LINK:=	${LATEST_LINK}-reference
.endif

COMMENT=	Programming reference for ${REFERENCE_PORT}

MD5_FILE=	${PARENTDIR}/distinfo

REFERENCE_SRC?=	${WRKSRC}/docs/reference
BOOKS?=		.

PORTDOCS=	*

.if !target(do-build)
do-build:
	@${DO_NADA}
.endif

make-descr:
	@${ECHO_CMD} "This port contains the programming reference for ${REFERENCE_PORT}." > ${DESCR}
	@www=`${GREP} "^WWW:" ${PARENTDIR}/pkg-descr` || ${TRUE}; \
	if [ -n "$$www" ]; then \
		${ECHO_CMD} "" >> ${DESCR}; \
		${ECHO_CMD} "$$www" >> ${DESCR}; \
	fi

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
