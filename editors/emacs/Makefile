# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}
PORTREVISION=	3
PORTEPOCH=	3
CATEGORIES=	editors ipv6
MASTER_SITES=	GNU
PKGNAMESUFFIX?= 24

PATCH_SITE_SUBDIR+=	ashish
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GNU editing macros

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_ia64=	Emacs 24.X does not currently build on ia64

CONFLICTS_INSTALL?=	emacs-nox11-[0-9]*
CONFLICTS_INSTALL+=	\
		emacs-19.* emacs21-[0-9]* emacs22-[0-9]* emacs23-[0-9]* \
		xemacs-[0-9]* xemacs-devel-[0-9]* xemacs-mule-[0-9]* \
		xemacs-devel-mule-[0-9]* \
		emacs-devel-[0-9]*

EMACS_VER=	24.5
GNU_CONFIGURE=	yes
USES=		cpe gmake localbase makeinfo ncurses pkgconfig shebangfix tar:xz
# Building with GCC 4.6+ requires it
LDFLAGS+=	${ncurses_ARGS:Mport:C/.+/-ltinfo/}
INFO_PATH=	${DATADIR_REL}/info
CPE_VENDOR=	gnu

SUB_FILES=	pkg-install sources.el
SUB_LIST+=	ARCHLIBDIR=${PREFIX}/libexec/emacs/${EMACS_VER}/${CONFIGURE_TARGET}
SUB_LIST+=	EMACS_VER=${EMACS_VER} # sources.el
SHEBANG_FILES=	lib-src/grep-changelog

CONFIGURE_ARGS=	--localstatedir=/var

PLIST_SUB=	EMACS_VER=${EMACS_VER} GNU_HOST=${CONFIGURE_TARGET}

MAKE_ENV=	LC_ALL=C

INFO=		ada-mode auth autotype bovine calc ccmode cl dbus dired-x \
		ebrowse ede ediff edt efaq eieio eintr elisp emacs-gnutls \
		emacs-mime emacs epa erc ert eshell eudc eww flymake forms \
		gnus htmlfontify idlwave ido info mairix-el message mh-e \
		newsticker nxml-mode octave-mode org pcl-cvs pgg rcirc reftex \
		remember sasl sc semantic ses sieve smtpmail speedbar srecode \
		todo-mode tramp url vip viper widget wisent woman

OPTIONS_DEFINE=	CANNA X11 ACL DBUS GCONF GIF JPEG M17N OTF PNG SOUND SOURCES SVG TIFF SCROLLBARS \
		XFT XIM XML XPM MAGICK GNUTLS GSETTINGS LTO FILENOTIFY

OPTIONS_RADIO=	X11 SOUND

CANNA_DESC=		Canna support
ACL_DESC=		ACL support
GSETTINGS_DESC=		GSettings support
SCROLLBARS_DESC=	Toolkit scroll-bars
SOUND_DESC=		Sound support
SOURCES_DESC=		Install sources
XAW_DESC=		Athena widgets
XAW3D_DESC=		Athena3D widgets
XIM_DESC=		X Input Method Support
M17N_DESC=		M17N support for text-shaping
OTF_DESC=		Opentype fonts suport
FILENOTIFY_DESC=	File notification support
LTO_DESC=		Enable link-time optimization (requires GCC 4.6+)

OPTIONS_RADIO_X11=	GTK2 GTK3 XAW XAW3D MOTIF
OPTIONS_RADIO_SOUND=	ALSA OSS

OPTIONS_DEFAULT?=	DBUS GCONF GIF GTK2 JPEG M17N OTF PNG SOURCES SVG TIFF \
			SCROLLBARS XFT XIM XML XPM MAGICK GNUTLS GSETTINGS OSS

OPTIONS_SUB=		SOURCES

CANNA_CONFIGURE_ON=	--with-canna \
			--with-canna-includes=${LOCALBASE}/include \
			--with-canna-libraries=${LOCALBASE}/lib
CANNA_PATCH_SITES=	http://distfiles.pirateparty.in/%SUBDIR%/ LOCAL
CANNA_PATCHFILES=	emacs24.4canna-20141030.diff.gz
CANNA_LIB_DEPENDS=	libcanna.so:japanese/canna-lib

