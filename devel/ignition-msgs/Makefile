PORTNAME=	ignition-msgs
DISTVERSIONPREFIX=	gz-msgs12_
DISTVERSION=	12.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Protobuf messages and functions for robot applications
WWW=		https://ignitionrobotics.org/home

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cli11>0:devel/cli11 \
		ignition-cmake>=5:devel/ignition-cmake \
		ignition-tools>0:devel/ignition-tools
LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		libabsl_city.so:devel/abseil \
		libabsl_hash.so:devel/abseil \
		libabsl_log_internal_message.so:devel/abseil \
		libabsl_log_internal_nullguard.so:devel/abseil \
		libabsl_raw_hash_set.so:devel/abseil \
		libgz-math.so:math/ignition-math \
		libgz-utils.so:devel/ignition-utils \
		libtinyxml2.so:textproc/tinyxml2

USES=		cmake compiler:c++17-lang localbase:ldflags python:build,run ruby shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	gazebosim
GH_PROJECT=	gz-msgs

LDFLAGS+=	-labsl_city -labsl_hash -labsl_log_internal_message -labsl_log_internal_nullguard -labsl_raw_hash_set
USE_CXXSTD=	c++17

SHEBANG_FILES=	tools/gz_msgs_generate.py \
		tools/gz_msgs_generate_factory.py

PLIST_SUB=	MSGS_IGN_VER=msgs${DISTVERSION:R:R}

.include <bsd.port.mk>
