# Created by: Craig Leres <leres@freebsd.org>
# $FreeBSD$

PORTNAME=	xtensa-esp32-elf
DISTVERSION=	1.22.0.g20171219
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases/binutils:source1 \
		GNU/binutils:source1 \
		https://github.com/libexpat/libexpat/releases/download/R_${PORTVERSION:S|.|_|g}/:source2 \
		SF/expat:source2 \
		GCC/releases/gcc-5.2.0:source3 \
		GNU/gdb:source4 \
		GNU/gmp:source5 \
		http://isl.gforge.inria.fr/:source6 \
		GNU/mpc:source7 \
		http://www.mpfr.org/mpfr-3.1.3/:source8 \
		GNU/mpfr:source8 \
		ftp://ftp.invisible-island.net/ncurses/:source9 \
		GNU/ncurses:source9 \
		SOURCEWARE/newlib:source10 \
		ftp://sources.redhat.com/pub/newlib/:source10
DISTFILES=	binutils-2.25.1.tar.bz2:source1 \
		expat-2.1.0.tar.gz:source2 \
		gcc-5.2.0.tar.bz2:source3 \
		gdb-7.10.tar.xz:source4 \
		gmp-6.0.0a.tar.xz:source5 \
		isl-0.14.tar.xz:source6 \
		mpc-1.0.3.tar.gz:source7 \
		mpfr-3.1.3.tar.xz:source8 \
		ncurses-6.0.tar.gz:source9 \
		newlib-2.2.0.tar.gz:source10
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	leres@freebsd.org
COMMENT=	Espressif ESP32 toolchain

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	bash:shells/bash \
		gawk:lang/gawk \
		git:devel/git \
		gpatch:devel/patch \
		${LOCALBASE}/bin/grep:textproc/gnugrep \
		gperf:devel/gperf \
		gsed:textproc/gsed \
		help2man:misc/help2man \
		makeinfo:print/texinfo \
		wget:ftp/wget

NO_MTREE=	yes
USES=		autoreconf:build bison gmake libtool python
USE_GCC=	yes
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/${PORTNAME}/libexec/gcc/${PORTNAME}/5.2.0
SUBDIR=		crosstool-NG
TAGNAME=	1.22.0-80-g6c4433a5
GH_TUPLE=	espressif:${SUBDIR}:${TAGNAME}
BINARY_ALIAS=	g++=${CXX} gcc=${CC} python=${PYTHON_VERSION}
BUILD_ENV=	CT_ALLOW_BUILD_AS_ROOT_SURE=1 \
		${MAKE_ENV:MPATH=*}

post-extract:
	${MKDIR} ${BUILD_WRKSRC}/.build/tarballs
.for F in $(DISTFILES:N$(EXTRACT_ONLY))
	${LN} -s ${DISTDIR}/${F:C/:source[0-9]+$//} \
	    ${BUILD_WRKSRC}/.build/tarballs
.endfor

pre-configure:
	cd ${BUILD_WRKSRC} && ./bootstrap
	${PRINTF} "#!/bin/sh\necho '${SUBDIR:tl}-${TAGNAME}'\n" > \
	    ${BUILD_WRKSRC}/version.sh
	${CHMOD} -w+x ${BUILD_WRKSRC}/version.sh

do-configure:
	cd ${BUILD_WRKSRC} && \
	    ./configure --enable-local --with-grep=${LOCALBASE}/bin/grep

pre-build:
	cd ${BUILD_WRKSRC} && \
	    ${SETENV} -uMAKELEVEL -uMAKEFLAGS -u.MAKE.LEVEL.ENV \
	    ${MAKE_CMD} install && ${SETENV} ${BUILD_ENV} ./ct-ng ${PORTNAME}

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${BUILD_ENV} ./ct-ng build

post-build:
	cd ${BUILD_WRKSRC}/builds/${PORTNAME} && \
	    ${RM} build.log.bz2 lib/charset.alias

do-install:
	cd ${BUILD_WRKSRC}/builds && \
	    ${COPYTREE_BIN} ${PORTNAME} ${STAGEDIR}${PREFIX}
	${FIND} ${STAGEDIR}${PREFIX}/${PORTNAME} -type f | \
	    ${XARGS} ${CHMOD} -wx
	${FIND} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin \
	    ${STAGEDIR}${PREFIX}/${PORTNAME}/libexec/gcc/${PORTNAME}/5.2.0 \
	    ${STAGEDIR}${PREFIX}/${PORTNAME}/${PORTNAME}/bin -type f | \
	    ${XARGS} ${CHMOD} +x

.include <bsd.port.mk>