SOUND_CONFIGURE_OFF=	--with-sound=no
ALSA_CONFIGURE_ON=	--with-sound=alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_IMPLIES=		SOUND
OSS_CONFIGURE_ON=	--with-sound=oss
OSS_IMPLIES=		SOUND

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_WITH=	dbus

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

XML_USE=		GNOME=libxml2
XML_CONFIGURE_WITH=	xml2

SVG_USE=		GNOME=librsvg2
SVG_CONFIGURE_WITH=	rsvg
SVG_IMPLIES=		X11

X11_CONFIGURE_WITH=	x
X11_USE=		XORG=x11
X11_USES=		desktop-file-utils
X11_VARS=		INSTALLS_ICONS=yes

GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_ON=	--with-x-toolkit=gtk2
GTK2_IMPLIES=		X11

GTK3_USE=		GNOME=gtk30
GTK3_CONFIGURE_ON=	--with-x-toolkit=gtk3
GTK3_IMPLIES=		X11

XAW3D_LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d
XAW3D_CONFIGURE_ON=	--with-x-toolkit=athena
XAW3D_IMPLIES=		X11

XAW_USE=		XORG=xaw
XAW_CONFIGURE_ON+=	--with-x-toolkit=athena --without-xaw3d
XAW_IMPLIES=		X11

MOTIF_USES=		motif
MOTIF_CONFIGURE_ON+=	--with-x-toolkit=motif
MOTIF_IMPLIES=		X11

SCROLLBARS_CONFIGURE_WITH=	toolkit-scroll-bars
SCROLLBARS_IMPLIES=	X11

JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=	jpeg
JPEG_IMPLIES=		X11

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=	tiff
TIFF_IMPLIES=		X11

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_WITH=	gif
GIF_IMPLIES=		X11

PNG_LIB_DEPENDS+=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png
PNG_IMPLIES=		X11

XPM_USE=		XORG=xpm
XPM_CONFIGURE_WITH=	xpm
XPM_IMPLIES=		X11

XFT_USE=		XORG=xft
XFT_LIB_DEPENDS=	libfreetype.so:print/freetype2
XFT_CONFIGURE_WITH=	xft
XFT_IMPLIES=		X11

M17N_LIB_DEPENDS=	libm17n.so:devel/m17n-lib
M17N_CONFIGURE_WITH=	m17n-flt
M17N_IMPLIES=		XFT

OTF_LIB_DEPENDS=	libotf.so:print/libotf
OTF_CONFIGURE_WITH=	libotf
OTF_IMPLIES=		XFT

MAGICK_LIB_DEPENDS=	libMagickCore-6.so:graphics/ImageMagick
MAGICK_CONFIGURE_WITH=	imagemagick
MAGICK_IMPLIES=		X11

GSETTINGS_USE=		gnome=glib20
GSETTINGS_CONFIGURE_WITH=	gsettings
GSETTINGS_IMPLIES=	X11 DBUS

GCONF_USE=		gnome=gconf2
GCONF_CONFIGURE_WITH=	gconf
GCONF_IMPLIES=		X11

XIM_CONFIGURE_WITH=	xim
XIM_IMPLIES=		X11

LTO_CONFIGURE_ON=	--enable-link-time-optimization
LTO_USE=		GCC=4.6+

ACL_CONFIGURE_OFF=	--disable-acl

FILENOTIFY_CONFIGURE_ON=	--with-file-notification=gfile
FILENOTIFY_CONFIGURE_OFF=	--without-file-notification
FILENOTIFY_USE=		GNOME=glib20

post-patch-X11-off:
	@${REINPLACE_CMD} -e 's/^Terminal=.*$$/Terminal=true/' ${WRKSRC}/etc/emacs.desktop

post-install:
	@${RM} -rf ${STAGEDIR}/var/games/emacs
	@${FIND} ${STAGEDIR}${PREFIX}/${INFO_PATH} -type f -name '*.gz' -exec ${GUNZIP_CMD} '{}' \;

post-install-SOURCES-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${EMACS_VER}/src
	${INSTALL_DATA} ${WRKSRC}/src/*.[ch] ${STAGEDIR}${DATADIR}/${EMACS_VER}/src
	${INSTALL_DATA} ${WRKDIR}/sources.el \
		${STAGEDIR}${DATADIR}/${EMACS_VER}/site-lisp/site-start.el

.if !defined(WITHOUT_X11)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "====> To disable X11 support, define: WITHOUT_X11."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
