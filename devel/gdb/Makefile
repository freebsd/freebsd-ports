PORTNAME=	gdb
DISTVERSION=	12.1
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	GNU Project Debugger

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING3

# untested on sparc64, might work
NOT_FOR_ARCHS=	sparc64

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
TEST_DEPENDS=	runtest:misc/dejagnu

USES=		compiler:c++11-lang cpe gmake libtool makeinfo pkgconfig tar:xz
USE_PYTHON=	flavors py3kplist

TEST_TARGET=	check

CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${DISTVERSION:S/.//g} \
		--enable-targets=all --enable-64-bit-bfd \
		--with-separate-debug-dir=/usr/lib/debug \
		${ICONV_CONFIGURE_ARG} \
		--with-expat=yes --with-libexpat-prefix=${LOCALBASE} \
		--without-libunwind-ia64 --with-system-zlib
CONFIGURE_OUTSOURCE=	yes
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT
EXCLUDE=	dejagnu expect sim texinfo intl
EXTRACT_AFTER_ARGS=	${EXCLUDE:S/^/--exclude /}
EXTRA_PATCHES=	${FILESDIR}/commit-711b0b6698f \
		${FILESDIR}/commit-922c2fc18e4 \
		${FILESDIR}/commit-b1babce7c31 \
		${FILESDIR}/commit-a49ce729c80 \
		${FILESDIR}/commit-c77282d8ba9 \
		${FILESDIR}/commit-041a4212d37 \
		${FILESDIR}/commit-4bd817e71ee \
		${FILESDIR}/commit-1570c37c340 \
		${FILESDIR}/commit-6719bc690e2 \
		${FILESDIR}/commit-983b1119bc3 \
		${FILESDIR}/commit-a3627b54280 \
		${FILESDIR}/commit-065a00b3a46 \
		${FILESDIR}/commit-e330d4c033e \
		${FILESDIR}/commit-a171378aa47 \
		${FILESDIR}/commit-b5c2367c3ac \
		${FILESDIR}/commit-f3215e1526d \
		${FILESDIR}/commit-c13566fdd57 \
		${FILESDIR}/commit-3181aed81c9 \
		${FILESDIR}/commit-8e6afe4013f \
		${FILESDIR}/commit-40c23d88038 \
		${FILESDIR}/commit-92d48a1e4ea \
		${FILESDIR}/commit-099fbce0acc \
		${FILESDIR}/commit-2e686a74dc4 \
		${FILESDIR}/commit-684943d213b \
		${FILESDIR}/commit-414d5848bb2 \
		${FILESDIR}/commit-0a765c1a8e9 \
		${FILESDIR}/commit-f9fbb7636a5 \
		${FILESDIR}/commit-b7fe5463cf0 \
		${FILESDIR}/commit-b2fdd31b03e
LIB_DEPENDS+=	libexpat.so:textproc/expat2

VER=		${DISTVERSION:S/.//g}
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
DEBUG_VARS=	STRIP=
GUILE_CONFIGURE_WITH=	guile
GUILE_LIB_DEPENDS=	libguile-2.2.so:lang/guile2
NLS_USES=	gettext-runtime
PORT_READLINE_USES=	readline
PORT_ICONV_USES=	iconv:wchar_t
PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_CMD}
PYTHON_CONFIGURE_OFF=	--without-python
PYTHON_USES=		python:3.6+
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

.if ${PORT_OPTIONS:MPYTHON} && \
    (exists(/usr/lib/libc++.so.1) || exists(/lib/libc++.so.1))
USE_GITHUB=	nodefault

GH_ACCOUNT=	bsdjhb:libcxx
GH_PROJECT=	libcxx-gdbpy:libcxx
GH_TAGNAME=	03d0d9b:libcxx

# Workaround USE_GITHUB preventing the default DISTFILES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

.if exists(/usr/lib/libc++.so.1)
LIBCXX_DIR=	/usr/lib
.else
LIBCXX_DIR=	/lib
.endif

PLIST_SUB+=	LIBCXX_DIR="${LIBCXX_DIR}"
PLIST_SUB+=	LIBCXX=""
.else
PLIST_SUB+=	LIBCXX="@comment "
.endif

.if ! ${PORT_OPTIONS:MBUNDLED_ZLIB}
EXCLUDE+=	zlib
.endif

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$| [GDB v${DISTVERSION} for FreeBSD]|' \
		${WRKSRC}/gdb/version.in

post-patch-KGDB-on:
	@${CP} -r ${FILESDIR}/kgdb/*.[ch] ${WRKSRC}/gdb/
	@${PATCH} -d ${PATCH_WRKSRC} ${PATCH_ARGS} < ${FILESDIR}/extrapatch-kgdb

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/gdb/gdb \
		${STAGEDIR}${PREFIX}/bin/gdb${VER}
	${INSTALL_MAN} ${WRKSRC}/gdb/doc/gdb.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/gdb${VER}.1
	(cd ${INSTALL_WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-syscalls )

do-install-KGDB-on:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/gdb/kgdb \
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
	(cd ${INSTALL_WRKSRC}/gdb ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
	(cd ${INSTALL_WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
	@(cd ${STAGEDIR}${PREFIX}/share/gdb/python && \
		${PYTHON_CMD} -m compileall .)
. for f in gdb gdb/command gdb/function gdb/printer
	@(cd ${STAGEDIR}${PREFIX}/share/gdb/python/${f} ; ${CHMOD} 644 *.py* )
. endfor
.if exists(/usr/lib/libc++.so.1) || exists(/lib/libc++.so.1)
	@(cd ${WRKSRC_libcxx} ; \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} \
		    LIBCXX_DIR="${LIBCXX_DIR}" install )
	@(cd ${STAGEDIR}${PREFIX}/share/gdb/auto-load/${LIBCXX_DIR} && \
		${PYTHON_CMD} -m compileall .)
	@(cd ${STAGEDIR}${PREFIX}/share/libcxx-gdbpy/libcxx && \
		${PYTHON_CMD} -m compileall .)
.endif

do-install-GUILE-on:
	(cd ${INSTALL_WRKSRC}/gdb ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-guile )
	(cd ${INSTALL_WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-guile )

.include <bsd.port.post.mk>
