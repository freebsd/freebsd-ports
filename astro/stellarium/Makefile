PORTNAME=	stellarium
PORTVERSION=	23.1
CATEGORIES=	astro
MASTER_SITES=	https://github.com/Stellarium/stellarium/releases/download/v${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${_DISTFILES:Nstars_*.cat:N*.pdf}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	3D photo-realistic sky renderer (planetarium)
WWW=		https://stellarium.org/

LICENSE=	GPLv2+

USES=		cmake compiler:c++11-lang desktop-file-utils \
		perl5 qt:5 shared-mime-info tar:xz
USE_PERL5=	build
USE_QT=		qmake:build buildtools:build \
		charts concurrent core gui network opengl \
		printsupport widgets
CMAKE_OFF=	ENABLE_QT6

GUIDE_VERSION=	${PORTVERSION}

PORTDOCS=	CREDITS.md ChangeLog README.md \
		stellarium_user_guide-${GUIDE_VERSION}-1.pdf

OPTIONS_DEFINE=		DOCS GPS MORE_STARS MULTIMEDIA NLS SCRIPTS \
			SHOWMYSKY TELESCOPE TEST TEXTURES WEBENGINE XLSX
OPTIONS_DEFAULT=	GPS MULTIMEDIA SCRIPTS SHOWMYSKY TELESCOPE \
			WEBENGINE XLSX
OPTIONS_SUB=		yes

GPS_DESC=		GPS (NMEA handling) support
MORE_STARS_DESC=	Install additional star catalogs (1.0GB)
MULTIMEDIA_DESC=	Sound and video support
SCRIPTS_DESC=		Remote control and scripting support
SHOWMYSKY_DESC=		Realistic atmosphere light scattering
TELESCOPE_DESC=		Build telescope control plugin
TEXTURES_DESC=		Install better quality textures
WEBENGINE_DESC=		Get and show extra object information
XLSX_DESC=		Data export to Excel files support

DOCS_MASTER_SITES=	https://github.com/Stellarium/stellarium/releases/download/v${GUIDE_VERSION}/:ug
DOCS_DISTFILES=		stellarium_user_guide-${GUIDE_VERSION}-1.pdf:ug

GPS_LIB_DEPENDS=	libgps.so:astro/gpsd
GPS_USE=		QT=location,serialport
GPS_CMAKE_OFF=		-DENABLE_GPS:BOOL=OFF

MULTIMEDIA_USE=		QT=multimedia
MULTIMEDIA_CMAKE_OFF=	-DENABLE_MEDIA:BOOL=OFF

NLS_USE=		QT=linguisttools:build
NLS_CMAKE_OFF=		-DENABLE_NLS:BOOL=OFF

SCRIPTS_USE=		QT=script
SCRIPTS_CMAKE_OFF=	-DENABLE_SCRIPTING:BOOL=OFF

SHOWMYSKY_BUILD_DEPENDS=	${LOCALBASE}/include/ShowMySky/AtmosphereRenderer.hpp:astro/calcmysky
SHOWMYSKY_RUN_DEPENDS=	${LOCALBASE}/lib/libShowMySky-Qt5.so:astro/calcmysky
SHOWMYSKY_CMAKE_OFF=	-DENABLE_SHOWMYSKY:BOOL=OFF

TELESCOPE_BUILD_DEPENDS=	${LOCALBASE}/lib/libindiclient.a:devel/indi
TELESCOPE_USE=		QT=serialport
TELESCOPE_CMAKE_OFF=	-DUSE_PLUGIN_TELESCOPECONTROL:BOOL=OFF

TEST_USE=		QT=testlib:build
TEST_CMAKE_ON=		-DENABLE_TESTING:BOOL=ON

TEXTURES_MASTER_SITES=	SF/${PORTNAME}/Extra-data-files/textures:gfx
TEXTURES_DISTFILES=	textures-1K.zip:gfx

WEBENGINE_USE=		QT=declarative,webchannel,webengine
WEBENGINE_CMAKE_OFF=	-DENABLE_QTWEBENGINE:BOOL=OFF

XLSX_LIB_DEPENDS=	libQXlsx.so:devel/qxlsx
XLSX_CMAKE_OFF=		-DENABLE_XLSX:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMORE_STARS}
.  for i in 4 5 6 7 8
MASTER_SITES+=	SF/${PORTNAME}/Extra-data-files/stars${i}:stars${i}
.  endfor
DISTFILES+=	stars_4_1v0_2.cat:stars4 stars_5_2v0_1.cat:stars5 \
		stars_6_2v0_1.cat:stars6 stars_7_2v0_1.cat:stars7 \
		stars_8_2v0_1.cat:stars8
.endif

post-extract-DOCS-on:
	@${LN} -sf ${_DISTDIR}/stellarium_user_guide-${GUIDE_VERSION}-1.pdf \
		${WRKSRC}

post-install:
	@${RM} -r ${STAGEDIR}${DATADIR}/guide
	@${RMDIR} ${STAGEDIR}${DATADIR}/skycultures/greek_almagest/almstars

post-install-MORE_STARS-on:
	${INSTALL_DATA} ${DISTDIR}/stars_4_1v0_2.cat \
		${DISTDIR}/stars_[5678]_2v0_1.cat \
		${STAGEDIR}${DATADIR}/stars/default

post-install-TEXTURES-on:
	(cd ${WRKDIR} && for f in *.png; do \
		new=`${STAT} -f '%z' $$f` ; \
		existing=`${STAT} -f '%z' \
			${STAGEDIR}${DATADIR}/textures/$$f` ; \
		${TEST} $$new -gt $$existing || continue ; \
		${ECHO_CMD} "-- Replacing texture: $$f\
			(has larger file size: $$new > $$existing)" ; \
		${INSTALL_DATA} $$f ${STAGEDIR}${DATADIR}/textures ; \
	done)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test-TEST-on:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
