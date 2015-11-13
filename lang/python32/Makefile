# $FreeBSD$

PORTNAME=	python32
PORTVERSION=	3.2.5
PORTREVISION=	14
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

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=		OPT=""							# Null out OPT to respect user CFLAGS and remove optimizations

INSTALL_TARGET=		altinstall						# Don't want cloberring of unprefixed files
MAKE_ARGS+=		INSTALL_SHARED="${INSTALL_LIB}"				# Strip shared library
MAKE_ARGS+=		LIBPC="${PREFIX}/libdata/pkgconfig"			# Until pathfix gets support for files other than Makefile.in
MAKE_JOBS_UNSAFE=	yes							# Parser/pgen build bug. See Issue: 200622, 201974

PLIST_SUB=		ABI=${ABIFLAGS} \
			OSMAJOR=${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}		# For plat-freebsd* in pkg-plist. http://bugs.python.org/issue19554

OPTIONS_DEFINE=		DEBUG IPV6 LIBFFI NLS PYMALLOC THREADS TSC UCS4
OPTIONS_DEFAULT=	IPV6 LIBFFI NLS PYMALLOC THREADS UCS4
OPTIONS_SUB=		yes

LIBFFI_DESC=		Use libffi from ports instead of bundled version
NLS_DESC=		Enable gettext support for the locale module
PYMALLOC_DESC=		Enable specialized mallocs
TSC_DESC=		Enable processor timestamp counter profiling

DEBUG_CONFIGURE_WITH=	pydebug
IPV6_CONFIGURE_ENABLE=	ipv6
LIBFFI_CONFIGURE_ON=	--with-system-ffi
LIBFFI_LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi

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
UCS4_CONFIGURE_WITH=	wide-unicode

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUCS4}
ABIFLAGS:=	u${ABIFLAGS}
.endif

.if ${PORT_OPTIONS:MPYMALLOC}
ABIFLAGS:=	m${ABIFLAGS}
.endif

.if ${PORT_OPTIONS:MDEBUG}
ABIFLAGS:=	d${ABIFLAGS}
.endif

.if !empty(ABIFLAGS)
PLIST_FILES+=	bin/python3.2%%ABI%%
PLIST_FILES+=	bin/python3.2%%ABI%%-config
PLIST_FILES+=	libdata/pkgconfig/python-3.2%%ABI%%.pc
.endif

.if ${ARCH} == sparc64
CFLAGS+=	-DPYTHON_DEFAULT_RECURSION_LIMIT=900
.endif

# See http://bugs.freebsd.org/115940 and http://bugs.freebsd.org/193650
.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS)
PLIST_SUB+=	NO_NIS="@comment "
.else
PLIST_SUB+=	NO_NIS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's,/usr/doc/python-docs-,${PREFIX}/share/doc/python,g' \
		${PATCH_WRKSRC}/Lib/pydoc.py
# Fix for http://bugs.python.org/issue12852 (especially on 10.x+);
# not needed for python33+
	@${REINPLACE_CMD} -e 's|_XOPEN_SOURCE 600|_XOPEN_SOURCE 700|' \
		${WRKSRC}/configure
.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS)
	@${REINPLACE_CMD} -e 's/disabled_module_list =[^]]*/&, "nis"/' \
		${WRKSRC}/setup.py
.endif
# Fix permissions for keyword.py and token.py - otherwise the cache files
# can't be properly recreated, since compileall fails with an IOError.
# This looks like an improper fix in http://bugs.python.org/issue6074
# for Python3.2
# Since side effects for other modules can't be foreseen, do not fix
# it on a source level yet.
	@${CHMOD} a-x ${WRKSRC}/Lib/keyword.py ${WRKSRC}/Lib/token.py

post-install:
.if !${PORT_OPTIONS:MDEBUG}
	# Upstream Issue: http://bugs.python.org/issue17975
	${RM} -f ${STAGEDIR}${PREFIX}/lib/libpython3.so
.endif
	# Strip shared extensions
	for i in ${STAGEDIR}${PREFIX}/lib/python3.2/lib-dynload/*.so; do \
		${STRIP_CMD} $$i; done

regression-test: build
	@cd ${WRKSRC} && ${MAKE} TESTOPTS=-j${MAKE_JOBS_NUMBER} buildbottest

.include <bsd.port.mk>
