# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghdl
PORTVERSION=	0.33
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	cad
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU VHDL simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc

USES=		ada gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tgingold

BROKEN_aarch64=		fails to configure: Configuration aarch64-portbld-freebsd11 not supported

GNU_CONFIGURE=	yes
GCCVER=		4.9.2
LLVMVER=	35
BLD_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL:R}
BUILDDIR=	${WRKDIR}/build
GCCSRCDIR=	${WRKDIR}/gcc-${GCCVER}
CFG_SCRIPT=	${GCCSRCDIR}/configure
PKG_PREFIX=	${PREFIX}/ghdl
LINKER_COMMAND=	${LOCALBASE}/${ADAXX}-aux/bin/gcc

GHDL_ARGS=	--enable-languages="c,vhdl" \
		--build=${BLD_TARGET} \
		--prefix=${PKG_PREFIX:Q} \
		--disable-bootstrap \
		--disable-nls \
		--disable-libquadmath \
		--disable-libmudflap \
		--disable-libgomp \
		--disable-libssp \
		--with-system-zlib \
		--with-gmp=${PREFIX} \
		--with-mpfr=${PREFIX} \
		--with-mpc=${PREFIX} \
		--enable-shared \
		--enable-threads=posix \
		${ICONV_CONFIGURE_ARG} ${EXTRA_CONFIG}

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	GCC LLVM

GCC_DESC=		Code generator is GCC  (mature)
LLVM_DESC=		Code generator is LLVM (experimental)
LLVM_USES=		libedit ncurses

.if exists (/sbin/hammer)
OPTIONS_DEFAULT=	LLVM
PLIST_SUB=		DRAGONFLY="" FREEBSD="@comment "
.else
OPTIONS_DEFAULT=	GCC
PLIST_SUB=		DRAGONFLY="@comment " FREEBSD=""
.endif

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
MODERN_BINUTILS=	yes
.endif

.if ${ARCH:S/amd64/x86_64/} == x86_64
PLIST_SUB+=	X86_64=""
.else
PLIST_SUB+=	X86_64="@comment "
.endif

.if defined(MODERN_BINUTILS)
# Apparently gcc 4.9 needs binutils 2.23 or greater to link Ada correctly
USE_BINUTILS=	yes
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
AS_COMMAND=	${LOCALBASE}/bin/as
EXTRA_CONFIG+=	--with-ld=${LOCALBASE}/bin/ld
.else
AS_COMMAND=	/usr/bin/as
EXTRA_CONFIG+=	--with-ld=/usr/bin/ld
.endif
EXTRA_CONFIG+=	--with-as=${AS_COMMAND}

.if ${PORT_OPTIONS:MGCC}
DISTFILES+=	gcc-${GCCVER}.tar.bz2
USES+=		iconv libtool makeinfo perl5
USE_PERL5=	build
INFO=		ghdl
PLIST_SUB+=	GLEX=ghdl/libexec/gcc/${BLD_TARGET}/${GCCVER} \
		GLIB=ghdl/lib/gcc/${BLD_TARGET}/${GCCVER} \
		TARGET=${BLD_TARGET}
.  if ${OPSYS} == DragonFly
IGNORE=		not supported by GCC backend
.  endif
.endif

.if ${PORT_OPTIONS:MLLVM}
BUILD_DEPENDS+=	llvm-config${LLVMVER}:devel/llvm${LLVMVER} \
		clang++${LLVMVER}:lang/clang${LLVMVER}
RUN_DEPENDS+=	llc${LLVMVER}:devel/llvm${LLVMVER}
PLIST=		${.CURDIR}/llvm-plist
PLIST_SUB+=	GLIB=ghdl/lib/ghdl/
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\@AS_COMMAND\@|${AS_COMMAND}|' \
		-e 's|\@LINKER_COMMAND\@|${LINKER_COMMAND}|' \
		${WRKSRC}/src/ghdldrv/ghdldrv.adb
	@${REINPLACE_CMD} \
		-e 's|llvm-config|llvm-config${LLVMVER}|' \
		-e 's|(INSTALL_PROGRAM)|(BSD_INSTALL_PROGRAM)|' \
		-e 's|(INSTALL_DATA)|(BSD_INSTALL_DATA)|' \
		${WRKSRC}/configure ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|clang++|clang++${LLVMVER}|' \
		-e 's|\((LDFLAGS)\)|\1 -L${LOCALBASE}/lib|' \
		${WRKSRC}/src/ortho/llvm/Makefile

.if ${PORT_OPTIONS:MGCC}
do-configure:
	${MKDIR} ${BUILDDIR}
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--with-gcc=${GCCSRCDIR} --prefix=${PKG_PREFIX:Q})
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} copy-sources
	(cd ${BUILDDIR} && ${SETENV} ${CONFIGURE_ENV} \
		${CFG_SCRIPT} ${GHDL_ARGS})

do-build:
	(cd ${BUILDDIR} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} -j${MAKE_JOBS_NUMBER} ${MAKE_ARGS} all)

do-install:
	(cd ${BUILDDIR} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} install-strip ${MAKE_ARGS})
	${MV} ${STAGEDIR}${PREFIX}/ghdl/share/man/man1/ghdl.1 \
		${STAGEDIR}${PREFIX}/man/man1
	${MV} ${STAGEDIR}${PREFIX}/ghdl/share/info/ghdl.info \
		${STAGEDIR}${PREFIX}/info
	${RM} -r ${STAGEDIR}${PREFIX}/ghdl/share

.endif	# TAIL: GCC

.if ${PORT_OPTIONS:MLLVM}
do-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--with-llvm=${LOCALBASE} --prefix=${PKG_PREFIX:Q})
.endif	# TAIL: LLVM

check:
	(cd ${WRKSRC}/testsuite && ${SETENV} ${MAKE_ENV} \
		GHDL=${STAGEDIR}${PREFIX}/ghdl/bin/ghdl ${SH} testsuite.sh)

.include <bsd.port.mk>
