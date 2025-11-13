PORTNAME=	fritzing
PORTVERSION=	1.0.6
CATEGORIES=	cad

MAINTAINER=	kenrap@kennethraplee.com
COMMENT=	CAD for printed circuit boards
WWW=		https://fritzing.org/

LICENSE=	GPLv2+

IGNORE_FreeBSD_13=	Requires OpenSSL >= 3

BUILD_DEPENDS=	boost-libs>1.52:devel/boost-libs \
		svgpp>0:graphics/svgpp

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libngspice.so:cad/ngspice_rework@shlib \
		libpolyclipping.so:graphics/polyclipping \
		libquazip1-qt6.so:archivers/quazip@qt6

USES=		compiler:c++17-lang desktop-file-utils gl gmake pkgconfig \
		qmake qt:6 shared-mime-info ssl xorg

USE_GITHUB=	yes
GH_PROJECT=	fritzing-app \
		fritzing-parts:parts
GH_TAGNAME=	04e5bb0241e8f1de24d0fce9be070041c6d5b68e \
		12761296fc8bcc53ed481b78e3a99c907d85b18d:parts

USE_CXXSTD=	c++17
USE_GL=		egl gl opengl
USE_QT=		base serialport svg tools
USE_XORG=	x11 xau xcb xdmcp

post-extract:
	cd ${WRKSRC_parts};\
		${MKDIR} parts;${MV} -f * parts 2> /dev/null || true;\

post-patch:
	${REINPLACE_CMD} -e '/CONFIG += debug_and_release/d' ${WRKSRC}/phoenix.pro
	${REINPLACE_CMD} -e 's|QT_MOST=.*|QT_MOST=${QT6_VERSION}|' ${WRKSRC}/phoenix.pro
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${FILESDIR}/pri_quazipdetect.pri > ${WRKSRC}/pri/quazipdetect.pri
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${FILESDIR}/pri_spicedetect.pri > ${WRKSRC}/pri/spicedetect.pri
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${FILESDIR}/pri_clipper1detect.pri > ${WRKSRC}/pri/clipper1detect.pri

post-install:
	cd ${WRKSRC_parts}; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${RM} -r ${STAGEDIR}${DATADIR}/.github
	${STAGEDIR}${PREFIX}/bin/Fritzing \
		-db ${STAGEDIR}${DATADIR}/parts/parts.db \
		-pp ${STAGEDIR}${DATADIR}/parts \
		-f  ${STAGEDIR}${DATADIR} \
		-platform offscreen

.include <bsd.port.mk>
