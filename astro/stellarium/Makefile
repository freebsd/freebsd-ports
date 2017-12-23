# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	stellarium
PORTVERSION=	0.17.0
DISTVERSIONPREFIX=	v
CATEGORIES=	astro
EXTRACT_ONLY=	${_DISTFILES:Nstars_*.cat:N*.pdf}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	3D photo-realistic sky renderer (planetarium)

LICENSE=	GPLv2+

CONFLICTS_INSTALL=	${PORTNAME}-qt4-0.12.*

USE_GITHUB=	yes
GH_ACCOUNT=	Stellarium

USES=		cmake gettext
USE_QT5=	qmake_build buildtools_build linguisttools_build \
		concurrent core gui network opengl printsupport widgets

CMAKE_ARGS=	-DENABLE_GPS:BOOL=OFF	# XXX: requires Qt5Positioning

GUIDE_VERSION=	0.16.1

PORTDOCS=	CREDITS.md ChangeLog README.md \
		stellarium_user_guide-${GUIDE_VERSION}-1.pdf

OPTIONS_DEFINE=		DOCS MORE_STARS MULTIMEDIA SCRIPTING TEXTURES \
			TELESCOPE
OPTIONS_DEFAULT=	MULTIMEDIA SCRIPTING TELESCOPE

MORE_STARS_DESC=	Install extra star catalogs (1.0GB)
TEXTURES_DESC=		Install better quality textures
MULTIMEDIA_DESC=	Sound and video support
SCRIPTING_DESC=		Scripting support
TELESCOPE_DESC=		Telescope control plugin

DOCS_MASTER_SITES=	SF/${PORTNAME}/Stellarium-user-guide/${GUIDE_VERSION}-1:ug
DOCS_DISTFILES=		stellarium_user_guide-${GUIDE_VERSION}-1.pdf:ug

TEXTURES_MASTER_SITES=	SF/${PORTNAME}/Extra-data-files/textures:gfx
TEXTURES_DISTFILES=	textures-1K.zip:gfx

MULTIMEDIA_USE=		QT5=multimedia
MULTIMEDIA_CMAKE_OFF=	-DENABLE_MEDIA:BOOL=OFF

TELESCOPE_USE=		QT5=serialport
TELESCOPE_CMAKE_OFF=	-DUSE_PLUGIN_TELESCOPECONTROL:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMORE_STARS}
.  for i in 4 5 6 7 8
MASTER_SITES+=	SF/${PORTNAME}/Extra-data-files/stars${i}:stars${i}
.  endfor
DISTFILES+=	stars_4_1v0_1.cat:stars4 stars_5_2v0_1.cat:stars5 \
		stars_6_2v0_1.cat:stars6 stars_7_2v0_1.cat:stars7 \
		stars_8_2v0_1.cat:stars8
PLIST_SUB+=	MORE_STARS=""
.else
PLIST_SUB+=	MORE_STARS="@comment "
.endif

.if ${PORT_OPTIONS:MSCRIPTING}
USE_QT5+=	script
PLIST_SUB+=	SCRIPTS=""
.else
CMAKE_ARGS+=	-DENABLE_SCRIPTING:BOOL=OFF
PLIST_SUB+=	SCRIPTS="@comment "
.endif

# Work-around the vestige of bzr->git conversion upstream
post-extract:
	@${MV} ${WRKSRC}/textures/earth-shadow-new.png \
		${WRKSRC}/textures/earth-shadow.png

post-extract-DOCS-on:
	@${LN} -sf ${_DISTDIR}/stellarium_user_guide-${GUIDE_VERSION}-1.pdf \
		${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's, -Wno-unused-result,,' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/<netinet\/in\.h>/ { x ; \
		s,.*,#include <sys/socket.h>, ; G ; }' \
		${WRKSRC}/src/external/libindi/libs/indibase/baseclient.cpp

post-install-MORE_STARS-on:
	${INSTALL_DATA} ${DISTDIR}/stars_[45678]_[12]v0_1.cat \
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

.include <bsd.port.mk>
