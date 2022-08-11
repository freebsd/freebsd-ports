PORTNAME=	xtensa-esp32-elf
DISTVERSION=	1.22.0.g20200907
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases/binutils:source1 \
		GNU/binutils:source1 \
		https://github.com/libexpat/libexpat/releases/download/R_2_1_0/:source2 \
		SF/expat/expat/2.1.0:source2 \
		GCC/releases/gcc-${GCCVER}:source3 \
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
		gcc-${GCCVER}.tar.bz2:source3 \
		gdb-7.10.tar.xz:source4 \
		gmp-6.0.0a.tar.xz:source5 \
		isl-0.14.tar.xz:source6 \
		mpc-1.0.3.tar.gz:source7 \
		mpfr-3.1.3.tar.xz:source8 \
		ncurses-6.0.tar.gz:source9 \
		newlib-2.2.0.tar.gz:source10
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Espressif ESP32 toolchain

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	bash:shells/bash \
		gawk:lang/gawk \
		gpatch:devel/patch \
		${LOCALBASE}/bin/grep:textproc/gnugrep \
		gperf:devel/gperf \
		gsed:textproc/gsed \
		help2man:misc/help2man \
		makeinfo:print/texinfo \
		wget:ftp/wget

USES=		autoreconf:build bison gmake libtool python
USE_GCC=	10
USE_GITHUB=	yes

NO_MTREE=	yes
SUBDIR=		crosstool-NG
TAGNAME=	1.22.0-97-gc752ad5
GH_TUPLE=	espressif:${SUBDIR}:${TAGNAME}
BINARY_ALIAS=	g++=${CXX} gcc=${CC} python=${PYTHON_VERSION}
BUILD_ENV=	CT_ALLOW_BUILD_AS_ROOT_SURE=1 \
		CT_FORBID_DOWNLOAD=y \
		GREP=${LOCALBASE}/bin/grep \
		LD_RUN_PATH=${PREFIX}/lib/${CC} \
		LDFLAGS=-I/usr/local/lib \
		${MAKE_ENV:MPATH=*}

ESPVER=		crosstool-ng-$(TAGNAME)
GCCVER=		5.2.0
PLIST_SUB=	PKGBASE=$(PKGBASE) GCCVER=$(GCCVER)
TARBALLS=	${BUILD_WRKSRC}/.build/tarballs

post-extract:
	${MKDIR} ${TARBALLS}
.for F in $(DISTFILES:N$(EXTRACT_ONLY))
	${LN} -s ${DISTDIR}/${F:C/:source[0-9]+$//} ${TARBALLS}
.endfor
	${MKDIR} ${WRKSRC}/local-patches/gdb/7.10
	${CP} ${FILESDIR}/0001-gdb-7.12.1.patch ${WRKSRC}/local-patches/gdb/7.10
	echo CT_LOG_PROGRESS_BAR=n >> \
	    ${BUILD_WRKSRC}/samples/${PORTNAME}/crosstool.config

do-configure:
	cd ${BUILD_WRKSRC} && ./bootstrap
	${PRINTF} "#!/bin/sh\necho '${ESPVER}'\n" > \
	    ${BUILD_WRKSRC}/version.sh
	${CHMOD} -w+x ${BUILD_WRKSRC}/version.sh
	cd ${BUILD_WRKSRC} && \
	    ${SETENV} ${BUILD_ENV} \
	    ./configure --enable-local --prefix=${WRKDIR}/ct-ng --exec-prefix=${WRKDIR}/ct-ng
	cd ${BUILD_WRKSRC} && \
	    ${SETENV} -uMAKELEVEL -uMAKEFLAGS -u.MAKE.LEVEL.ENV ${BUILD_ENV} \
	    ${MAKE_CMD} install && ${SETENV} ${BUILD_ENV} ./ct-ng ${PORTNAME}

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${BUILD_ENV} ./ct-ng build
	cd ${BUILD_WRKSRC}/builds/${PORTNAME} && \
	    ${CHMOD} +w . lib && \
	    ${RM} build.log.bz2 lib/charset.alias && \
	    ${CHMOD} -w . lib

do-install:
	cd ${BUILD_WRKSRC}/builds/${PORTNAME} && \
	    ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/${PKGBASE}
	${FIND} ${STAGEDIR}${PREFIX}/${PKGBASE} -type f | \
	    ${XARGS} ${CHMOD} -wx
	${FIND} ${STAGEDIR}${PREFIX}/${PKGBASE}/bin \
	    ${STAGEDIR}${PREFIX}/${PKGBASE}/libexec/gcc/${PORTNAME}/${GCCVER} \
	    ${STAGEDIR}${PREFIX}/${PKGBASE}/${PORTNAME}/bin -type f | \
	    ${XARGS} ${CHMOD} +x

.include <bsd.port.mk>
