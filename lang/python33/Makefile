# $FreeBSD$

PORTNAME=	python33
PORTVERSION=	3.3.5
PORTREVISION=	5
CATEGORIES=	lang python ipv6
MASTER_SITES=	PYTHON
MASTER_SITE_SUBDIR=	ftp/python/${PORTVERSION}
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

PLIST_SUB=		ABI=${ABIFLAGS} \
			OSMAJOR=${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}		# For plat-freebsd* in pkg-plist. http://bugs.python.org/issue19554

OPTIONS_DEFINE=		DEBUG IPV6 NLS PYMALLOC THREADS TSC LIBFFI
OPTIONS_DEFAULT=	IPV6 NLS PYMALLOC THREADS LIBFFI
OPTIONS_SUB=		yes

NLS_DESC=		Enable gettext support for the locale module
PYMALLOC_DESC=		Enable specialized mallocs
TSC_DESC=		Enable processor timestamp counter profiling
LIBFFI_DESC=		Use libffi from ports instead of bundled version

DEBUG_CONFIGURE_WITH=	pydebug
IPV6_CONFIGURE_ENABLE=	ipv6

# Use CPPFLAGS over CFLAGS due to -I ordering, causing elementtree and pyexpat
# to break in Python 2.7, or preprocessor complaints in Python >= 3.3
# Upstream Issue: http://bugs.python.org/issue6299
NLS_USES=		gettext
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LIBS=		-L${LOCALBASE}/lib -lintl
NLS_CONFIGURE_ENV_OFF=	ac_cv_lib_intl_textdomain=no ac_cv_header_libintl_h=no

PYMALLOC_CONFIGURE_WITH=	pymalloc

THREADS_CONFIGURE_WITH=	threads
THREADS_CFLAGS=		${PTHREAD_CFLAGS}
THREADS_LDFLAGS=	${PTHREAD_LIBS}
TSC_CONFIGURE_WITH=	tsc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYMALLOC}
ABIFLAGS:=	m${ABIFLAGS}
.endif

.if ${PORT_OPTIONS:MDEBUG}
ABIFLAGS:=	d${ABIFLAGS}
.endif

.if ${PORT_OPTIONS:MLIBFFI}
CONFIGURE_ARGS+=	--with-system-ffi
LIB_DEPENDS+=		libffi.so:${PORTSDIR}/devel/libffi
.endif

.if !empty(ABIFLAGS)
PLIST_FILES+=	bin/python3.3%%ABI%%
PLIST_FILES+=	bin/python3.3%%ABI%%-config
PLIST_FILES+=	libdata/pkgconfig/python-3.3%%ABI%%.pc
.endif

.if ${ARCH} == sparc64
CFLAGS+=	-DPYTHON_DEFAULT_RECURSION_LIMIT=900
.endif

# See http://bugs.freebsd.org/115940
.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS) # the world with NO_NIS
PLIST_SUB+=	NO_NIS="@comment "
.else
PLIST_SUB+=	NO_NIS=""
.endif

post-patch:
.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS)
	@${REINPLACE_CMD} -e 's/disabled_module_list =[^]]*/&, "nis"/' \
		${WRKSRC}/setup.py
.endif

post-install:
.if ! ${PORT_OPTIONS:MDEBUG}
	${RM} -f ${STAGEDIR}${PREFIX}/lib/libpython3.so						# Upstream Issue: http://bugs.python.org/issue17975
.endif
	for i in ${STAGEDIR}${PREFIX}/lib/python3.3/lib-dynload/*.so; do \
		${STRIP_CMD} $$i; done								# Strip shared extensions

regression-test: build
	@cd ${WRKSRC} && ${MAKE} TESTOPTS=-j${MAKE_JOBS_NUMBER} buildbottest

.include <bsd.port.mk>
