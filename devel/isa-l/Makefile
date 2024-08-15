PORTNAME=	isa-l
PORTVERSION=	2.31.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

PATCH_SITES=	https://github.com/intel/isa-l/commit/
PATCHFILES=	1b1ee1e18f5bb4d91e3839405a8557a64a3b2581.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intel(R) Intelligent Storage Acceleration Libray
WWW=		https://github.com/intel/isa-l

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64le powerpc64 powerpc

BUILD_DEPENDS=	nasm:devel/nasm # yasm fails to compiler asm modules, see https://github.com/intel/isa-l/issues/294

USE_GITHUB=	yes
GH_ACCOUNT=	intel

USES=		autoreconf gmake libtool:keepla

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
