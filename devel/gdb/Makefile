# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=	8.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	GNU GDB of newer version than comes with the system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING3

# untested on sparc64, might work
ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 mips powerpc powerpc64

LIB_DEPENDS=	libmpfr.so:math/mpfr
TEST_DEPENDS=	runtest:misc/dejagnu

TEST_TARGET=	check
# XXX: This should be compiler:c++11-lib as GDB doesn't really require
# C++14.  However, clang in 10.3 crashes while building this port.
# Requiring C++14 forces 10.3 to use an external version of clang while
# still using the base system clang on 11.0 and later.
USES=		compiler:c++14-lang cpe iconv gmake libtool tar:xz
USE_CSTD=	gnu89
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:S/.//g} \
		--enable-targets=all --enable-64-bit-bfd \
		--with-gdb-datadir=${PREFIX}/share/gdb${PORTVERSION:S/.//g} \
		--with-separate-debug-dir=/usr/lib/debug \
		${ICONV_CONFIGURE_ARG} \
		--with-expat=yes --with-libexpat-prefix=${LOCALBASE} \
		--without-libunwind-ia64
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT -Wno-unused-function -Wno-unused-variable
CFLAGS+=	-Wno-unknown-warning-option
EXCLUDE=	dejagnu expect sim texinfo intl
EXTRACT_AFTER_ARGS=	${EXCLUDE:S/^/--exclude /}
EXTRA_PATCHES=	${FILESDIR}/commit-d2176225dc \
		${FILESDIR}/commit-b999e2038d \
		${FILESDIR}/commit-262f62f57d \
		${FILESDIR}/commit-92fce24de2 \
		${FILESDIR}/commit-2d97a5d9d3 \
		${FILESDIR}/commit-906b4aac4c \
		${FILESDIR}/commit-f169cfdc08 \
		${FILESDIR}/commit-12279366d7 \
		${FILESDIR}/commit-386a867618 \
		${FILESDIR}/commit-7efba073e2
LIB_DEPENDS+=	libexpat.so:textproc/expat2

VER=		${PORTVERSION:S/.//g}
PLIST_SUB=	VER=${VER}

OPTIONS_DEFINE=	DEBUG GDB_LINK GUILE KGDB PYTHON TUI

OPTIONS_DEFAULT=	GDB_LINK KGDB PYTHON TUI PORT_READLINE

OPTIONS_SINGLE=	READLINE
OPTIONS_SINGLE_READLINE=	BUNDLED_READLINE PORT_READLINE

GDB_LINK_DESC=		Create ${PREFIX}/bin/gdb symlink
KGDB_DESC=		Kernel Debugging Support
BUNDLED_READLINE_DESC=	from gdb distfile
PORT_READLINE_DESC=	from devel/readline port
TUI_DESC=		Text User Interface enabled

OPTIONS_SUB=	yes

BUNDLED_READLINE_CONFIGURE_OFF=	--with-system-readline
DEBUG_CFLAGS=		-g
GUILE_CONFIGURE_WITH=	guile
GUILE_USES=		pkgconfig
GUILE_LIB_DEPENDS=	libguile-2.0.so:lang/guile2
PORT_READLINE_USES=	readline:port
PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_CMD}
PYTHON_CONFIGURE_OFF=	--without-python
PYTHON_USES=		python
TUI_CONFIGURE_ENABLE=	tui

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MBUNDLED_READLINE}
EXCLUDE+=	readline
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

.if ${COMPILER_TYPE} == "clang"
CFLAGS+=	-Wno-extended-offsetof
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$| [GDB v${PORTVERSION} for FreeBSD]|' \
		${WRKSRC}/gdb/version.in

post-patch-KGDB-on:
	@${CP} -r ${FILESDIR}/kgdb/*.[ch] ${WRKSRC}/gdb/
	@${PATCH} -d ${PATCH_WRKSRC} ${PATCH_ARGS} < ${FILESDIR}/extrapatch-kgdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${STAGEDIR}${PREFIX}/bin/gdb${VER}
	${INSTALL_MAN} ${WRKSRC}/gdb/doc/gdb.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/gdb${VER}.1
	(cd ${WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-syscalls )

do-install-KGDB-on:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/kgdb \
		${STAGEDIR}${PREFIX}/bin/kgdb${VER}
	${INSTALL_MAN} ${FILESDIR}/kgdb/kgdb.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/kgdb${VER}.1

do-install-TUI-on:
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdbtui${VER}

do-install-GDB_LINK-on:
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdb
.if ${PORT_OPTIONS:MKGDB}
	${LN} -sf kgdb${VER} ${STAGEDIR}${PREFIX}/bin/kgdb
.endif

do-install-PYTHON-on:
	(cd ${WRKSRC}/gdb; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
	(cd ${WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
. for f in gdb gdb/command gdb/function gdb/printer
	@(cd ${STAGEDIR}${PREFIX}/share/gdb${VER}/python/${f} ; ${CHMOD} 644 *.py* )
. endfor

do-install-GUILE-on:
	(cd ${WRKSRC}/gdb; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-guile )
	(cd ${WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-guile )

.include <bsd.port.post.mk>
