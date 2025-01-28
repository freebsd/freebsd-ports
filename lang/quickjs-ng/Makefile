PORTNAME=	quickjs
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	lang devel
PKGNAMESUFFIX=	-ng

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Embeddable Javascript interpreter in C (NG fork)
WWW=		https://quickjs-ng.github.io/quickjs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cmake:testing,noninja cmake cpe tar:xz
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
