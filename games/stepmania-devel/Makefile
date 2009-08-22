# New ports collection makefile for:	stepmania-devel
# Date created:		16 December 2007
# Whom:			Brad Allen <braddo@tranceaddict.net>
#
# $FreeBSD$
#

PORTNAME=	stepmania
PORTVERSION=	20071121
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/OldFiles
PKGNAMESUFFIX=	-devel
DISTNAME=	StepMania-CVS-20071121-src

MAINTAINER=	braddo@tranceaddict.net
COMMENT=	Stepmania dance and rhythm game

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		m.3:${PORTSDIR}/misc/compat5x
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js

CONFLICTS=	stepmania-[0-9]*

GNU_CONFIGURE=	yes
USE_GL=		gl glu
USE_XORG=	x11 xtst xrandr xau xdmcp xext xrender
USE_ICONV=	yes
USE_GNOME=	gtk20
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include"

# Not yet implemented
#		FFMPEG		"Enable ffmpeg support"			off \

OPTIONS=	VORBIS		"Enable Ogg Vorbis support"		on  \
		THEORA		"Enable theora support"			off \

.include <bsd.port.pre.mk>

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg.6:${PORTSDIR}/audio/libogg
.else
CONFIGURE_ARGS+=--without-vorbis
.endif

.if defined(WITH_THEORA)
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
.else
CONFIGURE_ARGS+=--without-theora
.endif

.if ${OSVERSION} < 700000
BROKEN=		does not link
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lrt|-lrt -liconv|' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|@LINUX_TRUE@am__append_19|@UNIX_TRUE@am__append_19|' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|@LINUX_TRUE@am__objects_16|@UNIX_TRUE@am__objects_16|' ${WRKSRC}/src/Makefile.in

do-install:
	${MKDIR} ${PREFIX}/share/games
	${MKDIR} ${PREFIX}/share/games/stepmania
	${MKDIR} ${PREFIX}/share/games/stepmania/Announcers
	${MKDIR} ${PREFIX}/share/games/stepmania/Songs
	(cd ${WRKSRC} && ${UNZIP_CMD} -o Packages/StepMania.smzip)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "BGAnimations\
	BackgroundEffects BackgroundTransitions Characters Courses\
	Data NoteSkins Themes" ${PREFIX}/share/games/stepmania)
	${INSTALL_PROGRAM} ${WRKSRC}/src/stepmania \
	${PREFIX}/share/games/stepmania
	${INSTALL_DATA} ${WRKSRC}/src/GtkModule.so \
	${PREFIX}/share/games/stepmania

.include <bsd.port.post.mk>
