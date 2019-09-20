# $FreeBSD$

PORTNAME=	clazy
DISTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt oriented code checker based on clang

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING-LGPL2.txt

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cmake compiler:c++11-lang tar:xz

CMAKE_ARGS=	-DLLVM_ROOT=${LOCALBASE}/llvm${LLVM_DEFAULT}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
