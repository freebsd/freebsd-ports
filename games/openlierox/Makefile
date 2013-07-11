# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openlierox
DISTVERSION=	0.59_beta10
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/OpenLieroX%20${DISTVERSION:C/_/%20/}
DISTNAME=	OpenLieroX_${DISTVERSION}.src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Extremely addictive realtime worms shoot-em-up

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		boost_signals:${PORTSDIR}/devel/boost-libs \
		curl:${PORTSDIR}/ftp/curl \
   		alut.1:${PORTSDIR}/audio/freealut

USE_BZIP2=	yes
USE_SDL=	sdl image
USE_GNOME=	libxml2
MAKE_JOBS_SAFE=	yes
USE_OPENAL=	yes
USE_GCC=	4.6+

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		cmake
CMAKE_ARGS=	-DHAWKNL_BUILTIN=YES \
		-DLIBZIP_BUILTIN=YES \
		-DBREAKPAD=NO \
		-DSYSTEM_DATA_DIR="${DATADIR}" \
		-DHASBFD=NO

WRKSRC=		${WRKDIR}/OpenLieroX

PORTDOCS=	*
PORTDATA=	*

PLIST_FILES=	bin/openlierox \
		share/applications/openlierox-openlierox.desktop \
		share/pixmaps/OpenLieroX.svg
PLIST_DIRSTRY=	share/applications

OPTIONS_DEFINE=	DEDICATED_ONLY DOCS
DEDICATED_ONLY_DESC=Build dedicated server only

.include <bsd.port.options.mk>

.if ${OSVERSION} < 700000
IGNORE=		does not build on 7.x
.endif

.if ${PORT_OPTIONS:MDEDICATED_ONLY}
BROKEN=		does not build
CMAKE_ARGS+=	-DDEDICATED_ONLY=YES
.else
USE_XORG+=	x11
USE_SDL+=	mixer
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|boost_signals-mt|boost_signals boost_system|; \
		s|EXEC_PROGRAM.*OLXVER)|SET(OLXVER "${DISTVERSION}")|; \
		s|/usr/local|${LOCALBASE}|' ${WRKSRC}/CMakeOlxCommon.cmake
	@${FIND} ${WRKSRC} \( -name "*.cpp" -o -name "*.h" -o -name "*.cc" \) -print0 | ${XARGS} -0 -n1 \
		${REINPLACE_CMD} -e '/include.*curl\/types.h/ d'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/openlierox ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/share/openlierox-openlierox.desktop \
		${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/share/OpenLieroX.svg \
		${PREFIX}/share/pixmaps/
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/share/gamedir && ${COPYTREE_SHARE} . ${DATADIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.mk>
