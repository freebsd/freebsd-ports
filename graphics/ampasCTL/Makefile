# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	ampasCTL
PORTVERSION=	1.5.2
PORTREVISION=	6
CATEGORIES=	graphics devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Color Transformation Language interpreter

LICENSE=	AMPAS
LICENSE_NAME=	AMPAS
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libImath.so:graphics/ilmbase \
		libIlmImf.so:graphics/openexr \
		libtiff.so:graphics/tiff \
		libAcesContainer.so:graphics/ampasACES-container

USES=		compiler:c++11-lang cmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	ampas
GH_PROJECT=	CTL
GH_TAGNAME=	57b48a2

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*
DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS CHANGELOG README.md
DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	CtlManual.pdf CtlManual.doc

post-patch:
	@${REINPLACE_CMD} -e 's|lib/CMake|lib/cmake|' \
		-e 's|add_subdirectory(doc)||' \
		${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
