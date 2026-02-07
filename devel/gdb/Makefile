PORTNAME=	gdb
DISTVERSION=	15.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	GNU Project Debugger
WWW=		https://www.gnu.org/software/gdb/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING3

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libzstd.so:archivers/zstd
TEST_DEPENDS=	runtest:misc/dejagnu

USES=		compiler:c++17-lang cpe gmake libtool makeinfo pkgconfig tar:xz
USE_PYTHON=	flavors py3kplist

TEST_TARGET=	check

CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${VER} \
		--disable-sim \
		--enable-targets=all --enable-64-bit-bfd \
		--with-separate-debug-dir=/usr/lib/debug \
		--with-additional-debug-dirs=${LOCALBASE}/lib/debug \
		${ICONV_CONFIGURE_ARG} \
		--without-libunwind-ia64
CONFIGURE_OUTSOURCE=	yes
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT
EXCLUDE=	dejagnu expect texinfo intl
EXTRACT_AFTER_ARGS=	${EXCLUDE:S/^/--exclude /}

VER=		${DISTVERSION:S/.//g}
PLIST_SUB=	VER=${VER}

OPTIONS_DEFINE=	DEBUGINFOD GDB_LINK GUILE KGDB NLS PYTHON \
		SOURCE_HIGHLIGHT TUI XXHASH
OPTIONS_DEFAULT=	GDB_LINK KGDB NLS PYTHON SOURCE_HIGHLIGHT \
			TUI XXHASH
OPTIONS_DEFAULT+=	PORT_READLINE PORT_ICONV SYSTEM_ZLIB

OPTIONS_SINGLE=	READLINE ICONV ZLIB
OPTIONS_SINGLE_READLINE=	BUNDLED_READLINE PORT_READLINE
OPTIONS_SINGLE_ICONV=	PORT_ICONV SYSTEM_ICONV
OPTIONS_SINGLE_ZLIB=	BUNDLED_ZLIB SYSTEM_ZLIB

DEBUGINFOD_DESC=	Build gdb with debuginfod server support
GDB_LINK_DESC=		Create ${PREFIX}/bin/gdb symlink
KGDB_DESC=		Kernel debugging support
BUNDLED_READLINE_DESC=	from gdb distfile
BUNDLED_ZLIB_DESC=	from gdb distfile
PORT_READLINE_DESC=	from devel/readline port
PORT_ICONV_DESC=	use libiconv, with wider charset support
SOURCE_HIGHLIGHT_DESC=	Syntax highlighting support
SYSTEM_ICONV_DESC=	use libc iconv, with no wchar support
SYSTEM_ZLIB_DESC=	use system zlib
TUI_DESC=		Text User Interface support
XXHASH_DESC=		Use xxHash for hashing (faster)

OPTIONS_SUB=	yes

BUNDLED_READLINE_CONFIGURE_OFF=	--with-system-readline
DEBUGINFOD_CONFIGURE_WITH=	debuginfod
DEBUGINFOD_LIB_DEPENDS=	libdebuginfod.so:devel/elfutils
GUILE_CONFIGURE_WITH=	guile=guile-${GUILE_VER}
GUILE_USES=		guile:2.2,3.0
NLS_USES=	gettext-runtime
PORT_READLINE_USES=	readline
PORT_ICONV_USES=	iconv:wchar_t
PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_CMD}
PYTHON_CONFIGURE_OFF=	--without-python
PYTHON_USES=		python
SOURCE_HIGHLIGHT_CONFIGURE_ENABLE=	source-highlight
SOURCE_HIGHLIGHT_LIB_DEPENDS=	\
	libboost_regex.so:devel/boost-libs \
	libsource-highlight.so:textproc/source-highlight
SYSTEM_ICONV_USES=	iconv
SYSTEM_ZLIB_CONFIGURE_WITH=	system-zlib
TUI_CONFIGURE_ENABLE=	tui
XXHASH_CONFIGURE_OFF=	--with-xxhash=no
XXHASH_LIB_DEPENDS=	libxxhash.so:devel/xxhash

ALL_TARGET=	all-gdb

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
GH_TAGNAME=	4bb8585:libcxx

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
		${STAGEDIR}${PREFIX}/share/man/man1/gdb${VER}.1
	(cd ${INSTALL_WRKSRC}/gdb/data-directory ; ${SETENVI} ${WRK_ENV} \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-syscalls )

do-install-KGDB-on:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/gdb/kgdb \
		${STAGEDIR}${PREFIX}/bin/kgdb${VER}
	${INSTALL_MAN} ${FILESDIR}/kgdb/kgdb.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/kgdb${VER}.1

do-install-TUI-on:
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdbtui${VER}

do-install-GDB_LINK-on:
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdb
	${LN} -sf gdb${VER}.1 ${STAGEDIR}${PREFIX}/share/man/man1/gdb.1
.if ${PORT_OPTIONS:MKGDB}
	${LN} -sf kgdb${VER} ${STAGEDIR}${PREFIX}/bin/kgdb
	${LN} -sf kgdb${VER}.1 ${STAGEDIR}${PREFIX}/share/man/man1/kgdb.1
.endif

do-install-PYTHON-on:
	(cd ${INSTALL_WRKSRC}/gdb ; ${SETENVI} ${WRK_ENV} \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
	(cd ${INSTALL_WRKSRC}/gdb/data-directory ; ${SETENVI} ${WRK_ENV} \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
	@(cd ${STAGEDIR}${PREFIX}/share/gdb/python && \
		${PYTHON_CMD} -m compileall .)
. for f in gdb gdb/command gdb/function gdb/printer
	@(cd ${STAGEDIR}${PREFIX}/share/gdb/python/${f} ; ${CHMOD} 644 *.py* )
. endfor
.if exists(/usr/lib/libc++.so.1) || exists(/lib/libc++.so.1)
	@(cd ${WRKSRC_libcxx} ; ${SETENVI} ${WRK_ENV} \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} \
		    LIBCXX_DIR="${LIBCXX_DIR}" install )
	@(cd ${STAGEDIR}${PREFIX}/share/gdb/auto-load/${LIBCXX_DIR} && \
		${PYTHON_CMD} -m compileall .)
	@(cd ${STAGEDIR}${PREFIX}/share/libcxx-gdbpy/libcxx && \
		${PYTHON_CMD} -m compileall .)
.endif

# DO NOT try and add rules here to strip .go files, no matter how loudly
# testport / stage-qa shouts at you about it, because .go files (which are
# compiled bytecode) are not intended to be stripped and doing so causes
# breakage at run time.

do-install-GUILE-on:
	(cd ${INSTALL_WRKSRC}/gdb ; ${SETENVI} ${WRK_ENV} \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-guile )
	(cd ${INSTALL_WRKSRC}/gdb/data-directory ; ${SETENVI} ${WRK_ENV} \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-guile )

.include <bsd.port.post.mk>
