# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	vegastrike
PORTVERSION=	0.5.1.r1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.5.1/
DISTNAME=	vegastrike-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Opensource 3D space simulator

BROKEN=		Does not build with any modern compiler

RUN_DEPENDS=	${DATADIR}/vegastrike.ico:${PORTSDIR}/games/vegastrike-data
LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libogg.so:${PORTSDIR}/audio/libogg

GNU_CONFIGURE=	yes
USES=		dos2unix gmake openal:al tar:bzip2
USE_PYTHON=	yes
USE_SDL=	sdl
USE_XORG=	sm ice xi x11 xext xrender xinerama xi xrandr xcursor \
		xcomposite xdamage xfixes
USE_GL=		gl glu glut
USE_GNOME=	gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
DOS2UNIX_GLOB=	*.cpp *.h
EXTRACT_AFTER_ARGS+=--exclude boost

# cegui and ffmpeg are not used yet
CONFIGURE_ARGS=	--disable-cegui --disable-ffmpeg \
		--with-data-dir="${LOCALBASE}/share/${PORTNAME}" \
		--with-boost=system \
		--enable-flags="${CXXFLAGS}"

PLIST_FILES=	bin/vegastrike bin/vssetup bin/vegaserver

PORTDOCS=	README

OPTIONS_DEFINE=	MESHER
MESHER_DESC=	Enable mesher modelling tool

MESHER_PLIST_FILES=	bin/mesher
MESHER_LIB_DEPENDS=	libOgreMain.so:${PORTSDIR}/graphics/ogre3d
MESHER_CONFIGURE_ENABLE=	ogre

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
		s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${PLIST_FILES:S|bin|${WRKSRC}|} \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
