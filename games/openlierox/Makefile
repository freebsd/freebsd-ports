# New ports collection makefile for:	openlierox
# Date created:		12 Oct 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openlierox
DISTVERSION=	0.59_beta9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/OpenLieroX%20${DISTVERSION:C/_/%20/}
DISTNAME=	OpenLieroX_${DISTVERSION}.src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Extremely addictive realtime worms shoot-em-up

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		boost_signals.4:${PORTSDIR}/devel/boost-libs \
		curl.6:${PORTSDIR}/ftp/curl \
   		alut.1:${PORTSDIR}/audio/freealut

USE_BZIP2=	yes
USE_SDL=	sdl image
USE_GNOME=	libxml2
MAKE_JOBS_SAFE=	yes
USE_OPENAL=	yes

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

USE_CMAKE=	yes
CMAKE_ARGS=	-DHAWKNL_BUILTIN=YES \
		-DLIBZIP_BUILTIN=YES \
		-DBREAKPAD=NO \
		-DSYSTEM_DATA_DIR="${DATADIR}"

WRKSRC=		${WRKDIR}/OpenLieroX

PORTDOCS=	*
PORTDATA=	*

PLIST_FILES=	bin/openlierox \
		share/applications/openlierox-openlierox.desktop \
		share/pixmaps/OpenLieroX.svg
PLIST_DIRSTRY=	share/applications

OPTIONS=	DEDICATED_ONLY "Build dedicated server only" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEDICATED_ONLY)
BROKEN=		does not build
CMAKE_ARGS+=	-DDEDICATED_ONLY=YES
.else
USE_XORG+=	x11
USE_SDL+=	mixer
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-mt||; s|EXEC_PROGRAM.*OLXVER)|SET(OLXVER "${DISTVERSION}")|; \
		s|/usr/local|${LOCALBASE}|' ${WRKSRC}/CMakeOlxCommon.cmake

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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
