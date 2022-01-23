# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>

PORTNAME=	tarantool
PORTVERSION=	2.8.3
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	NoSQL database running in a Lua application server

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: mmintrin.h:50:12: invalid conversion between vector type '__m64' (vector of 1 'long long' value) and integer type 'int' of different siz
BROKEN_riscv64=		fails to compile: mmintrin.h:50:12: invalid conversion between vector type '__m64' (vector of 1 'long long' value) and integer type 'int' of different siz
NOT_FOR_ARCHS=		armv6 powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	fails to build: Unsupported architecture

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libicui18n.so:devel/icu \
		libmsgpuck.so:devel/msgpuck \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd

USES=		cmake:noninja compiler:c++11-lang cpe gettext-runtime gmake iconv perl5 readline ssl
USE_PERL5=	build

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
CMAKE_ARGS=	-DCMAKE_INSTALL_FULL_SYSCONFDIR=${ETCDIR} \
		-DCMAKE_INSTALL_LOCALSTATEDIR=/var \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/man
CMAKE_OFF=	ENABLE_BUNDLED_LIBCURL \
		ENABLE_BUNDLED_LIBYAML \
		ENABLE_BUNDLED_MSGPUCK \
		ENABLE_BUNDLED_ZSTD
CMAKE_ON=	ENABLE_DIST
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	tarantool

USERS=		tarantool
GROUPS=		tarantool

PLIST_SUB=	TT_DATADIR=${TT_DATADIR} \
		TT_LOGDIR=${TT_LOGDIR}
SUB_FILES=	pkg-message

GH_TUPLE=	luafun:luafun:f126f9c:luafun_luafun/third_party/luafun \
		tarantool:decNumber:5ddfde1:tarantool_decNumber/third_party/decNumber \
		tarantool:luajit:8304ca9:tarantool_luajit/third_party/luajit \
		tarantool:luarocks:954c2f5:tarantool_luarocks/third_party/luarocks \
		tarantool:small:781fd38:tarantool_small/src/lib/small \
		tarantool:test-run:d16cbdc:tarantool_test_run/test-run
USE_GITHUB=	yes

TT_DATADIR?=	/var/db/tarantool
TT_LOGDIR?=	/var/log/tarantool
TT_RUNDIR?=	/var/run/tarantool

OPTIONS_DEFINE=	DEBUG

DEBUG_CMAKE_BOOL=	ENABLE_BACKTRACE

post-patch:
	@${ECHO_CMD} ${PORTVERSION}-0 > ${WRKSRC}/VERSION
	@${GREP} -lr 'msgpuck/msgpuck.h' ${WRKSRC}/ | ${XARGS} ${REINPLACE_CMD} -e 's|msgpuck/msgpuck.h|msgpuck.h|'
	@${REINPLACE_CMD} -e 's|libmsgpuck.a|libmsgpuck.so|' ${WRKSRC}/cmake/FindMsgPuck.cmake
	@${REINPLACE_CMD} -e 's|lib/msgpuck.h|msgpuck.h|' ${WRKSRC}/src/lib/core/decimal.c

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/tarantool/

.include <bsd.port.mk>
