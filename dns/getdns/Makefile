PORTNAME=	getdns
PORTVERSION=	1.7.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://getdnsapi.net/dist/ \
		ZI \
		http://getdnsapi.net/dist/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Modern asynchronous DNS API
WWW=		https://getdnsapi.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	check>0:devel/check

LIB_DEPENDS=	libidn2.so:dns/libidn2 \
		libunbound.so:dns/unbound
USES=		compiler:c11 pathfix ssl cmake

SOMAJVER=	10
SOVERSION=	${SOMAJVER}.2.0
MAKE_JOBS_UNSAFE=yes

PLIST_SUB+=	SOVERSION="${SOVERSION}" SOMAJVER="${SOMAJVER}"
SUB_FILES+=	pkg-message
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH:FILEPATH="${LOCALBASE}" \
		-DENABLE_STATIC:BOOL=OFF -DBUILD_LIBUV:BOOL=OFF \
		-DPATH_TRUST_ANCHOR_FILE:STRING="${LOCALBASE}/etc/unbound/root.key"

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	LIBEV LIBEVENT STUBBY
OPTIONS_DEFAULT=STUBBY

STUBBY_CMAKE_ON=	-DBUILD_STUBBY:BOOL=ON
STUBBY_DESC=		Build with stubby support
STUBBY_LIB_DEPENDS=	libyaml.so:textproc/libyaml
LIBEVENT_CMAKE_ON=	-DBUILD_LIBEVENT2:BOOL=ON
LIBEVENT_CMAKE_OFF=	-DBUILD_LIBEVENT2:BOOL=OFF
LIBEVENT_DESC=		Build with libevent support
LIBEVENT_LIB_DEPENDS=	libevent_core.so:devel/libevent
LIBEV_CMAKE_OFF=	-DBUILD_LIBEV:BOOL=OFF
LIBEV_DESC=		Build with libev support
LIBEV_LIB_DEPENDS=	libev.so:devel/libev

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	${REINPLACE_CMD} -e 's,$${RUNSTATEDIR},/var/run,' \
		${WRKSRC}/stubby/CMakeLists.txt
	${REINPLACE_CMD} -e 's,/etc/unbound/getdns-root.key,${LOCALBASE}/unbound/root.key,' \
		${WRKSRC}/src/getdns/getdns_extra.h.in
	${REINPLACE_CMD} -e 's,-Wpedantic,-Wpedantic -Wno-strict-prototypes,' \
		-e '/^\*\*\* /d' -e '/^\*\*\*\\n/d' \
		${WRKSRC}/CMakeLists.txt

post-stage-STUBBY-on:
	${MV} ${STAGEDIR}${PREFIX}/etc/stubby/stubby.yml \
		${STAGEDIR}${PREFIX}/etc/stubby/stubby.yml.sample

.include <bsd.port.post.mk>
