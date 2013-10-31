# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	ampasCTL
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	graphics devel

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Color Transformation Language interpreter

LICENSE=	BSD

CONFLICTS=	openexr_ctl-1.[0-4].*

LIB_DEPENDS=	libImath.so:${PORTSDIR}/graphics/ilmbase \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libAcesContainer.so:${PORTSDIR}/graphics/ampasACES-container

USE_GITHUB=	yes
GH_ACCOUNT=	ampas
GH_PROJECT=	CTL
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9cb69b8

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS CHANGELOG README.md

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	CtlManual.pdf CtlManual.doc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|#include <alloca.h>||' \
		${WRKSRC}/lib/dpx/dpx_util.cc ${WRKSRC}/lib/IlmCtl/CtlExc.cpp \
		${WRKSRC}/lib/IlmCtl/CtlTypeStorage.cpp ${WRKSRC}/ctlrender/tiff_file.cc

	@${REINPLACE_CMD} -e 's|lib/CMake|lib/cmake|' \
		-e 's|add_subdirectory(doc)||' \
		-e 's|lib/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/OpenEXR_CTL/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
