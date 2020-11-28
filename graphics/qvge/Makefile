# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qvge
PORTVERSION=	0.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Qt Visual Graph Editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ArsMasiuk

USES=		compiler:c++11-lang desktop-file-utils gl qt:5 \
		shared-mime-info xorg
USE_GL=		gl
USE_QT=		buildtools_build qmake_build core gui network opengl \
		printsupport svg widgets x11extras xml
USE_XORG=	x11

MAKE_ARGS=	INSTALL_ROOT=${STAGEDIR}
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/qvgeapp share/appdata/qvge.appdata.xml \
		share/applications/qvge.desktop \
		share/mime/packages/application-xgr.xml \
		share/pixmaps/qvge.png
PORTDOCS=	CHANGES README.md

OPTIONS_DEFINE=	DOCS OGDF
OGDF_DESC=	Use OGDF instead of GraphViz engine

OGDF_LIB_DEPENDS=	libOGDF.so:math/ogdf
OGDF_QMAKE_ON=	CONFIG+=USE_OGDF
OGDF_QMAKE_OFF=	CONFIG+=USE_GVGRAPH
OGDF_RUN_DEPENDS_OFF=	dot:graphics/graphviz

do-configure:
	cd ${CONFIGURE_WRKSRC} && ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
