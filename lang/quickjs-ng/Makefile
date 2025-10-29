PORTNAME=	quickjs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	lang devel
PKGNAMESUFFIX=	-ng

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Embeddable Javascript interpreter in C (NG fork)
WWW=		https://quickjs-ng.github.io/quickjs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing,noninja compiler:c11 cpe
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	quickjs-ng

CPE_VENDOR=	${PORTNAME}_project

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_TARGET=	run-test262

CONFLICTS=	quickjs

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
