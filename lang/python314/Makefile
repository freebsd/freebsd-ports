PORTNAME=	python
DISTVERSION=	${PYTHON_DISTVERSION}
PORTREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION:C/[a-z].*//}
PKGNAMESUFFIX=	${PYTHON_SUFFIX}
DISTNAME=	Python-${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Interpreted object-oriented programming language
WWW=		https://www.python.org/

LICENSE=	PSFL

LIB_DEPENDS=	libffi.so:devel/libffi \
		libzstd.so:archivers/zstd

USES=		compiler:c11 cpe ncurses pathfix pkgconfig readline \
		shebangfix ssl tar:xz
PATHFIX_MAKEFILEIN=	Makefile.pre.in
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
python_CMD=	${PREFIX}/bin/python${PYTHON_DISTVERSION:R}
SHEBANG_FILES=	Lib/*.py Lib/*/*.py Lib/*/*/*.py Lib/*/*/*/*.py
SHEBANG_FILES+=	Lib/test/archivetestdata/exe_with_z64 \
		Lib/test/archivetestdata/exe_with_zip \
		Lib/test/archivetestdata/header.sh

# Duplicate python.mk variables. TODO: Let lang/python?? ports use python.mk bits.
PYTHON_VER=		${PYTHON_DISTVERSION:R}
PYTHON_VERSION=		python${PYTHON_VER}
PYTHON_SUFFIX=		${PYTHON_VER:S/.//g}

DISABLED_EXTENSIONS=	 _gdbm _sqlite3 _tkinter
CONFIGURE_ARGS+=	--enable-shared --without-ensurepip
CONFIGURE_ENV+=		OPT="" # Null out OPT to respect user CFLAGS and remove optimizations

INSTALL_TARGET=		altinstall						# Don't want cloberring of unprefixed files

# TEST_TARGET=		buildbottest # that's the --slow-ci with more resources/longer timeouts
TEST_TARGET=		test # that's the --fast-ci with tighter timeouts and using less resources
# TEST_ARGS: test_gdb requires debug symbols for the test_gdb.test_pretty_print test, so skip it unless defined(WITH_DEBUG)
TEST_ARGS=		TESTOPTS="-j${MAKE_JOBS_NUMBER} ${WITH_DEBUG:U-x test_gdb}"

MAKE_ARGS+=		INSTALL_SHARED="${INSTALL_LIB}"				# Strip shared library

SUB_FILES=		pkg-message
SUB_LIST=		PYTHON_SUFFIX=${PYTHON_SUFFIX}

PLIST_SUB=		ABI=${ABIFLAGS} \
			XY=${PYTHON_SUFFIX} \
			XYDOT=${PYTHON_VER} \
			XYZDOT=${DISTVERSION:C/[a-z].*//} \
			OSMAJOR=${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}		# For plat-freebsd* in pkg-plist. https://bugs.python.org/issue19554

OPTIONS_DEFINE=		DEBUG IPV6 LIBMPDEC LTO NLS PYMALLOC
OPTIONS_DEFAULT=	LIBMPDEC LTO PYMALLOC
OPTIONS_EXCLUDE_powerpc64=	LTO
OPTIONS_EXCLUDE_riscv64=	LTO
OPTIONS_RADIO=		HASH
OPTIONS_RADIO_HASH=	FNV SIPHASH
OPTIONS_SUB=		yes

LIBMPDEC_DESC=		Use libmpdec from ports instead of bundled version
NLS_DESC=		Enable gettext support for the locale module
PYMALLOC_DESC=		Enable specialized mallocs

HASH_DESC=		Hash Algorithm (PEP-456)
FNV_DESC=		Modified Fowler-Noll-Vo Algorithm
SIPHASH_DESC=		SipHash24 Algorithm

FNV_CONFIGURE_ON=	--with-hash-algorithm=fnv
SIPHASH_CONFIGURE_ON=	--with-hash-algorithm=siphash24

DEBUG_CONFIGURE_WITH=	pydebug
IPV6_CONFIGURE_ENABLE=	ipv6

LIBMPDEC_CONFIGURE_ON=	--with-system-libmpdec
LIBMPDEC_LIB_DEPENDS=	libmpdec.so:math/mpdecimal

LTO_CONFIGURE_ON=	--with-lto

