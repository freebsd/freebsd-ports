PORTNAME=	engauge-digitizer
DISTVERSIONPREFIX=	v
DISTVERSION=	12.9.1
PORTREVISION=	1
CATEGORIES=	graphics math science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extract data points from images of graphs
WWW=		https://markummitchell.github.io/engauge-digitizer/ \
		https://github.com/akhuettel/engauge-digitizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		liblog4cpp.so:devel/log4cpp \
		libopenjp2.so:graphics/openjpeg \
		libpoppler-qt6.so:graphics/poppler-qt6

USES=		compiler:c++11-lang desktop-file-utils gl pkgconfig qmake qt:6 # pkgconfig is for https://github.com/markummitchell/engauge-digitizer/issues/423
USE_QT=		base tools
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	akhuettel

CONFIGURE_ENV=	OPENJPEG_INCLUDE=${PREFIX}/include/openjpeg-2.4 OPENJPEG_LIB=${PREFIX}/lib \
		POPPLER_INCLUDE=${PREFIX}/include/poppler/qt6 POPPLER_LIB=${PREFIX}/lib
QMAKE_ARGS=	"CONFIG+=jpeg2000 pdf"

CXXFLAGS+=	`pkg-config --cflags libopenjp2` # workaround for https://github.com/markummitchell/engauge-digitizer/issues/423

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

#DOCS_USE=	QT=help,linguist:build

do-patch-NLS-on:
	@${REINPLACE_CMD} -e 's|QCoreApplication::applicationDirPath () + "/translations",|"${DATADIR}/translations",|' ${WRKSRC}/src/Translator/TranslatorContainer.cpp

post-build-NLS-on:
	@cd ${WRKSRC} && ${LRELEASE} engauge.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Engauge ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${GZIP_CMD} < ${WRKSRC}/src/img/${PORTNAME}.svg > ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svgz
	${INSTALL_DATA} ${WRKSRC}/dev/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${STAGEDIR}${DATADIR}/translations

.include <bsd.port.mk>
