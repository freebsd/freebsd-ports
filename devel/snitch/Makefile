PORTNAME=	snitch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.5
CATEGORIES=	devel
PKGNAMESUFFIX=	-testing

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight C++20 testing framework
WWW=		https://github.com/cschreib/snitch

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++20-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cschreib

FLAVORS=	default headers_only
FLAVOR?=	${FLAVORS:[1]}
headers_only_PLIST=	${MASTERDIR}/pkg-plist-headers-only

.if ${FLAVOR} == default
CMAKE_ON=	BUILD_SHARED_LIBS
.endif

.if ${FLAVOR} == headers_only
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-headers-only
CMAKE_ON=	SNITCH_HEADER_ONLY
NO_ARCH=	yes
CONFLICTS_INSTALL=	snitch-testing # see https://github.com/cschreib/snitch/issues/125
.endif

.include <bsd.port.mk>
