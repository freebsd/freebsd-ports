# Created by: Kenneth Vestergaard Schmidt <kvs@pil.dk>
# $FreeBSD$

PORTNAME=	emacs
DISTVERSION=	${EMACS_VER}.${EMACS_REV}
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	editors ipv6
PKGNAMESUFFIX=	-devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GNU editing macros

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	emacs25-[0-9]* emacs-nox11-[0-9]*

BROKEN_aarch64=		Fails to link: missing sbrk

USE_GITHUB=	yes
GH_ACCOUNT=	emacs-mirror
GH_TAGNAME=	5e2cf8c

EMACS_VER=	26.0.50
EMACS_REV=	20170509
GNU_CONFIGURE=	yes
USES=		autoreconf:build cpe gmake makeinfo ncurses pkgconfig
INFO_PATH=	${DATADIR_REL}/info
CPE_VENDOR=	gnu

SUB_FILES=	sources.el
SUB_LIST=	EMACS_VER=${EMACS_VER}

CONFIGURE_ARGS=	--with-gameuser=games:games

PLIST_SUB=	EMACS_VER=${EMACS_VER} GNU_HOST=${CONFIGURE_TARGET}

INFO=	ada-mode auth autotype bovine calc ccmode cl dbus dired-x ebrowse ede	\
	ediff edt efaq eieio eintr elisp emacs emacs-gnutls emacs-mime epa erc	\
	ert eshell eudc eww flymake forms gnus htmlfontify idlwave ido info	\
	mairix-el message mh-e newsticker nxml-mode octave-mode org pcl-cvs pgg	\
	rcirc reftex remember sasl sc semantic ses sieve smtpmail speedbar	\
	srecode todo-mode tramp url vhdl-mode vip viper widget wisent woman

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	ACL DBUS GNUTLS LLDB MODULES SOURCES THREADS X11 XML

OPTIONS_RADIO=			FILENOTIFY SOUND X11TOOLKIT
OPTIONS_RADIO_FILENOTIFY=	GFILE KQUEUE
OPTIONS_RADIO_SOUND=		ALSA OSS
OPTIONS_RADIO_X11TOOLKIT=	GTK2 GTK3 MOTIF XAW XAW3D
OPTIONS_GROUP=			GRAPHICS NEEDX11
OPTIONS_GROUP_GRAPHICS=		CAIRO GIF JPEG MAGICK PNG SVG TIFF XPM
OPTIONS_GROUP_NEEDX11=		GCONF GSETTINGS M17N OTF SCROLLBARS XFT XIM     \
				XWIDGETS

OPTIONS_DEFAULT=	ACL DBUS FREEDESKTOP GCONF GIF GNUTLS GSETTINGS GTK2    \
			JPEG KQUEUE M17N MAGICK MODULES OSS OTF PNG SCROLLBARS  \
			SOURCES SVG THREADS TIFF X11 XFT XIM XML XPM

ACL_DESC=	Access control list support
CAIRO_DESC=	Experimental Cairo support    (implies PNG, XFT)
FILENOTIFY_DESC=File notification support
GCONF_DESC=	GConf configuration support
GFILE_DESC=	File notification via gfile
GRAPHICS_DESC=	Graphics support (each implies X11)
GSETTINGS_DESC=	GSettings support             (implies DBUS)
KQUEUE_DESC=	File notification via kqueue
LLDB_DESC=	Enable LLDB support for GUD
#LTO_DESC=	Enable link-time optimization
MAGICK_DESC=	ImageMagick support
M17N_DESC=	M17N support for text-shaping (implies XFT)
MODULES_DESC=	Dynamic modules support
NEEDX11_DESC=	Other X11-dependent (each implies X11)
OTF_DESC=	Opentype fonts support        (implies XFT)
SCROLLBARS_DESC=Toolkit scroll-bars
SOURCES_DESC=	Install sources
SVG_DESC=	SVG support (implies PNG)
THREADS_DESC=	Emacs Lisp threading support
X11_DESC=	X11 support
X11TOOLKIT_DESC=X11 toolkit (each implies X11)
XAW3D_DESC=	Athena3D widgets
XAW_DESC=	Athena widgets
XIM_DESC=	X Input Method Support
XWIDGETS_DESC=	GTK widgets in Emacs buffers  (requires GTK3)

OPTIONS_SUB=		YES

