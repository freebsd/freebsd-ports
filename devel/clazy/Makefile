PORTNAME=	clazy
DISTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src/

PATCH_SITES+=	https://invent.kde.org/sdk/clazy/-/commit/
PATCHFILES+=	20fca52da739ebefa47e35f6b338bb99a0da3cfe.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt oriented code checker based on clang
WWW=		https://github.com/KDE/clazy

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING-LGPL2.txt

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cmake tar:xz

CMAKE_ARGS=	-DLLVM_ROOT=${LOCALBASE}/llvm${LLVM_DEFAULT}


OPTIONS_DEFINE=	DOCS

DOCS_CMAKE_BOOL=	CLAZY_MAN_PAGE

CPP=		${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT}
CC=		${LOCALBASE}/bin/clang${LLVM_DEFAULT}
CXX=		${LOCALBASE}/bin/clang++${LLVM_DEFAULT}

.include <bsd.port.mk>
