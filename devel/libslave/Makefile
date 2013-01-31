# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	libslave
PORTVERSION=	0.0.${DATE}
PORTREVISION=	1
CATEGORIES=	devel databases
MASTER_SITES=	GH GHC

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Mysql replication client library, embeddable into your C++ application

LICENSE=	GPLv3

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

DATE=		20121210
USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_MYSQL=	client
USE_GITHUB=	yes
GH_ACCOUNT=	Begun
GH_COMMIT=	64d548b
GH_TAGNAME=	master
PORTEXAMPLES=	*

OPTIONS_DEFINE=	STATIC TEST EXAMPLES
STATIC_DESC=	Build static lib
TEST_DESC=	Build test binary

OPTIONS_DEFAULT=STATIC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
PLIST_SUB+=	STATIC=""
CMAKE_ARGS+=	-DENABLE_STATIC=ON
.else
CMAKE_ARGS+=	-DENABLE_STATIC=OFF
PLIST_SUB+=	STATIC="@comment "
.endif

.if ${PORT_OPTIONS:MTEST}
PLIST_SUB+=	TEST=""
CMAKE_ARGS+=	-DENABLE_TEST=ON
.else
CMAKE_ARGS+=	-DENABLE_TEST=OFF
PLIST_SUB+=	TEST="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} test ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
