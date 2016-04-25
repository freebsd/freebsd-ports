# $FreeBSD$

PORTNAME=	python27
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
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

CPE_VENDOR=	python
CPE_PRODUCT=	${CPE_VENDOR}
CPE_VERSION=	${PORTVERSION}

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=		ac_cv_opt_olimit_ok=no OPT=""				# Null out OPT to respect user CFLAGS and remove optimizations

INSTALL_TARGET=		altinstall						# Don't want cloberring of unprefixed files

TEST_TARGET=		buildbottest
TEST_ARGS=		TESTOPTS=-j${MAKE_JOBS_NUMBER}

MAKE_ARGS+=		INSTALL_SHARED="${INSTALL_LIB}"				# Strip shared library
MAKE_ARGS+=		LIBPC="${PREFIX}/libdata/pkgconfig"			# Until pathfix gets support for files other than Makefile.in
MAKE_JOBS_UNSAFE=	yes							# Parser/pgen build bug. See Issue: 200622, 201974

PLIST_SUB=		ABI=${ABIFLAGS} \
			PORTVERSION=${PORTVERSION} \
			OSMAJOR=${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}		# For plat-freebsd* in pkg-plist. http://bugs.python.org/issue19554

OPTIONS_DEFINE=		DEBUG IPV6 LIBFFI NLS PYMALLOC SEM THREADS
OPTIONS_DEFAULT=	IPV6 LIBFFI NLS PYMALLOC SEM THREADS UCS4
OPTIONS_SINGLE=		UNICODE
OPTIONS_SINGLE_UNICODE=	UCS2 UCS4
OPTIONS_SUB=		yes

LIBFFI_DESC=	Use libffi from ports instead of bundled version
NLS_DESC=	Enable gettext support for the locale module
UCS2_DESC=	Enable UCS2 Unicode Strings
UCS4_DESC=	Enable UCS4 Unicode Strings
PYMALLOC_DESC=	Enable specialized mallocs

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

SEM_CONFIGURE_ENV=	ac_cv_posix_semaphores_enabled=yes
SEM_CONFIGURE_ENV_OFF=	ac_cv_posix_semaphores_enabled=no

THREADS_CONFIGURE_WITH=	threads
THREADS_LDFLAGS=	-lpthread

UCS2_CONFIGURE_ON=	--enable-unicode=ucs2
UCS4_CONFIGURE_ON=	--enable-unicode=ucs4

.include "${.CURDIR}/Makefile.version"
.include <bsd.port.options.mk>

# http://bugs.python.org/issue22521
# http://bugs.python.org/issue23042
.if !${PORT_OPTIONS:MLIBFFI} && ${ARCH} == i386
BROKEN=	You must use libffi from ports on i386. Enable the LIBFFI option
.endif

.if ${ARCH} == i386
PLIST_SUB+=	X86_ONLY=""
.else
PLIST_SUB+=	X86_ONLY="@comment "
.endif

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == ia64 || ${ARCH} == sparc64 || ${ARCH} == powerpc64 || ${ARCH} == mips64
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

.include <bsd.port.mk>
