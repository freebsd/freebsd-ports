# New ports collection makefile for:	vice
# Date created:		Mar 28, 1998
# Whom:			dchapes@ddm.on.ca
#
# $FreeBSD$

PORTNAME=	vice
PORTVERSION=	2.3
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://www.zimmers.net/anonftp/pub/cbm/crossplatform/emulators/VICE/ \
		ftp://ftp.zimmers.net/pub/cbm/crossplatform/emulators/VICE/
PKGNAMESUFFIX?=	${GNOME_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulator for Commodore C64, C128, VIC20, PET, and CBM-II

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		gif:${PORTSDIR}/graphics/giflib \
		mp3lame:${PORTSDIR}/audio/lame
.if defined(VICE_WITH_XAW3D)
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

RESTRICTED=	"ROMs are copyrighted by Commodore Business Machines"
LICENSE=	GPLv2

USE_XORG=	xpm ice sm xext xv xt x11 xmu
USE_XORG+=	xrender xinerama xi xrandr xcursor xcomposite xdamage xfixes
USE_GMAKE=	yes
USE_PKGCONFIG=	yes
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
CONFIGURE_ARGS+=	--enable-fullscreen --enable-ipv6 --disable-dependency-tracking
MAN1=		vice.1 c1541.1 petcat.1
MLINKS=		vice.1 x64.1 \
		vice.1 x128.1 \
		vice.1 xvic.1 \
		vice.1 xpet.1 \
		vice.1 xplus4.1 \
		vice.1 xcbm2.1

FIX_XAW=	src/arch/unix/x11/xaw/about.c \
		src/arch/unix/x11/xaw/uicartridge.c \
		src/arch/unix/x11/xaw/uiedisk.c \
		src/arch/unix/x11/xaw/uimenu.c \
		src/arch/unix/x11/xaw/uiscreenshot.c \
		src/arch/unix/x11/xaw/uisnapshot.c \
		src/arch/unix/x11/xaw/x11ui.c \
		src/arch/unix/x11/xaw/widgets/FileSel.c \
		src/arch/unix/x11/xaw/widgets/FileSelP.h \
		src/arch/unix/x11/xaw/widgets/MultiList.h \
		src/arch/unix/x11/xaw/widgets/MultiListP.h \
		src/arch/unix/x11/xaw/widgets/ScrList.c \

.if !defined(NOPORTDOCS)
INFO=		vice
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION}<800063
LIB_DEPENDS+=		usb:${PORTSDIR}/devel/libusb
.endif

.if exists(${LOCALBASE}/bin/fc-cache)
PLIST_SUB+=		FCCACHE=""
PLIST_SUB+=		NOFCCACHE="@comment "
.else
PLIST_SUB+=		FCCACHE="@comment "
PLIST_SUB+=		NOFCCACHE=""
.endif

# will be picked up by configure
.if exists(${LOCALBASE}/include/ffmpeg/avformat.h)
LIB_DEPENDS+=		avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.endif

.if !defined(WITHOUT_NLS)
PATCH_DEPENDS+=		${LOCALBASE}/bin/iconv:${PORTSDIR}/converters/libiconv
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls --localedir=${LOCALBASE}/share/locale
# causes vice to crash:
#LDFLAGS+=		-lgettextlib
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=		sdl
CONFIGURE_ARGS+=	--with-sdlsound
CPPFLAGS+=		-I${LOCALBASE}/include/SDL
.endif

.if defined(VICE_WITH_ASOUND)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/vice.info*

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/man/vice.1
	${REINPLACE_CMD} -e "s|^localedir.*|localedir = ${LOCALBASE}/share/locale|" \
		${WRKSRC}/po/Makefile.in.in
	${REINPLACE_CMD} -e 's|lungif|lgif|g' -e 's|== "x|= "x|' \
		-e 's|"DATADIRNAME"/locale|share/locale|' \
		${WRKSRC}/configure
.for i in da.po de.po fr.po hu.po it.po nl.po pl.po sv.po tr.po
	${MV} "${WRKSRC}/po/${i}" "${WRKSRC}/po/${i}.latin"
	${LOCALBASE}/bin/iconv -f latin1 -t utf-8 < "${WRKSRC}/po/${i}.latin" > "${WRKSRC}/po/${i}"
.endfor
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's| doc||' ${WRKSRC}/Makefile.in
.endif
.if defined(NOPORTDOCS)
.if defined(VICE_WITH_XAW3D)
.for i in ${FIX_XAW}
	${REINPLACE_CMD} -e 's|X11/Xaw/|X11/Xaw3d/|' ${WRKSRC}/${i}
.endfor
.endif
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
