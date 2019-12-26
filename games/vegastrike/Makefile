# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	vegastrike
PORTVERSION=	0.5.1.r1
PORTREVISION=	19
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source 3D space simulator

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		Fails to compile: POSH cannot determine target CPU

RUN_DEPENDS=	${LOCALBASE}/${DATADIR_REL}/vegastrike.ico:games/vegastrike-data
LIB_DEPENDS=	${PY_BOOST} \
		libexpat.so:textproc/expat2 \
		libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang dos2unix gl gmake gnome jpeg \
		localbase:ldflags openal:al pkgconfig python:2.7 sdl tar:bzip2 \
		xorg
USE_CXXSTD=	c++98
USE_SDL=	sdl
USE_GL=		gl glu glut
USE_XORG=	sm ice xi x11 xext xrender xinerama xi xrandr xcursor \
		xcomposite xdamage xfixes xmu
USE_GNOME=	cairo gdkpixbuf2 gtk20

GNU_CONFIGURE=	yes
DOS2UNIX_GLOB=	*.cpp *.h
EXTRACT_AFTER_ARGS=	--exclude boost
LLD_UNSAFE=	yes

# cegui and ffmpeg are not used yet
CONFIGURE_ARGS=	--disable-cegui --disable-ffmpeg \
		--with-data-dir="${LOCALBASE}/share/${PORTNAME}" \
		--with-boost=system \
		--enable-flags="${CXXFLAGS}"

BIN_FILES=	bin/vegastrike bin/vssetup bin/vegaserver
PLIST_FILES=	${BIN_FILES}
PORTDOCS=	README

OPTIONS_DEFINE=	MESHER DOCS
MESHER_DESC=	Enable mesher modelling tool

MESHER_VARS=	BIN_FILES+=bin/mesher
MESHER_LIB_DEPENDS=	libOgreMain.so:graphics/ogre3d19
MESHER_CONFIGURE_ENABLE=	ogre

post-patch:
	@${REINPLACE_CMD} -E 's,/usr/(local|X11R6),${LOCALBASE},' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/-lboost_python/-l${PY_BOOST_LIB}/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/#include <sys\/dir\.h>/d' \
		${WRKSRC}/setup/src/c/setup.cpp

do-install:
	${INSTALL_PROGRAM} ${BIN_FILES:S|bin|${WRKSRC}|} \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
