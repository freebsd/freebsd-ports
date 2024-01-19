PORTNAME=	tarantool
PORTVERSION=	3.0.0
CATEGORIES=	databases
MASTER_SITES=	https://download.tarantool.org/tarantool/src/

MAINTAINER=	balaev@tarantool.org
COMMENT=	NoSQL database running in a Lua application server
WWW=		https://tarantool.io/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		armv6 i386 powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	fails to build: Unsupported architecture

BUILD_DEPENDS=	gsed:textproc/gsed \
		msgpuck>=2.0_6:devel/msgpuck \
		curl>=8.4.0:ftp/curl
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libicui18n.so:devel/icu \
		libmsgpuck.so:devel/msgpuck \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd

USES=		cmake:noninja compiler:c++11-lang cpe gettext-runtime gmake iconv perl5 readline ssl
USE_PERL5=	build

CONFLICTS_INSTALL=	tarantool2

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
CMAKE_ARGS=	-DCMAKE_INSTALL_FULL_SYSCONFDIR=${ETCDIR} \
		-DCMAKE_INSTALL_LOCALSTATEDIR=/var \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man
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

TT_DATADIR?=	/var/db/tarantool
TT_LOGDIR?=	/var/log/tarantool
TT_RUNDIR?=	/var/run/tarantool

post-patch:
	@${ECHO_CMD} ${PORTVERSION}-0 > ${WRKSRC}/VERSION

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/tarantool/

.include <bsd.port.mk>
