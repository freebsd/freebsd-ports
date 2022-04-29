PORTNAME=	fccf
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Command-line tool that quickly searches through C/C++

LICENSE=	MIT

BUILD_DEPENDS+=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	p-ranav

post-patch:
	${REINPLACE_CMD} "s/llvm-config/llvm-config${LLVM_DEFAULT}/g" ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
