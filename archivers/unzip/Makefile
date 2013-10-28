# Created by: jmz
# $FreeBSD$

PORTNAME=	unzip
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES?=	archivers
MASTER_SITES=	SF/infozip/UnZip%206.x%20%28latest%29/UnZip%20${PORTVERSION}/:main \
		SF/infozip/UnZip%205.x%20and%20earlier/5.51/:unreduce
DISTNAME=	${PORTNAME}60
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

MAINTAINER?=	ehaupt@FreeBSD.org
COMMENT?=	List, test, and extract compressed files in a ZIP archive

LICENSE=	Info-ZIP
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME=	Info-ZIP license
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS?=	unzip-iconv-[0-9]* zh-unzip-[0-9]* ko-unzip-[0-9]* ru-unzip-[0-9]*

MAKEFILE=	unix/Makefile
MAKE_ARGS=	LF2="${STRIP}"
.if defined(INSTALL_AS_INFOUNZIP)
UNZIP_NAME=	info-unzip
.else
UNZIP_NAME=	unzip
.endif
PLIST_FILES=	bin/${UNZIP_NAME} bin/funzip bin/unzipsfx bin/zipgrep bin/zipinfo
PORTDOCS=	README WHERE
MAN1=		${UNZIP_NAME}.1 funzip.1 unzipsfx.1 zipgrep.1 zipinfo.1

LOCAL_UNZIP=	${CFLAGS} -DACORN_FTYPE_NFS -DWILD_STOP_AT_DIR \
		-DUNICODE_SUPPORT -DUTF8_MAYBE_NATIVE -D_MBCS \
		-DLARGE_FILE_SUPPORT

.if defined(WITH_UNZIP_UNREDUCE)
DISTFILES+=	unreduce_full.zip:unreduce
EXTRACT_ONLY+=	${DISTNAME}${EXTRACT_SUFX}
LOCAL_UNZIP+=	-DUSE_SMITH_CODE
.endif

.if defined(WITH_ICONV)
PATCH_SITES+=		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	nork
PATCHFILES+=		unzip60-alt-iconv-utf8.patch
PATCH_DIST_STRIP+=	-p1
USES=			iconv
CFLAGS+=		-I${LOCALBASE}/include -DNATIVE
MAKE_ARGS+=		LFLAGS1="-L${LOCALBASE}/lib ${ICONV_LIB}"
.endif

MAKE_ENV=	LOCAL_UNZIP="${LOCAL_UNZIP}" \
		D_USE_BZ2=-DUSE_BZIP2 L_BZ2=-lbz2

.ifdef USE_UNZIP
.error You have `USE_UNZIP' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
ALL_TARGET=	freebsd
.else
ALL_TARGET=	bsd
.endif

.for m in ${MAN1}
PLIST_FILES+=	man/man1/${m}.gz
.endfor

.if !defined(INSTALL_AS_INFOUNZIP)
pre-fetch:
	@${ECHO} ""
	@${ECHO} "Use INSTALL_AS_INFOUNZIP=yes to install Info Unzip as ${PREFIX}/bin/info-unzip"
	@${ECHO} ""
.endif

.if defined(WITH_UNZIP_UNREDUCE)
pre-build:
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} CFLAGS="${CFLAGS}" unzip)
	@(cd ${WRKSRC}; \
		./unzip -o ${_DISTDIR}unreduce_full.zip; \
		${MV} unreduce_full.c unreduce.c)
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unzip ${STAGEDIR}${PREFIX}/bin/${UNZIP_NAME}
.for file in funzip unzipsfx
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
	${LN} -sf ${UNZIP_NAME} ${STAGEDIR}${PREFIX}/bin/zipinfo
	${INSTALL_SCRIPT} ${WRKSRC}/unix/zipgrep ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/unzip.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/${UNZIP_NAME}.1
.for f in ${MAN1:Nunzip.1:Ninfo-unzip.1}
	${INSTALL_MAN} ${WRKSRC}/man/${f} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
