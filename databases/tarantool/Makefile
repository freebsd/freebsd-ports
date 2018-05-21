# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tarantool
PORTVERSION=	1.9.1
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	NoSQL database running in a Lua application server

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		armv6 powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	fails to build: Unsupported architecture

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libicui18n.so:devel/icu \
		libmsgpuck.so:devel/msgpuck \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd

CMAKE_ARGS=	-DCMAKE_INSTALL_FULL_SYSCONFDIR=${ETCDIR} \
		-DCMAKE_INSTALL_LOCALSTATEDIR=/var \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/man
CMAKE_OFF=	ENABLE_BUNDLED_LIBYAML ENABLE_BUNDLED_MSGPUCK ENABLE_BUNDLED_ZSTD
CMAKE_ON=	ENABLE_DIST
MAKE_JOBS_UNSAFE=	yes
USES=		cmake:noninja compiler:c++11-lang gettext-runtime gmake perl5 readline ssl
USE_PERL5=	build
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}

PLIST_SUB=	TT_DATADIR=${TT_DATADIR} \
		TT_LOGDIR=${TT_LOGDIR}
SUB_FILES=	pkg-message

GH_TUPLE=	rtsisyk:luafun:04c99f9:luafun/third_party/luafun \
		tarantool:luajit:b8587fa:luajit/third_party/luajit \
		tarantool:luarocks:6e6fe62:luarocks/third_party/luarocks \
		tarantool:small:22d1bad:small/src/lib/small \
		tarantool:test-run:ff5fb4f:test_run/test-run
USE_GITHUB=	yes

USERS=		tarantool
GROUPS=		tarantool

TT_DATADIR?=	/var/db/tarantool
TT_LOGDIR?=	/var/log/tarantool
TT_RUNDIR?=	/var/run/tarantool

OPTIONS_DEFINE=	DEBUG

DEBUG_CMAKE_BOOL=	ENABLE_BACKTRACE

post-patch:
	@${ECHO_CMD} ${PORTVERSION}-0 > ${WRKSRC}/VERSION
	@${GREP} -lr 'msgpuck/msgpuck.h' ${WRKSRC}/ | ${XARGS} ${REINPLACE_CMD} -e 's|msgpuck/msgpuck.h|msgpuck.h|'

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/tarantool/

.include <bsd.port.mk>
