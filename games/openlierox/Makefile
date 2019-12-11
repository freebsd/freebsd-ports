# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openlierox
DISTVERSION=	0.58_rc5
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/OpenLieroX%20${DISTVERSION:C/_/%20/}
DISTNAME=	OpenLieroX_${DISTVERSION}.src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Extremely addictive realtime worms shoot-em-up

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake:insource compiler:c++11-lang gnome localbase pkgconfig \
		sdl tar:bzip2
USE_SDL=	sdl image
USE_GNOME=	libxml2

CMAKE_ARGS=	-DHAWKNL_BUILTIN=YES \
		-DLIBZIP_BUILTIN=YES \
		-DBREAKPAD=NO \
		-DSYSTEM_DATA_DIR="${DATADIR}" \
		-DHASBFD=NO

WRKSRC=		${WRKDIR}/OpenLieroX

# 0.59 versions are unstable
PORTSCOUT=	skipv:0.59_beta1,0.59_beta2,0.59_beta3,0.59_beta4,0.59_beta5,0.59_beta6,0.59_beta7,0.59_beta8,0.59_beta9,0.59_beta10

PORTDOCS=	*
PORTDATA=	*

PLIST_FILES=	bin/openlierox \
		share/applications/openlierox-openlierox.desktop \
		share/pixmaps/OpenLieroX.svg

OPTIONS_DEFINE=	DEDICATED_ONLY DOCS

DEDICATED_ONLY_DESC=		Build dedicated server only
DEDICATED_ONLY_CMAKE_BOOL=	DEDICATED_ONLY
DEDICATED_ONLY_USES_OFF=	xorg
DEDICATED_ONLY_USE_OFF=		XORG=x11 SDL=mixer
DEDICATED_ONLY_LIB_DEPENDS_OFF=	libgd.so:graphics/gd

post-patch:
	@${REINPLACE_CMD} -e 's|EXEC_PROGRAM.*OLXVER)|SET(OLXVER "${DISTVERSION}")|; \
		s|/usr/local|${LOCALBASE}|' ${WRKSRC}/CMakeOlxCommon.cmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/openlierox ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/share/openlierox-openlierox.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/share/OpenLieroX.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	@cd ${WRKSRC}/share/gamedir && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/OpenLieroX

do-install-DOCS-on:
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
