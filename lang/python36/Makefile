# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	3
CATEGORIES=	lang python
MASTER_SITES=	PYTHON/ftp/python/${PORTVERSION}
PKGNAMESUFFIX=	${PYTHON_SUFFIX}
DISTNAME=	Python-${PORTVERSION}
DIST_SUBDIR=	python

# Resolve sinpi name clash with libm (IEEE-754 violation)
PATCH_SITES=	https://github.com/python/cpython/commit/
PATCHFILES=	f57cd8288dbe6aba99c057f37ad6d58f8db75350.patch:-p1 \
		f9c01a16dae8aa15d264a1937fb589e8598d1c88.patch:-p1

MAINTAINER=	python@FreeBSD.org
COMMENT=	Interpreted object-oriented programming language

LICENSE=	PSFL

USES=		cpe ncurses pathfix pkgconfig readline:port shebangfix ssl tar:xz
PATHFIX_MAKEFILEIN=	Makefile.pre.in
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
python_CMD=	${PREFIX}/bin/python${PYTHON_PORTVERSION:R}
SHEBANG_FILES=	Lib/*.py Lib/*/*.py Lib/*/*/*.py Lib/*/*/*/*.py

# Duplicate python.mk variables. TODO: Let lang/python?? ports use python.mk bits.
PYTHON_VER=		${PYTHON_PORTVERSION:R}
PYTHON_VERSION=		python${PYTHON_VER}
PYTHON_SUFFIX=		${PYTHON_VER:S/.//g}

DISABLED_EXTENSIONS=	_sqlite3 _tkinter _gdbm
CONFIGURE_ARGS+=	--enable-shared --without-ensurepip
CONFIGURE_ENV+=		OPT="" DISABLED_EXTENSIONS="${DISABLED_EXTENSIONS}"	# Null out OPT to respect user CFLAGS and remove optimizations

INSTALL_TARGET=		altinstall						# Don't want cloberring of unprefixed files

TEST_TARGET=		buildbottest
TEST_ARGS=		TESTOPTS=-j${MAKE_JOBS_NUMBER}

MAKE_ARGS+=		INSTALL_SHARED="${INSTALL_LIB}"				# Strip shared library

SUB_FILES=		pkg-message
SUB_LIST=		PYTHON_SUFFIX=${PYTHON_SUFFIX}

PLIST_SUB=		ABI=${ABIFLAGS} \
			XY=${PYTHON_SUFFIX} \
			XYDOT=${PYTHON_VER} \
			XYZDOT=${PORTVERSION} \
			OSMAJOR=${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}		# For plat-freebsd* in pkg-plist. https://bugs.python.org/issue19554

OPTIONS_DEFINE=		DEBUG IPV6 LIBFFI NLS PYMALLOC THREADS
OPTIONS_DEFAULT=	LIBFFI PYMALLOC THREADS
OPTIONS_RADIO=		HASH
OPTIONS_RADIO_HASH=	FNV SIPHASH
OPTIONS_SUB=		yes

LIBFFI_DESC=		Use libffi from ports instead of bundled version
NLS_DESC=		Enable gettext support for the locale module
PYMALLOC_DESC=		Enable specialized mallocs

HASH_DESC=		Hash Algorithm (PEP-456)
FNV_DESC=		Modified Fowler-Noll-Vo Algorithm
SIPHASH_DESC=		SipHash24 Algorithm

FNV_CONFIGURE_ON=	--with-hash-algorithm=fnv
SIPHASH_CONFIGURE_ON=	--with-hash-algorithm=siphash24

DEBUG_CONFIGURE_WITH=	pydebug
IPV6_CONFIGURE_ENABLE=	ipv6

LIBFFI_CONFIGURE_ON=	--with-system-ffi
LIBFFI_LIB_DEPENDS=	libffi.so:devel/libffi

# Use CPPFLAGS over CFLAGS due to -I ordering, causing elementtree and pyexpat
# to break in Python 2.7, or preprocessor complaints in Python >= 3.3
# Upstream Issue: https://bugs.python.org/issue6299
NLS_USES=		gettext
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LIBS=		-L${LOCALBASE}/lib -lintl
NLS_CONFIGURE_ENV_OFF=	ac_cv_lib_intl_textdomain=no ac_cv_header_libintl_h=no

PYMALLOC_CONFIGURE_WITH=	pymalloc

THREADS_CONFIGURE_WITH=	threads
THREADS_LDFLAGS=	-lpthread

.include "${.CURDIR}/Makefile.version"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYMALLOC}
ABIFLAGS:=	m${ABIFLAGS}
.endif

.if ${PORT_OPTIONS:MDEBUG}
ABIFLAGS:=	d${ABIFLAGS}
.endif

.if !empty(ABIFLAGS)
PLIST_FILES+=	bin/python${PYTHON_VER}${ABIFLAGS} \
		bin/python${PYTHON_VER}${ABIFLAGS}-config \
		libdata/pkgconfig/python-${PYTHON_VER}${ABIFLAGS}.pc
.endif

# https://bugs.python.org/issue22521
# https://bugs.python.org/issue23042
.if ${ARCH} == i386 && !${PORT_OPTIONS:MLIBFFI}
BROKEN=		You must use libffi from ports on i386. Enable the LIBFFI option
.endif

.if ${ARCH} == sparc64
CFLAGS+=	-DPYTHON_DEFAULT_RECURSION_LIMIT=900
.endif

# See https://bugs.freebsd.org/115940 and https://bugs.freebsd.org/193650
.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS)
PLIST_SUB+=	NO_NIS="@comment "
DISABLED_EXTENSIONS+=	nis
.else
PLIST_SUB+=	NO_NIS=""
.endif

post-install:
.if ! ${PORT_OPTIONS:MDEBUG}
	${RM} ${STAGEDIR}${PREFIX}/lib/libpython3.so						# Upstream Issue: https://bugs.python.org/issue17975
.endif
# This code block exists for the qemu-user enabled cross build environment.
# When using this environment in poudriere, CC is not set to the default
# of /usr/bin/cc and a cross-compile toolchain is used.  We need to hand
# edit this so that the run time configuration for python matches what the
# FreeBSD base system provides.  sbruno 02Aug2017
.if ${CC} == /nxb-bin/usr/bin/cc
	@${REINPLACE_CMD} -e 's=/nxb-bin==' \
		${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/_sysconfigdata_m_freebsd${OSREL:R}_.py
	@cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		./python -E -m compileall -d ${PREFIX}/lib/python${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/_sysconfigdata_m_freebsd${OSREL:R}_.py
	@cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		./python -E -O -m compileall -d ${PREFIX}/lib/python${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/_sysconfigdata_m_freebsd${OSREL:R}_.py
	@${REINPLACE_CMD} -e 's=/nxb-bin==' \
		${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/config-${PYTHON_VER}m/Makefile
.endif
	for i in ${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/lib-dynload/*.so; do \
		${STRIP_CMD} $$i; done								# Strip shared extensions
	${INSTALL_DATA} ${WRKSRC}/Tools/gdb/libpython.py \
		${STAGEDIR}${PREFIX}/lib/libpython${PYTHON_VER}${ABIFLAGS}.so.1.0-gdb.py

.include <bsd.port.mk>
