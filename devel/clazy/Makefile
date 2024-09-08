PORTNAME=	clazy
DISTVERSION=	1.12
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt oriented code checker based on clang
WWW=		https://github.com/KDE/clazy

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.0-or-later.txt

USES=		cmake llvm:build,run tar:xz

CMAKE_ARGS=	-DLLVM_ROOT=${LLVM_PREFIX}

OPTIONS_DEFINE=	DOCS

DOCS_CMAKE_BOOL=	CLAZY_MAN_PAGE

.include <bsd.port.mk>
