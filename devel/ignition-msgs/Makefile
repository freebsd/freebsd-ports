PORTNAME=	ignition-msgs
DISTVERSIONPREFIX=	ignition-msgs3_
DISTVERSION=	3.2.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Protobuf messages and functions for robot applications
WWW=		https://ignitionrobotics.org/home

LICENSE=	APACHE20

BUILD_DEPENDS=	ignition-cmake>=2:devel/ignition-cmake \
		ignition-tools>0:devel/ignition-tools
LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		libabsl_city.so:devel/abseil \
		libabsl_hash.so:devel/abseil \
		libabsl_log_internal_message.so:devel/abseil \
		libabsl_log_internal_nullguard.so:devel/abseil \
		libabsl_raw_hash_set.so:devel/abseil \
		libignition-math6.so:math/ignition-math

USES=		compiler:c++17-lang cmake localbase:ldflags ruby
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	gazebosim
GH_PROJECT=	gz-msgs

LDFLAGS+=	-labsl_city -labsl_hash -labsl_log_internal_message -labsl_log_internal_nullguard -labsl_raw_hash_set
USE_CXXSTD=	c++17

PLIST_SUB=	MSGS_IGN_VER=msgs${DISTVERSION:R:R}

.include <bsd.port.mk>
