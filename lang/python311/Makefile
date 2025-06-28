PORTNAME=	python
DISTVERSION=	${PYTHON_DISTVERSION}
CATEGORIES=	lang python
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION:C/[a-z].*//}
PKGNAMESUFFIX=	${PYTHON_SUFFIX}
DISTNAME=	Python-${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Interpreted object-oriented programming language
WWW=		https://www.python.org/

LICENSE=	PSFL

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		compiler:c11 cpe ncurses pathfix pkgconfig \
		python:${PYTHON_DISTVERSION:R},env readline shebangfix ssl tar:xz
PATHFIX_MAKEFILEIN=	Makefile.pre.in
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
python_CMD=	${PREFIX}/bin/python${PYTHON_DISTVERSION:R}
SHEBANG_FILES=	Lib/*.py Lib/*/*.py Lib/*/*/*.py Lib/*/*/*/*.py
SHEBANG_FILES+=	Lib/test/ziptestdata/exe_with_z64 \
		Lib/test/ziptestdata/exe_with_zip \
		Lib/test/ziptestdata/header.sh

DISABLED_EXTENSIONS=	_sqlite3 _tkinter _gdbm
CONFIGURE_ARGS+=	--enable-shared --without-ensurepip \
			--with-system-ffi
CONFIGURE_ENV+=		OPT="" ac_cv_prog_cc_g=false # Null out OPT to respect user CFLAGS and remove optimizations

INSTALL_TARGET=		altinstall						# Don't want cloberring of unprefixed files

TEST_TARGET=		buildbottest
TEST_ARGS=		TESTOPTS=-j${MAKE_JOBS_NUMBER}

MAKE_ARGS+=		INSTALL_SHARED="${INSTALL_LIB}"				# Strip shared library

SUB_FILES=		pkg-message
SUB_LIST=		PYTHON_SUFFIX=${PYTHON_SUFFIX}

PLIST_SUB=		ABI=${ABIFLAGS} \
			DISTVERSION=${DISTVERSION} \
			OSMAJOR=${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}		# For plat-freebsd* in pkg-plist. https://bugs.python.org/issue19554

OPTIONS_DEFINE=		DEBUG IPV6 LIBMPDEC LTO NLS PYMALLOC
OPTIONS_DEFAULT=	LIBMPDEC LTO PYMALLOC
OPTIONS_EXCLUDE_riscv64=	LTO
OPTIONS_EXCLUDE_powerpc64le=	LTO
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

# See https://bugs.freebsd.org/115940 and https://bugs.freebsd.org/193650
.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS)
PLIST_SUB+=	NO_NIS="@comment "
DISABLED_EXTENSIONS+=	nis
.else
PLIST_SUB+=	NO_NIS=""
.endif

.if ${SSL_DEFAULT:Mlibressl*}
EXTRA_PATCHES+=	${PATCHDIR}/libressl
CONFIGURE_ENV+=	ac_cv_working_openssl_hashlib=yes
.endif

.include <bsd.port.pre.mk>

# llvm17 with -flto=thin makes Programs/_freeze_module crash on armv7; workaround
# cf. https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276249
.if ${ARCH} == armv7 && ${CHOSEN_COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 170 && \
	${COMPILER_VERSION} < 180
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:N${LTO_CONFIGURE_ON}}
.endif

post-patch:
# disable the detection of includes and library from libuuid,
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

.include <bsd.port.post.mk>
