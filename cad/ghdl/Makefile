# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghdl
PORTVERSION=	0.32
CATEGORIES=	cad
DISTFILES=	${SRCDISTFILE} ${GCCDISTFILE}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNU VHDL simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc

USES=		ada gmake iconv libtool perl5
USE_PERL5=	build
INFO=		ghdl

USE_GITHUB=	yes
GH_ACCOUNT=	hanzer
GH_PROJECT=	GHDL
GH_TAGNAME=	a88ac1c

GNU_CONFIGURE=	yes
GCCVER=		4.9.2
SRCDISTFILE=	hanzer-GHDL-${PORTVERSION}-${GH_TAGNAME}_GH0.tar.gz
GCCDISTFILE=	gcc-${GCCVER}.tar.bz2
BLD_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL:R}
BUILDDIR=	${WRKDIR}/build
GCCSRCDIR=	${WRKDIR}/gcc-${GCCVER}
CFG_SCRIPT=	${GCCSRCDIR}/configure
PKG_PREFIX=	${PREFIX}/ghdl
LINKER_COMMAND=	${LOCALBASE}/gcc-aux/bin/gcc
PLIST_SUB=	GLEX=ghdl/libexec/gcc/${BLD_TARGET}/${GCCVER} \
		GLIB=ghdl/lib/gcc/${BLD_TARGET}/${GCCVER} \
		TARGET=${BLD_TARGET}

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

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
MODERN_BINUTILS=	yes
PLIST_SUB+=	FREEBSD=""
.  if ${OSREL:R} == 8 && ${ARCH} == i386
BROKEN=		get_pc_thunk.cx errors
.  endif
.else
PLIST_SUB+=	FREEBSD="@comment "
.endif

.if ${ARCH:S/amd64/x86_64/} == x86_64
PLIST_SUB+=	X86_64=""
.else
PLIST_SUB+=	X86_64="@comment "
.endif

.if ${OPSYS} == DragonFly
IGNORE=		Not supported yet
.endif

.if defined(MODERN_BINUTILS)
# Apparently gcc 4.9 needs binutils 2.23 or greater to link Ada correctly
USE_BINUTILS=	yes
RUN_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
AS_COMMAND=	${LOCALBASE}/bin/as
EXTRA_CONFIG+=	--with-ld=${LOCALBASE}/bin/ld
.else
AS_COMMAND=	/usr/bin/as
EXTRA_CONFIG+=	--with-ld=/usr/bin/ld
.endif
EXTRA_CONFIG+=	--with-as=${AS_COMMAND}

post-patch:
	${REINPLACE_CMD} \
		-e 's|\@AS_COMMAND\@|${AS_COMMAND}|' \
		-e 's|\@LINKER_COMMAND\@|${LINKER_COMMAND}|' \
		${WRKSRC}/src/ghdldrv/ghdldrv.adb

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

check:
	(cd ${WRKSRC}/testsuite && ${SETENV} ${MAKE_ENV} \
		GHDL=${STAGEDIR}${PREFIX}/ghdl/bin/ghdl ${SH} testsuite.sh)

.include <bsd.port.post.mk>
