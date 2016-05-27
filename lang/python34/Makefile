# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python34
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	2
CATEGORIES=	lang python ipv6
MASTER_SITES=	PYTHON/ftp/python/${PORTVERSION}
DISTNAME=	Python-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Interpreted object-oriented programming language

LICENSE=	PSFL

USES=		cpe ncurses pkgconfig readline tar:xz
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPE_VENDOR=	python
CPE_PRODUCT=	${CPE_VENDOR}
CPE_VERSION=	${PORTVERSION}

DISABLED_EXTENSIONS=	_sqlite3 _tkinter _gdbm
CONFIGURE_ARGS+=	--enable-shared --without-ensurepip
CONFIGURE_ENV+=		OPT="" DISABLED_EXTENSIONS="${DISABLED_EXTENSIONS}"	# Null out OPT to respect user CFLAGS and remove optimizations

INSTALL_TARGET=		altinstall						# Don't want cloberring of unprefixed files

TEST_TARGET=		buildbottest
TEST_ARGS=		TESTOPTS=-j${MAKE_JOBS_NUMBER}

MAKE_ARGS+=		INSTALL_SHARED="${INSTALL_LIB}"				# Strip shared library
MAKE_ARGS+=		LIBPC="${PREFIX}/libdata/pkgconfig"			# Until pathfix gets support for files other than Makefile.in
MAKE_JOBS_UNSAFE=	yes							# Parser/pgen build bug. See Issue: 200622, 201974

SUB_FILES=		pkg-message
SUB_LIST=		PYTHON_SUFFIX=${PORTVERSION:R:S/.//g}

PLIST_SUB=		ABI=${ABIFLAGS} \
			OSMAJOR=${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}		# For plat-freebsd* in pkg-plist. http://bugs.python.org/issue19554

OPTIONS_DEFINE=		DEBUG IPV6 LIBFFI NLS PYMALLOC THREADS TSC
OPTIONS_DEFAULT=	LIBFFI PYMALLOC THREADS
OPTIONS_RADIO=		HASH
OPTIONS_RADIO_HASH=	FNV SIPHASH
OPTIONS_SUB=		yes

LIBFFI_DESC=		Use libffi from ports instead of bundled version
NLS_DESC=		Enable gettext support for the locale module
PYMALLOC_DESC=		Enable specialized mallocs
TSC_DESC=		Enable processor timestamp counter profiling

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
# Upstream Issue: http://bugs.python.org/issue6299

NLS_USES=		gettext
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LIBS=		-L${LOCALBASE}/lib -lintl
NLS_CONFIGURE_ENV_OFF=	ac_cv_lib_intl_textdomain=no ac_cv_header_libintl_h=no

PYMALLOC_CONFIGURE_WITH=	pymalloc

THREADS_CONFIGURE_WITH=	threads
THREADS_LDFLAGS=	-lpthread

TSC_CONFIGURE_WITH=	tsc

.include "${.CURDIR}/Makefile.version"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYMALLOC}
ABIFLAGS:=	m${ABIFLAGS}
.endif

.if ${PORT_OPTIONS:MDEBUG}
ABIFLAGS:=	d${ABIFLAGS}
.endif

.if !empty(ABIFLAGS)
PLIST_FILES+=	bin/python3.4%%ABI%%
PLIST_FILES+=	bin/python3.4%%ABI%%-config
PLIST_FILES+=	libdata/pkgconfig/python-3.4%%ABI%%.pc
.endif

# http://bugs.python.org/issue22521
# http://bugs.python.org/issue23042
.if ${ARCH} == i386 && !${PORT_OPTIONS:MLIBFFI}
BROKEN=	You must use libffi from ports on i386. Enable the LIBFFI option
.endif

.if ${ARCH} == sparc64
CFLAGS+=	-DPYTHON_DEFAULT_RECURSION_LIMIT=900
.endif

# See http://bugs.freebsd.org/115940 and http://bugs.freebsd.org/193650
.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS)
PLIST_SUB+=	NO_NIS="@comment "
DISABLED_EXTENSIONS+=	nis
.else
PLIST_SUB+=	NO_NIS=""
.endif

post-install:
.if ! ${PORT_OPTIONS:MDEBUG}
	${RM} -f ${STAGEDIR}${PREFIX}/lib/libpython3.so						# Upstream Issue: http://bugs.python.org/issue17975
.endif
	for i in ${STAGEDIR}${PREFIX}/lib/python3.4/lib-dynload/*.so; do \
		${STRIP_CMD} $$i; done								# Strip shared extensions

.include <bsd.port.mk>
