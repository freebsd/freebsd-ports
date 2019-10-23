# $FreeBSD$

PORTNAME=	nvc
DISTVERSIONPREFIX=	r
DISTVERSION=	1.4.0-33
DISTVERSIONSUFFIX=	-g2dfb3aab
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	VHDL compiler and simulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		autoreconf compiler:c++14-lang gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	nickg

GNU_CONFIGURE=	yes

LDFLAGS+=	-lexecinfo

CONFIGURE_ARGS=	--with-llvm=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT}

post-install:
	${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
