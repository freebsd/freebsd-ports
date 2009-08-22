# New ports collection makefile for:	unzip
# Date created:		17 October 1994
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	unzip
PORTVERSION=	5.52
PORTREVISION=	5
CATEGORIES?=	archivers
MASTER_SITES=	SF/infozip/UnZip%205.x%20and%20earlier/${PORTVERSION}
DISTNAME=	${PORTNAME}552

MAINTAINER?=	ache@FreeBSD.org
COMMENT?=	List, test and extract compressed files in a ZIP archive

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	unix/Makefile
.if defined(INSTALL_AS_INFOUNZIP)
UNZIP_NAME=	info-unzip
.else
UNZIP_NAME=	unzip
.endif
PLIST_FILES=	bin/${UNZIP_NAME} bin/funzip bin/unzipsfx bin/zipgrep bin/zipinfo
PORTDOCS=	README WHERE
MAN1=		${UNZIP_NAME}.1 funzip.1 unzipsfx.1 zipgrep.1 zipinfo.1

CFLAGS+=	-D_FILE_OFFSET_BITS=64
LOCAL_UNZIP=	${CFLAGS} -DACORN_FTYPE_NFS -DWILD_STOP_AT_DIR

.if defined(WITH_UNZIP_UNREDUCE)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} unreduce_full.zip
EXTRACT_ONLY=	${PORTNAME}552.tar.gz
LOCAL_UNZIP+=	-DUSE_SMITH_CODE
.endif

MAKE_ENV=	LOCAL_UNZIP="${LOCAL_UNZIP}"

.ifdef USE_UNZIP
.error You have `USE_UNZIP' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
ALL_TARGET=	freebsd
.else
ALL_TARGET=	bsd
.endif

.if !defined(INSTALL_AS_INFOUNZIP)
pre-fetch:
	@${ECHO} ""
	@${ECHO} "Use INSTALL_AS_INFOUNZIP=yes to install Info Unzip as ${PREFIX}/bin/info-unzip"
	@${ECHO} ""
.endif

.if defined(WITH_UNZIP_UNREDUCE)
pre-build:
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} unzip)
	@(cd ${WRKSRC}; \
		./unzip -o ${_DISTDIR}unreduce_full.zip; \
		${MV} unreduce_full.c unreduce.c)
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unzip ${PREFIX}/bin/${UNZIP_NAME}
.for file in funzip unzipsfx
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${LN} -sf ${UNZIP_NAME} ${PREFIX}/bin/zipinfo
	${INSTALL_SCRIPT} ${WRKSRC}/unix/zipgrep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/unzip.1 ${MAN1PREFIX}/man/man1/${UNZIP_NAME}.1
.for f in ${MAN1:Nunzip.1:Ninfo-unzip.1}
	${INSTALL_MAN} ${WRKSRC}/man/${f} ${MAN1PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
