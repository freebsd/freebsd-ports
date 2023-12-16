PORTNAME=	ccls
DISTVERSION=	0.20231116
CATEGORIES=	devel

MAINTAINER=	khng@FreeBSD.org
COMMENT=	C/C++/ObjC language server
WWW=		https://github.com/MaskRay/ccls

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rapidjson>=1.1.0_4:devel/rapidjson

USES=		cmake compiler:c++17-lang llvm:lib localbase
USE_GITHUB=	yes
GH_ACCOUNT=	MaskRay
GH_TAGNAME=	490edc1e0220

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
