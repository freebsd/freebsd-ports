PORTNAME=	aws-checksums
PORTVERSION=	0.1.12
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Cross-Platform HW accelerated CRC32c and CRC32

LICENSE=	APACHE20

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_LIBDIR=${LOCALBASE}/lib

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

# clang is crashing on CURRENT due an assertion
# see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=234232
# and https://bugs.llvm.org/show_bug.cgi?id=40985
.if ${OSVERSION} >= 1300000
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
