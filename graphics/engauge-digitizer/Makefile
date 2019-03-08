# $FreeBSD$

PORTNAME=	engauge-digitizer
DISTVERSIONPREFIX=	v
DISTVERSION=	10.12
CATEGORIES=	graphics math science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extract data points from images of graphs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		liblog4cpp.so:devel/log4cpp \
		libopenjp2.so:graphics/openjpeg \
		libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	markummitchell
USE_QT=		core gui printsupport sql xml widgets buildtools_build
USE_GL=		gl
CONFIGURE_ENV=	OPENJPEG_INCLUDE=${PREFIX}/include/openjpeg-2.3 OPENJPEG_LIB=${PREFIX}/lib \
		POPPLER_INCLUDE=${PREFIX}/include/poppler/qt5 POPPLER_LIB=${PREFIX}/lib
QMAKE_ARGS=	"CONFIG+=jpeg2000 pdf"

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

DOCS_USE=	QT=help,linguist_build

do-patch-NLS-on:
	@${REINPLACE_CMD} -e 's|QCoreApplication::applicationDirPath () + "/translations",|"${DATADIR}/translations",|' ${WRKSRC}/src/Translator/TranslatorContainer.cpp

post-build-NLS-on:
	@cd ${WRKSRC} && lrelease engauge.pro

post-build-DOCS-on:
	@cd ${WRKSRC}/help && ./build.bash

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/engauge ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${GZIP_CMD} < ${WRKSRC}/src/img/${PORTNAME}.svg > ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svgz
	${INSTALL_DATA} ${WRKSRC}/dev/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${STAGEDIR}${DATADIR}/translations

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/documentation/engauge.qch ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/documentation/engauge.qhc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