ACL_CONFIGURE_ENABLE=	acl
ALSA_CONFIGURE_ON=	--with-sound=alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
CAIRO_USE=		GNOME=cairo
CAIRO_CONFIGURE_WITH=	cairo
CAIRO_IMPLIES=		PNG XFT X11
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_WITH=	dbus
GCONF_USE=		GNOME=gconf2
GCONF_CONFIGURE_WITH=	gconf
GCONF_IMPLIES=		X11
GFILE_CONFIGURE_ON=	--with-file-notification=gfile
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_WITH=	gif
GIF_IMPLIES=		X11
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls
GSETTINGS_USE=		GNOME=glib20
GSETTINGS_CONFIGURE_WITH=gsettings
GSETTINGS_IMPLIES=	DBUS X11
GTK2_USE=		GNOME=cairo,gtk20
GTK2_USES=		gettext
GTK2_CONFIGURE_ON=	--with-x-toolkit=gtk2
GTK2_IMPLIES=		X11
GTK2_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libfontconfig.so:x11-fonts/fontconfig
GTK3_USE=		GNOME=cairo,gtk30
GTK3_USES=		gettext
GTK3_CONFIGURE_ON=	--with-x-toolkit=gtk3
GTK3_IMPLIES=		X11
JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=	jpeg
JPEG_IMPLIES=		X11
KQUEUE_CONFIGURE_ON=	--with-file-notification=kqueue
LLDB_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-lldb-gud.el
#LTO_CONFIGURE_ON=	--enable-link-time-optimization
M17N_LIB_DEPENDS=	libm17n.so:devel/m17n-lib
M17N_CONFIGURE_WITH=	m17n-flt
M17N_IMPLIES=		XFT X11
MAGICK_LIB_DEPENDS=	libMagickCore-6.so:graphics/ImageMagick
MAGICK_CONFIGURE_WITH=	imagemagick
MAGICK_IMPLIES=		X11
MODULES_CONFIGURE_WITH=	modules
MOTIF_USES=		motif
MOTIF_CONFIGURE_ON=	--with-x-toolkit=motif
MOTIF_IMPLIES=		X11
MOTIF_LIB_DEPENDS=	libXp.so:x11/libXp
OSS_CONFIGURE_ON=	--with-sound=oss
OTF_LIB_DEPENDS=	libotf.so:print/libotf
OTF_CONFIGURE_WITH=	libotf
OTF_IMPLIES=		X11 XFT
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png
PNG_IMPLIES=		X11
SCROLLBARS_CONFIGURE_WITH=toolkit-scroll-bars
SCROLLBARS_IMPLIES=	X11
SVG_USE=		GNOME=cairo,librsvg2
SVG_CONFIGURE_WITH=	rsvg
SVG_IMPLIES=		X11 PNG
SVG_USES=		gettext
THREADS_CONFIGURE_WITH=	threads
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=	tiff
TIFF_IMPLIES=		X11
X11_CONFIGURE_OFF=	--without-x --with-x-toolkit=no
X11_CONFIGURE_ON=	--with-x
X11_USE=		XORG=ice,sm,x11,xcb,xext,xfixes,xinerama,xmu,xrandr,xt
X11_USES=		desktop-file-utils
X11_VARS=		installs_icons=yes
X11_VARS_OFF=		without_x11=yes
XAW_USE=		XORG=xaw
XAW_CONFIGURE_ON=	--with-x-toolkit=athena --without-xaw3d
XAW_IMPLIES=		X11
XAW3D_LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d
XAW3D_CONFIGURE_ON=	--with-x-toolkit=athena
XAW3D_IMPLIES=		X11
XFT_USE=		XORG=xft,xrender
XFT_CONFIGURE_WITH=	xft
XFT_IMPLIES=		X11
XFT_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
XIM_CONFIGURE_WITH=	xim
XIM_IMPLIES=		X11
XML_USE=		GNOME=libxml2
XML_CONFIGURE_WITH=	xml2
XPM_USE=		XORG=xpm
XPM_CONFIGURE_WITH=	xpm
XPM_IMPLIES=		X11
XWIDGETS_USE=		XORG=xcomposite
XWIDGETS_CONFIGURE_WITH=xwidgets
XWIDGETS_LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3
XWIDGETS_IMPLIES=	GTK3

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh all)

# With a desktop entry stage-qa will give a warning about requiring
# desktop-file-utils and portlint -C will give a warning about INSTALL_ICONS,
# but don't pull in those dependencies when X11 is off.
post-patch-X11-off:
	@${REINPLACE_CMD} -e 's/^Terminal=.*$$/Terminal=true/' \
		${WRKSRC}/etc/emacs.desktop

post-install-SOURCES-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${EMACS_VER}/src
	${INSTALL_DATA} ${WRKSRC}/src/*.[ch] ${STAGEDIR}${DATADIR}/${EMACS_VER}/src
	${INSTALL_DATA} ${WRKDIR}/sources.el ${STAGEDIR}${DATADIR}/${EMACS_VER}/site-lisp/site-start.el

.include <bsd.port.mk>
