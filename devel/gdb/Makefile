# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=	8.3.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	GNU GDB of newer version than comes with the system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING3

# untested on sparc64, might work
NOT_FOR_ARCHS=	sparc64

LIB_DEPENDS=	libmpfr.so:math/mpfr
TEST_DEPENDS=	runtest:misc/dejagnu

USES=		compiler:c++11-lang cpe gmake libtool pkgconfig tar:xz
USE_PYTHON=	flavors py3kplist

TEST_TARGET=	check

USE_CSTD=	gnu89
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:S/.//g} \
		--enable-targets=all --enable-64-bit-bfd \
		--with-separate-debug-dir=/usr/lib/debug \
		${ICONV_CONFIGURE_ARG} \
		--with-expat=yes --with-libexpat-prefix=${LOCALBASE} \
		--without-libunwind-ia64 --with-system-zlib
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT -Wno-unused-function -Wno-unused-variable
CFLAGS+=	-Wno-unknown-warning-option
EXCLUDE=	dejagnu expect sim texinfo intl
EXTRACT_AFTER_ARGS=	${EXCLUDE:S/^/--exclude /}
EXTRA_PATCHES=	${FILESDIR}/commit-1163a4b7a3 \
		${FILESDIR}/commit-dd6876c91c \
		${FILESDIR}/commit-6e056c8178 \
		${FILESDIR}/commit-36c53a0262 \
		${FILESDIR}/commit-ef0bd2046f \
		${FILESDIR}/commit-945f3901b5 \
		${FILESDIR}/commit-f5424cfa7e \
		${FILESDIR}/commit-ce25aa57a3 \
		${FILESDIR}/commit-8399425f5f
LIB_DEPENDS+=	libexpat.so:textproc/expat2

VER=		${PORTVERSION:S/.//g}
PLIST_SUB=	VER=${VER}

OPTIONS_DEFINE=	DEBUG GDB_LINK GUILE KGDB NLS PYTHON SOURCE_HIGHLIGHT TUI

OPTIONS_DEFAULT=	GDB_LINK KGDB NLS PYTHON SOURCE_HIGHLIGHT TUI
OPTIONS_DEFAULT+=	PORT_READLINE PORT_ICONV SYSTEM_ZLIB

OPTIONS_SINGLE=	READLINE ICONV ZLIB
OPTIONS_SINGLE_READLINE=	BUNDLED_READLINE PORT_READLINE
OPTIONS_SINGLE_ICONV=	PORT_ICONV SYSTEM_ICONV
OPTIONS_SINGLE_ZLIB=	BUNDLED_ZLIB SYSTEM_ZLIB

GDB_LINK_DESC=		Create ${PREFIX}/bin/gdb symlink
KGDB_DESC=		Kernel Debugging Support
BUNDLED_READLINE_DESC=	from gdb distfile
BUNDLED_ZLIB_DESC=	from gdb distfile
PORT_READLINE_DESC=	from devel/readline port
PORT_ICONV_DESC=	use libiconv, with wider charset support
SOURCE_HIGHLIGHT_DESC=	Source Code Styling
SYSTEM_ICONV_DESC=	use libc iconv, with no wchar support
SYSTEM_ZLIB_DESC=	use system zlib
TUI_DESC=		Text User Interface enabled

OPTIONS_SUB=	yes

BUNDLED_READLINE_CONFIGURE_OFF=	--with-system-readline
DEBUG_CFLAGS=		-g
GUILE_CONFIGURE_WITH=	guile
GUILE_USES=		pkgconfig
GUILE_LIB_DEPENDS=	libguile-2.2.so:lang/guile2
GUILE_EXTRA_PATCHES=	${FILESDIR}/extrapatch-guile22
NLS_USES=	gettext-runtime
PORT_READLINE_USES=	readline:port
PORT_ICONV_USES=	iconv:wchar_t
PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_CMD}
PYTHON_CONFIGURE_OFF=	--without-python
PYTHON_USES=		python
SOURCE_HIGHLIGHT_WITH=	source-highlight
SOURCE_HIGHLIGHT_LIB_DEPENDS=	\
	libsource-highlight.so:textproc/source-highlight
SYSTEM_ICONV_USES=	iconv
SYSTEM_ZLIB_WITH=	system-zlib
TUI_CONFIGURE_ENABLE=	tui

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPYTHON}
.if ${PYTHON_VER} != ${PYTHON_DEFAULT}
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
.endif
.endif

.if ${PORT_OPTIONS:MPYTHON} && exists(/usr/lib/libc++.so.1)
USE_GITHUB=	nodefault

GH_ACCOUNT=	bsdjhb:libcxx
GH_PROJECT=	libcxx-gdbpy:libcxx
GH_TAGNAME=	229610a:libcxx

# Workaround USE_GITHUB preventing the default DISTFILES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

PLIST_SUB+=	LIBCXX=""
.else
PLIST_SUB+=	LIBCXX="@comment "
.endif

.if ! ${PORT_OPTIONS:MBUNDLED_READLINE}
EXCLUDE+=	readline
.endif

.if ! ${PORT_OPTIONS:MBUNDLED_ZLIB}
EXCLUDE+=	zlib
.endif

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

.if ${CHOSEN_COMPILER_TYPE} == clang
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
	${LN} -sf gdb${VER}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/gdb.1
.if ${PORT_OPTIONS:MKGDB}
	${LN} -sf kgdb${VER} ${STAGEDIR}${PREFIX}/bin/kgdb
	${LN} -sf kgdb${VER}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/kgdb.1
.endif

do-install-PYTHON-on:
	(cd ${WRKSRC}/gdb; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
	(cd ${WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
	@(cd ${STAGEDIR}${PREFIX}/share/gdb/python && \
		${PYTHON_CMD} -m compileall .)
. for f in gdb gdb/command gdb/function gdb/printer
	@(cd ${STAGEDIR}${PREFIX}/share/gdb/python/${f} ; ${CHMOD} 644 *.py* )
. endfor
.if exists(/usr/lib/libc++.so.1)
	@(cd ${WRKSRC_libcxx} ; \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} install )
	@(cd ${STAGEDIR}${PREFIX}/share/gdb/auto-load/usr/lib && \
		${PYTHON_CMD} -m compileall .)
	@(cd ${STAGEDIR}${PREFIX}/share/libcxx-gdbpy/libcxx && \
		${PYTHON_CMD} -m compileall .)
.endif

do-install-GUILE-on:
	(cd ${WRKSRC}/gdb; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-guile )
	(cd ${WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-guile )

.include <bsd.port.post.mk>
