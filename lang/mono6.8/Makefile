PORTNAME=	mono
PORTVERSION=	6.8.0.123
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	https://download.mono-project.com/sources/mono/
PKGNAMESUFFIX=	6.8
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source implementation of .NET Development Framework
WWW=		https://www.mono-project.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	riscv64 riscv64sf

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser \
		bash:shells/bash \
		cmake-core>0:devel/cmake-core
LIB_DEPENDS=	libinotify.so:devel/libinotify
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		ca_root_nss>=0:security/ca_root_nss \
		sqlite3>0:databases/sqlite3 \
		zip>=0:archivers/zip

CONFLICTS_INSTALL=	certmgr coin-or-disco disco mono mono[0-9]*

USES=	autoreconf:2.69 bison compiler:c11 cpe gmake iconv libtool localbase \
	pathfix perl5 python shebangfix tar:xz
USE_PERL5=	build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

SHEBANG_FILES=	mono/mini/genmdesc.py \
		mono/tests/gc-descriptors/gen-descriptor-tests.py \
		mono/tests/test_lldb.py scripts/mono-find-provides.in \
		scripts/mono-find-requires.in scripts/mono-heapviz \
		scripts/mono-package-runtime
BINARY_ALIAS=	python=${PYTHON_CMD}

CONFIGURE_ARGS_aarch64=	--with-csc=mcs
CONFIGURE_ARGS=	${CONFIGURE_ARGS_${ARCH}} --disable-dtrace
# Do not remove - this is needed to work around automake's lack of hinting
CONFIGURE_ENV+=	ac_cv_header_sys_inotify_h=yes

MAKE_ENV=	MONO_SHARED_DIR="${WRKDIR}" \
		INSTALL_STRIP_FLAG="${STRIP}"

TEST_ARGS=	-k
TEST_TARGET=	check

PORTSCOUT=	limit:^\d+\.\d+\.[1-9]\d*

# XXX MCL mat says: no. Options must not change themselves depending on what is installed.
# XXX MCL just leave this out for now to try to get *something* done.
# .if !exists(${LOCALBASE}/bin/mcs)
# OPTIONS_SLAVE=	MONOLITE
# .endif

# intentionally sorted alpha, then SPECTRE and MONODEV at the end
# because they have performance and security implications
OPTIONS_DEFINE=		BIGARRAY MONOLITE NINJA NLS ODBC X11 SPECTRE MONODEV
OPTIONS_DEFAULT=	MONOLITE NLS X11
OPTIONS_SUB=	yes

BIGARRAY_DESC=	Enable allocating arrays greater than Int32.MaxValue
BIGARRAY_CONFIGURE_ENABLE=	big-arrays

MONOLITE_DESC=		Use monolite to bootstrap mcs (otherwise use installed mcs)
MONOLITE_DISTFILES=	monolite-linux-${MONOLITE_VERSION}-latest.tar.gz:monolite
MONOLITE_MASTER_SITES=	http://download.mono-project.com/monolite/:monolite
# DO NOT ALTER OR REMOVE. DANGER, CASE-SENSITIVE!
# monolite 2020-01-13 @ 1798d23b
MONOLITE_VERSION=	1798d23b-3dbc-4161-b3f4-6bb00134ee4e

MONODEV_DESC=	Build for Mono development (disables crash privacy)
MONODEV_CONFIGURE_ON=	--enable-icall-symbol-map --enable-icall-export --with-crash_privacy=no

NINJA_DESC=	Use ninja to build wherever possible
NINJA_CONFIGURE_ON=	--enable-ninja
NINJA_USES=	ninja:build

NLS_DESC=	NLS Localization Support
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=	gettext

ODBC_DESC=	System.Data: support for unixODBC
ODBC_BUILD_DEPENDS=	unixODBC>0:databases/unixODBC
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

SPECTRE_DESC=	Enable internal Mono Spectre mitigations (SEE pkg-descr)
SPECTRE_CONFIGURE_ON=	--with-spectre-mitigation=yes

X11_USES=	display:test
X11_CONFIGURE_WITH=	x
X11_RUN_DEPENDS=	pango>0:x11-toolkits/pango \
	libgdiplus>0:x11-toolkits/libgdiplus

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
PLIST+=		${.CURDIR}/pkg-plist.powerpc
.endif

.include <bsd.port.pre.mk>

.if defined(QEMU_EMULATING) && "${QEMU_EMULATING}" == "1"
BROKEN=		fails to build under qemu: Roslyn requires more functional POSIX implementation
.endif

post-patch:
	# Needed to force regeneration due to tarball packaging
	${RM} ${WRKSRC}/configure ${WRKSRC}/Makefile \
		${WRKSRC}/mono/Makefile \
		${WRKSRC}/mono/native/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/mono
# XXX Drop after devel/msbuild >= 16.0 per https://github.com/mono/msbuild/commit/48f3571f4036
	${RLN} ${STAGEDIR}${PREFIX}/lib/mono/msbuild/Current \
		${STAGEDIR}${PREFIX}/lib/mono/msbuild/15.0
	${ECHO_CMD} lib/mono/msbuild/15.0 >>${TMPPLIST}

.include <bsd.port.post.mk>