# Use CPPFLAGS over CFLAGS due to -I ordering, causing elementtree and pyexpat
# to break in Python 2.7, or preprocessor complaints in Python >= 3.3
# Upstream Issue: https://bugs.python.org/issue6299
NLS_USES=		gettext
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LIBS=		-L${LOCALBASE}/lib -lintl
NLS_CONFIGURE_ENV_OFF=	ac_cv_lib_intl_textdomain=no ac_cv_header_libintl_h=no

PYMALLOC_CONFIGURE_WITH=	pymalloc

.include "${.CURDIR}/Makefile.version"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
ABIFLAGS:=	d${ABIFLAGS}
.endif

.if !empty(ABIFLAGS)
PLIST_FILES+=	bin/python${PYTHON_VER}${ABIFLAGS} \
		bin/python${PYTHON_VER}${ABIFLAGS}-config \
		libdata/pkgconfig/python-${PYTHON_VER}${ABIFLAGS}.pc \
		libdata/pkgconfig/python-${PYTHON_VER}${ABIFLAGS}-embed.pc
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

# Python 3.10 requires OpenSSL >= 1.1.1 (PEP 644), so with
# libressl, some modules are not built
.if ${SSL_DEFAULT:Mlibressl*}
PLIST_SUB+=	SUPPORTED_OPENSSL="@comment "
.else
PLIST_SUB+=	SUPPORTED_OPENSSL=""
.endif

post-patch:
# disable the detection of includes and library from e2fsprogs-libuuid,
# which introduces hidden dependency and breaks build
	@${REINPLACE_CMD} -e 's|uuid/uuid.h|ignore_&|' ${WRKSRC}/configure

# disable detection of multiarch as it breaks with clang >= 13, which adds a
# major.minor version number in -print-multiarch output, confusing Python
	@${REINPLACE_CMD} -e 's|^\( *MULTIARCH=\).*--print-multiarch.*|\1|' ${WRKSRC}/configure
# Apply DISABLED_EXTENSIONS
	@${ECHO_CMD} '*disabled*' > ${WRKSRC}/Modules/Setup.local
.  for _module in ${DISABLED_EXTENSIONS}
		@${ECHO_CMD} ${_module} >> ${WRKSRC}/Modules/Setup.local
.  endfor

post-install:
.if ! ${PORT_OPTIONS:MDEBUG}
	${RM} ${STAGEDIR}${PREFIX}/lib/libpython3.so						# Upstream Issue: https://bugs.python.org/issue17975
.endif
	${LN} -sf libpython${PYTHON_VER}${ABIFLAGS}.so.1.0 ${STAGEDIR}${PREFIX}/lib/libpython${PYTHON_VER}${ABIFLAGS}.so.1
# This code block exists for the qemu-user enabled cross build environment.
# When using this environment in poudriere, CC is not set to the default
# of /usr/bin/cc and a cross-compile toolchain is used.  We need to hand
# edit this so that the run time configuration for python matches what the
# FreeBSD base system provides.  sbruno 02Aug2017
.if ${CC} == /nxb-bin/usr/bin/cc
	@${REINPLACE_CMD} -e 's=/nxb-bin==' \
		${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/_sysconfigdata_${ABIFLAGS}_freebsd${OSREL:R}_.py
	@cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		./python -E -m compileall -d ${PREFIX}/lib/python${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/_sysconfigdata_${ABIFLAGS}_freebsd${OSREL:R}_.py
	@cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		./python -E -O -m compileall -d ${PREFIX}/lib/python${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/_sysconfigdata_${ABIFLAGS}_freebsd${OSREL:R}_.py
	@${REINPLACE_CMD} -e 's=/nxb-bin==' \
		${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/config-${PYTHON_VER}${ABIFLAGS}/Makefile
.endif
	for i in ${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/lib-dynload/*.so; do \
		${STRIP_CMD} $$i; done								# Strip shared extensions
	${INSTALL_DATA} ${WRKSRC}/Tools/gdb/libpython.py \
		${STAGEDIR}${PREFIX}/lib/libpython${PYTHON_VER}${ABIFLAGS}.so.1.0-gdb.py

_sigstorebundle=${DISTFILES}.sigstore
${_sigstorebundle}:
	${FETCH_CMD} ${MASTER_SITES}/${_sigstorebundle}

sigstore-verify: ${_sigstorebundle} checksum
	sigstore verify identity \
		--bundle ${DISTFILES}.sigstore \
		--cert-identity hugo@python.org \
		--cert-oidc-issuer https://github.com/login/oauth \
		${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}

post-clean:
	${RM} ${_sigstorebundle}

.include <bsd.port.mk>
