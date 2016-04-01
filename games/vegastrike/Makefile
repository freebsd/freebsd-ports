# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	vegastrike
PORTVERSION=	0.5.1.r1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source 3D space simulator

LICENSE=	GPLv2

RUN_DEPENDS=	${DATADIR}/vegastrike.ico:games/vegastrike-data
LIB_DEPENDS=	libboost_python.so:devel/boost-python-libs \
		libexpat.so:textproc/expat2 \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		dos2unix gmake openal:al pkgconfig python tar:bzip2
GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_GL=		glut
USE_XORG=	sm ice xi x11 xext xrender xinerama xi xrandr xcursor \
		xcomposite xdamage xfixes
USE_GNOME=	gtk20
DOS2UNIX_GLOB=	*.cpp *.h
EXTRACT_AFTER_ARGS=	--exclude boost

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# cegui and ffmpeg are not used yet
CONFIGURE_ARGS=	--disable-cegui --disable-ffmpeg \
		--with-data-dir="${LOCALBASE}/share/${PORTNAME}" \
		--with-boost=system \
		--enable-flags="${CXXFLAGS}"

BIN_FILES=	bin/vegastrike bin/vssetup bin/vegaserver
PLIST_FILES=	${BIN_FILES}
PORTDOCS=	README

OPTIONS_DEFINE=	MESHER
MESHER_DESC=	Enable mesher modelling tool

MESHER_PLIST_FILES=	bin/mesher
MESHER_LIB_DEPENDS=	libOgreMain.so:graphics/ogre3d
MESHER_CONFIGURE_ENABLE=	ogre

post-patch:
	@${REINPLACE_CMD} -E 's,/usr/(local|X11R6),${LOCALBASE},' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${BIN_FILES:S|bin|${WRKSRC}|} \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
