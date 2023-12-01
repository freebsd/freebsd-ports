# This port is based on the devel/gdb port and cheribuild [1].
#
# At the moment, it provides the minimal set of features to build an aarch64 package.
#
# [1] https://github.com/CTSRD-CHERI/cheribuild

PORTNAME=	gdb-cheri
PORTVERSION=	${GDB_RELEASE}
PORTREVISION=	0
CATEGORIES=	devel

USE_GITHUB=yes
GH_ACCOUNT=	CTSRD-CHERI
GH_PROJECT=	gdb
GH_TAGNAME=	${GDB_COMMIT}

MAINTAINER=	konrad.witaszczyk@cl.cam.ac.uk
COMMENT=	GNU Project Debugger with support for the Arm Morello architecture

NOT_FOR_ABIS=	purecap
NOT_FOR_ABIS_REASON_purecap=is not adapted for CheriABI yet

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING3
DATADIR=	${PREFIX}/share/gdb

USES=		compiler:c++11-lang gmake libtool makeinfo pkgconfig tar:xz

LIB_DEPENDS=	libgmp.so:math/gmp

VER=		${PORTVERSION:S/.//g}
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CONFIGURED_M4=m4 \
		CONFIGURED_BISON=byacc \
		gl_cv_func_gettimeofday_clobber=no \
		lt_cv_sys_max_cmd_len=262144 \
		am_cv_CC_dependencies_compiler_type=gcc3
CONFIGURE_ARGS+=--program-suffix=${VER} \
		--disable-gold \
		--disable-ld \
		--disable-libstdcxx \
		--disable-nls \
		--disable-sim \
		--disable-werror \
		--enable-64-bit-bfd \
		--enable-targets=all \
		--enable-tui \
		--with-gdb-datadir=${PREFIX}/share/gdb \
		--with-guile=no \
		--with-libgmp-type=static \
		--with-separate-debug-dir=/usr/lib/debug \
		--without-expat \
		--without-gnu-as \
		--without-libunwind-ia64 \
		--without-python
CONFIGURE_OUTSOURCE=	yes

CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-fcommon \
		-fno-strict-aliasing \
		-static \
		-DRL_NO_COMPAT \
		-DLIBICONV_PLUG

LDFLAGS+=	--static \
		-lelf \
		-lmd

EXCLUDE=	dejagnu expect sim texinfo intl
EXTRACT_AFTER_ARGS=	${EXCLUDE:S/^/--exclude /}

OPTIONS_DEFINE=	DEBUG GDB_LINK
OPTIONS_DEFAULT=GDB_LINK

GDB_LINK_DESC=		Create ${PREFIX}/bin/gdb symlink

DEBUG_CFLAGS=		-g
DEBUG_VARS=	STRIP=

PLIST_SUB=		VER=${VER}
OPTIONS_SUB=	yes

.include "${.CURDIR}/../gdb-cheri/Makefile.snapshot"

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/gdb/gdb \
		${STAGEDIR}${PREFIX}/bin/gdb${VER}
	(cd ${INSTALL_WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-syscalls )

do-install-GDB_LINK-on:
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdb

.include <bsd.port.post.mk>
