# $FreeBSD$

PARENTDIR?=	${.CURDIR:S|-reference$||}
REFERENCE_PORT=	${PKGORIGIN:S|-reference$||}

PORTSCOUT=	ignore

.include "${PARENTDIR}/Makefile"

.if defined(NOPORTDOCS)
IGNORE=		This port installs documents, but you have selected NOPORTDOCS
.endif

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
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-reference
.if defined(LATEST_LINK)
LATEST_LINK:=	${LATEST_LINK}-reference
.endif

COMMENT=	Programming reference for ${REFERENCE_PORT}

DISTINFO_FILE=	${PARENTDIR}/distinfo

REFERENCE_SRC?=	${WRKSRC}/docs/reference
BOOKS?=		.

PORTDOCS?=	*

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
.    for d in ${BOOKS}
	if [ -d ${REFERENCE_SRC}/${d}/html ]; then \
		${MKDIR} ${STAGEDIR}${DOCSDIR}/${d}; \
		cd ${REFERENCE_SRC}/${d}/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${d}; \
	fi
.    endfor
.endif

.include <bsd.port.mk>
