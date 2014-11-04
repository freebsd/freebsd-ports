# $FreeBSD$

PORTNAME=	python27
PORTVERSION=	2.7.8
PORTREVISION=	6
CATEGORIES=	lang python ipv6
MASTER_SITES=	PYTHON
MASTER_SITE_SUBDIR=	ftp/python/${PORTVERSION}
DISTNAME=	Python-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Interpreted object-oriented programming language

LICENSE=	PSFL

USES=		cpe ncurses pkgconfig readline tar:xz
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

CPE_VENDOR=	python
CPE_PRODUCT=	${CPE_VENDOR}
CPE_VERSION=	${PORTVERSION}

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=		ac_cv_opt_olimit_ok=no OPT=""				# Null out OPT to respect user CFLAGS and remove optimizations

INSTALL_TARGET=		altinstall						# Don't want cloberring of unprefixed files
MAKE_ARGS+=		INSTALL_SHARED="${INSTALL_LIB}"				# Strip shared library
MAKE_ARGS+=		LIBPC="${PREFIX}/libdata/pkgconfig"			# Until pathfix gets support for files other than Makefile.in

PLIST_SUB=		ABI=${ABIFLAGS} \
			PORTVERSION=${PORTVERSION} \
			OSMAJOR=${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}		# For plat-freebsd* in pkg-plist. http://bugs.python.org/issue19554

OPTIONS_DEFINE=		DEBUG IPV6 NLS PYMALLOC SEM THREADS LIBFFI
OPTIONS_DEFAULT=	IPV6 NLS PYMALLOC SEM THREADS UCS4 LIBFFI
OPTIONS_SINGLE=		UNICODE
OPTIONS_SINGLE_UNICODE=	UCS2 UCS4

OPTIONS_SUB=		yes

NLS_DESC=	Enable gettext support for the locale module
UCS2_DESC=	Enable UCS2 Unicode Strings
UCS4_DESC=	Enable UCS4 Unicode Strings
PYMALLOC_DESC=	Enable specialized mallocs
LIBFFI_DESC=	Use libffi from ports instead of bundled version

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

SEM_CONFIGURE_ENV=	ac_cv_posix_semaphores_enabled=yes
SEM_CONFIGURE_ENV_OFF=	ac_cv_posix_semaphores_enabled=no

THREADS_CONFIGURE_WITH=	threads
THREADS_CFLAGS=		${PTHREAD_CFLAGS}
THREADS_LDFLAGS=	${PTHREAD_LIBS}

UCS2_CONFIGURE_ON=	--enable-unicode=ucs2
UCS4_CONFIGURE_ON=	--enable-unicode=ucs4

.include <bsd.port.options.mk>

.if ${ARCH} == i386
PLIST_SUB+=	X86_ONLY=""
.else
PLIST_SUB+=	X86_ONLY="@comment "
.endif
.if ${ARCH} == amd64 || ${ARCH} == ia64 || ${ARCH} == sparc64 || ${ARCH} == powerpc64
PLIST_SUB+=	32BIT_ONLY="@comment "
.else
PLIST_SUB+=	32BIT_ONLY=""
.endif
.if ${ARCH} == powerpc64
MAKE_ENV+=	UNAME_m="powerpc64"
.endif
.if ${ARCH} == sparc64
CFLAGS+=	-DPYTHON_DEFAULT_RECURSION_LIMIT=900
.endif

.if ${PORT_OPTIONS:MLIBFFI}
CONFIGURE_ARGS+=	--with-system-ffi
LIB_DEPENDS+=		libffi.so:${PORTSDIR}/devel/libffi
.endif

# See http://bugs.freebsd.org/115940
.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS) # the world with NO_NIS
PLIST_SUB+=	NO_NIS="@comment "
.else
PLIST_SUB+=	NO_NIS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's,/usr/doc/python-docs-,${PREFIX}/share/doc/python,g' \
		${PATCH_WRKSRC}/Lib/pydoc.py
.if ${PORT_OPTIONS:MSEM}
	@# do not use SEM_EXTRA_PATCHES here, since patch-setup.py overlaps with this one
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-setup.py
.endif

.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS)
	@${REINPLACE_CMD} -e 's/disabled_module_list =[^]]*/&, "nis"/' \
		${WRKSRC}/setup.py
.endif

post-install:
	for i in ${STAGEDIR}${PREFIX}/lib/python2.7/lib-dynload/*.so; do \
		${STRIP_CMD} $$i; done						# Strip shared extensions

regression-test: build
	@cd ${WRKSRC} && ${MAKE} TESTOPTS=-j${MAKE_JOBS_NUMBER} buildbottest

.include <bsd.port.mk>
