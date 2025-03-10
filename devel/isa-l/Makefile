PORTNAME=	isa-l
PORTVERSION=	2.31.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Intel(R) Intelligent Storage Acceleration Libray
WWW=		https://github.com/intel/isa-l

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64le powerpc64 powerpc

BUILD_DEPENDS=	nasm:devel/nasm

USES=		autoreconf gmake libtool pathfix

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
TEST_TARGET=	check

USE_GITHUB=	yes
GH_ACCOUNT=	intel

.include <bsd.port.mk>
