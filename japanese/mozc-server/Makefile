# New ports collection makefile for:	mozc-server
# Date created:				26 June 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mozc-server
PORTVERSION=	1.3.911.102
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://mozc.googlecode.com/files/
DISTNAME=	mozc-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	Mozc server for IBus, SCIM and others

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/grep:${PORTSDIR}/textproc/gnugrep \
		gyp:${PORTSDIR}/devel/py-gyp-devel
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gtest.0:${PORTSDIR}/devel/googletest \
		protobuf.7:${PORTSDIR}/devel/protobuf \
		zinnia.0:${PORTSDIR}/japanese/zinnia 
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_GMAKE=	yes
eSE_ICONV=	yes
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
BROKEN=		Does not compile on FreeBSD 7.X
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile: segfault
.endif

# workaround for a gcc4.2.1's namespace bug
.if (${OSVERSION} < 1000000 && ${OSVERSION} > 9000000) || ${OSVERSION} < 802503
BUILD_DEPENDS+= gcc42:${PORTSDIR}/lang/gcc42
CC=		gcc42
CXX=		g++42
.endif

.if defined(WITH_DEBUG_CODE)
BUILD_MODE=	Debug
.else
BUILD_MODE=	Release
.endif

LOCALBASE_REPLACE_FILES= \
		${WRKSRC}/build_mozc.py \
		${WRKSRC}/gyp/common.gypi \
		${WRKSRC}/base/util.cc \
		${WRKSRC}/base/process.cc \
		${WRKSRC}/handwriting/zinnia_handwriting.cc

post-patch:
	@for FILE in ${LOCALBASE_REPLACE_FILES}; \
	do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    $${FILE}; \
	done;

do-build:
	@cd ${WRKSRC}/; \
		export BUILD_COMMAND=${GMAKE}; \
		export CC=${CC}; export CFLAGS="${CFLAGS}"; \
		export CXX=${CXX}; export CXXFLAGS="${CXXFLAGS}"; \
		export LDFLAGS="-L${LOCALBASE}/lib" ; \
		${PYTHON_CMD} build_mozc.py gyp --gypdir=${LOCALBASE}/bin; \
		${PYTHON_CMD} build_mozc.py build_tools \
			-c ${BUILD_MODE}; \
		${PYTHON_CMD} build_mozc.py build \
			-c ${BUILD_MODE}\
			server/server.gyp:mozc_server

do-install:
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_server \
		${LOCALBASE}/bin/mozc_server

.include <bsd.port.post.mk>
