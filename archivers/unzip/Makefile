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
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	infozip
DISTNAME=	${PORTNAME}552

MAINTAINER?=	ache@FreeBSD.org
COMMENT?=	List, test and extract compressed files in a ZIP archive

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	unix/Makefile
PLIST_FILES=	bin/unzip bin/funzip bin/unzipsfx bin/zipgrep bin/zipinfo
PORTDOCS=	README WHERE
MAN1=		funzip.1 unzip.1 unzipsfx.1 zipgrep.1 zipinfo.1

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

.if defined(WITH_UNZIP_UNREDUCE)
pre-build:
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} unzip)
	@(cd ${WRKSRC}; \
		./unzip -o ${_DISTDIR}unreduce_full.zip; \
		${MV} unreduce_full.c unreduce.c)
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean)
.endif

do-install:
.for file in funzip unzip unzipsfx
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${LN} -sf unzip ${PREFIX}/bin/zipinfo
	${INSTALL_SCRIPT} ${WRKSRC}/unix/zipgrep ${PREFIX}/bin
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${f} ${MAN1PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
