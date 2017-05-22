# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	galera
PORTVERSION=	25.3.20
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	devel@galeracluster.com
COMMENT=	Synchronous multi-master replication engine

LICENSE=	GPLv2

BUILD_DEPENDS=	checkmk:devel/check \
		${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

USES=		execinfo python:build scons ssl

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	codership
GH_TAGNAME=	release_${DISTVERSION}

LDFLAGS+=	-lboost_program_options -lboost_system
MAKE_ARGS+=	--config=force \
		deterministic_tests=1 \
		revno=${GH_TAGNAME} \
		system_asio=0

USE_RC_SUBR=	garb.sh

PLIST_FILES=	bin/garbd \
		lib/libgalera.so \
		lib/libgalera_smm.so

OPTIONS_DEFINE=	BOOSTPOOL BPOSTATIC DEBUG

BOOSTPOOL_DESC=	Use boost pool allocator
BPOSTATIC_DESC=	Use static boost_program_options

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MBOOSTPOOL}
MAKE_ARGS+=	boost_pool=1
.endif

.if ${PORT_OPTIONS:MBPOSTATIC}
MAKE_ARGS+=	bpostatic=${LOCALBASE}/lib/libboost_program_options.a
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	debug=3
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/garb/garbd ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libgalera_smm.so ${STAGEDIR}${PREFIX}/lib/
	@(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libgalera_smm.so \
		libgalera.so)

.include <bsd.port.post.mk>
