# New ports collection makefile for:	vice
# Date created:		Mar 28, 1998
# Whom:			dchapes@ddm.on.ca
#
# $FreeBSD$

PORTNAME=	vice
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.viceteam.org/online/ \
		http://www.zimmers.net/anonftp/pub/cbm/crossplatform/emulators/VICE/ \
		ftp://ftp.zimmers.net/pub/cbm/crossplatform/emulators/VICE/
PKGNAMESUFFIX?=	${GNOME_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulator for Commodore C64, C128, VIC20, PET, and CBM-II

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png
.if defined(VICE_WITH_XAW3D)
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

RESTRICTED=	"ROMs are copyrighted by Commodore Business Machines"

USE_XORG=	xpm ice sm xext xv xt x11 xmu
USE_XORG+=	xrender xinerama xi xrandr xcursor xcomposite xdamage xfixes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV+=	MAKEINFOFLAGS="--no-split"

.if defined(VICE_WITH_XAW3D)
GNOME_SUFFIX=	-xaw3d
CONFIGURE_ARGS=	--with-xaw3d --disable-gnomeui
CONFLICTS?=	vice-gnome-1.* vice-1.*
.else
.if !defined(VICE_WITHOUT_GNOME)
GNOME_SUFFIX=	-gnome
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--enable-gnomeui
CONFLICTS?=	vice-1.* vice-xaw3d-1.*
.else
CONFIGURE_ARGS=	--without-xaw3d --disable-gnomeui
CONFLICTS?=	vice-xaw3d-1.* vice-gnome-1.*
USE_XORG+=	xaw
.endif
.endif

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAN1=		vice.1 c1541.1 petcat.1
MLINKS=		vice.1 x64.1 \
		vice.1 x128.1 \
		vice.1 xvic.1 \
		vice.1 xpet.1 \
		vice.1 xplus4.1 \
		vice.1 xcbm2.1

.if !defined(NOPORTDOCS)
INFO=		vice
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/fc-cache)
PLIST_SUB+=		FCCACHE=""
PLIST_SUB+=		NOFCCACHE="@comment "
.else
PLIST_SUB+=		FCCACHE="@comment "
PLIST_SUB+=		NOFCCACHE=""
.endif

.if exists(${LOCALBASE}/include/esd.h) && !defined(WITHOUT_ESOUND)
WITH_ESOUND?=yes
.endif

# will be picked up by configure
.if exists(${LOCALBASE}/include/ffmpeg/avformat.h)
LIB_DEPENDS+=		avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
LDFLAGS+=		-lgettextlib
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=		sdl
CONFIGURE_ARGS+=	--with-sdl
CPPFLAGS+=		-I${LOCALBASE}/include/SDL
.endif

.if defined(WITH_ESOUND)
LIB_DEPENDS+=		esd.2:${PORTSDIR}/audio/esound
CONFIGURE_ARGS+=	--with-esd
.else
CONFIGURE_ARGS+=	--without-esd
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/vice.info*

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/man/vice.1
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's| doc||' ${WRKSRC}/Makefile.in
.endif

pre-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.endif
	${MKDIR} ${PREFIX}/lib/vice/fonts
	${INSTALL_DATA} ${WRKSRC}/data/fonts/vice-cbm.bdf \
		${PREFIX}/lib/vice/fonts/

post-install:
.if !defined(NOPORTDOCS)
	@${LN} -sf vice_toc.html ${DOCSDIR}/index.html
.endif

.include <bsd.port.post.mk>
