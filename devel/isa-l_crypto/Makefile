PORTNAME=	isa-l_crypto
PORTVERSION=	2.25.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Intel(R) Intelligent Storage Acceleration Library, Crypto Version
WWW=		https://github.com/intel/isa-l_crypto

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	Only amd64/aarch64 are listed in README.md, powerpc64le mentioned in v2.22

BUILD_DEPENDS=	nasm:devel/nasm

USES=		autoreconf gmake libtool

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
TEST_TARGET=	check

USE_GITHUB=	yes
GH_ACCOUNT=	intel

.include <bsd.port.mk>
