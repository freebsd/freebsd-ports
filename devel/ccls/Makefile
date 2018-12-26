# $FreeBSD$

PORTNAME=	ccls
DISTVERSION=	0.20181225
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	C/C++/ObjC language server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} \
		rapidjson>=1.1.0_4:devel/rapidjson
LIB_DEPENDS=	libLLVM-${LLVM_DEFAULT:C/[0-9]$//}.so:devel/llvm${LLVM_DEFAULT}

USES=		cmake compiler:c++17-lang localbase
USE_GITHUB=	yes
GH_ACCOUNT=	MaskRay
# Upstream likes to retag things.  This is the commit that matches
# the 0.20181225 tag at the moment:
#GH_TAGNAME=	98a1cf17f1e8c8fd15448a59e0caabeef39cebe

CMAKE_ARGS=	-DCLANG_ROOT:String="${LOCALBASE}/llvm${LLVM_DEFAULT}"
CMAKE_ON=	SYSTEM_CLANG USE_SHARED_LLVM

PLIST_FILES=	bin/ccls

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=		MaskRay-ccls.wiki-20181210.tar.gz:docs
DOCS_MASTER_SITES=	LOCAL/tobik:docs
PORTDOCS=		*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/ccls.wiki && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
