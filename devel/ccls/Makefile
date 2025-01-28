PORTNAME=	ccls
DISTVERSION=	0.20240202
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	88e382f8a3d107383764310624ac61f237fdfa06.patch:-p1 # Adapt llvmorg-19-init-1720-gda95d926f6fc: InclusionDirective
PATCHFILES+=	559b4164096d026a73604055e5014361faf70a10.patch:-p1 # Adapt llvmorg-19-init-9119-g4ec9a662d388: startswith/endswith removal
PATCHFILES+=	e5e101253a07e9f40f6ea54024a9a454978f6a58.patch:-p1 # Adapt llvmorg-19-init-9465-g39adc8f42329: BuiltinType::ArraySection
PATCHFILES+=	4331c8958698d42933bf4e132f8a7d61f3cedb8c.patch:-p1 # Adapt llvmorg-20-init-12964-gdf9a14d7bbf1: createDiagnostics

MAINTAINER=	khng@FreeBSD.org
COMMENT=	C/C++/ObjC language server
WWW=		https://github.com/MaskRay/ccls

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rapidjson>=1.1.0_4:devel/rapidjson

USES=		cmake compiler:c++17-lang llvm:lib localbase
USE_GITHUB=	yes
GH_ACCOUNT=	MaskRay
GH_TAGNAME=	${DISTVERSION}

CMAKE_ARGS=	-DCCLS_VERSION:STRING="${DISTVERSION}" \
		-DClang_DIR:PATH="${LLVM_PREFIX}/lib/cmake/clang" \
		-DLLVM_DIR:PATH="${LLVM_PREFIX}/lib/cmake/llvm"
CXXFLAGS+=	-DNDEBUG

PLIST_FILES=	bin/ccls
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_MASTER_SITES=	LOCAL/khng:docs
DOCS_DISTFILES=		ccls.wiki-${DISTVERSION}.tar.gz:docs

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/ccls.wiki && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.if defined(MAINTAINER_MODE)
MAINTAINER_DISTFILE=	\
	${_DISTDIR:S|/$||}/${DOCS_DISTFILES:Mccls.wiki-*.tar.gz\:*:C|\:.*$||}

maintainer-docs-fetch:
	@${MAKE} clean
	@${MKDIR} ${WRKDIR}/ccls.wiki
	@git clone https://github.com/MaskRay/ccls.wiki.git \
		${WRKDIR}/ccls.wiki
	@${TAR} -zcf ${MAINTAINER_DISTFILE} -C ${WRKDIR} \
		--uid 0 --gid 0 --exclude-vcs ccls.wiki
	@${MAKE} makesum
	@${MAKE} clean

${MAINTAINER_DISTFILE}: maintainer-docs-fetch

maintainer-docs-distfiles: ${MAINTAINER_DISTFILE}
	scp ${MAINTAINER_DISTFILE} \
	    freefall.freebsd.org:public_distfiles/
.endif

.include <bsd.port.mk>
