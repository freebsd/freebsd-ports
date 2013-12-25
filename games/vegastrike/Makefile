# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	vegastrike
PORTVERSION=	0.5.1.r1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.5.1/
DISTNAME=	vegastrike-src-${PORTVERSION}

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Opensource 3D space simulator

RUN_DEPENDS=	${DATADIR}/vegastrike.ico:${PORTSDIR}/games/vegastrike-data
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg:${PORTSDIR}/audio/libogg

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake openal:al
USE_PYTHON=	yes
USE_SDL=	sdl
USE_XORG=	sm ice xi x11 xext xrender xinerama xi xrandr xcursor \
		xcomposite xdamage xfixes
USE_GL=		gl glu glut
USE_GNOME=	gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# cegui and ffmpeg are not used yet
CONFIGURE_ARGS=	--disable-cegui --disable-ffmpeg \
		--with-data-dir="${LOCALBASE}/share/${PORTNAME}" \
		--enable-flags="${CXXFLAGS}"

PLIST_FILES=	bin/vegastrike bin/vssetup bin/vegaserver

PORTDOCS=	README

OPTIONS_DEFINE=	MESHER
MESHER_DESC=	Enable mesher modelling tool

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		fails to build on 7.x
.endif

.if ${PORT_OPTIONS:MMESHER}
PLIST_FILES+=	bin/mesher
BUILD_DEPENDS+=		${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d
RUN_DEPENDS+=		${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d
.else
CONFIGURE_ARGS+=	--disable-ogre
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
		s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vegaserver ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vegastrike ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vssetup ${PREFIX}/bin
.if ${PORT_OPTIONS:MMESHER}
	${INSTALL_PROGRAM} ${WRKSRC}/mesher ${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
