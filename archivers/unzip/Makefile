# New ports collection makefile for:	unzip
# Date created:		17 October 1994
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	unzip
PORTVERSION=	5.52
PORTREVISION=	2
CATEGORIES?=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/ \
		${MASTER_SITE_TEX_CTAN:S,%SUBDIR%,tools/zip/info-zip/src/,}
DISTNAME=	${PORTNAME}552

MAINTAINER?=	ache@FreeBSD.org
COMMENT?=	List, test and extract compressed files in a ZIP archive

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	unix/Makefile
MAKE_ENV=	LOCAL_UNZIP="${CFLAGS} -DUSE_UNSHRINK"
MAN1=		funzip.1 unzip.1 unzipsfx.1 zipgrep.1 zipinfo.1

.if defined(WITH_UNZIP_UNREDUCE)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} unreduce_full.zip
EXTRACT_ONLY=	${PORTNAME}552.tar.gz
MAKE_ENV=	LOCAL_UNZIP="${CFLAGS} -DUSE_UNSHRINK -DUSE_SMITH_CODE"
.endif

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
	${INSTALL_MAN} ${WRKSRC}/man/${f} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/unzip
.for f in README WHERE
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/unzip
.endfor
.endif

.include <bsd.port.post.mk>
