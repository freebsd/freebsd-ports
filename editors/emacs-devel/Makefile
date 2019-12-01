# Created by: Kenneth Vestergaard Schmidt <kvs@pil.dk>
# $FreeBSD$

PORTNAME=	emacs
DISTVERSION=	27.0.50.20191201
PORTEPOCH=	2
CATEGORIES=	editors
PKGNAMESUFFIX=	-devel

MAINTAINER=	emacs@FreeBSD.org
COMMENT=	GNU editing macros
.if ${FLAVOR:U} == nox
COMMENT+=	(No X flavor)
.endif

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	texinfo>=6.5,1:print/texinfo
LIB_DEPENDS=	libgmp.so:math/gmp

FLAVORS=		full nox
full_CONFLICTS_INSTALL=	emacs-devel-nox
nox_PKGNAMESUFFIX=	-devel-nox
nox_CONFLICTS_INSTALL=	emacs-devel

USES=		autoreconf:build cpe gmake localbase:ldflags ncurses pkgconfig
CPE_VENDOR=	gnu
USE_GITHUB=	yes
GH_ACCOUNT=	emacs-mirror
GH_TAGNAME=	293eb32
.if ${FLAVOR:U} != nox
USES+=		desktop-file-utils gnome xorg
INSTALLS_ICONS=	yes
USE_XORG=	ice sm x11 xcb xext xfixes xinerama xmu xrandr xrender xt
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-build-details \
			--localstatedir=/var
.if ${FLAVOR:U} == nox
CONFIGURE_ARGS+=	--with-sound=no \
			--with-x-toolkit=no \
			--without-cairo \
			--without-dbus \
			--without-gconf \
			--without-gif \
			--without-gsettings \
			--without-imagemagick \
			--without-jpeg \
			--without-lcms2 \
			--without-libotf \
			--without-m17n-flt \
			--without-png \
			--without-rsvg \
			--without-tiff \
			--without-toolkit-scroll-bars \
			--without-x \
			--without-xim \
			--without-xpm \
			--without-xwidgets
.else
CONFIGURE_ARGS+=	--with-x
.endif
# See r468320 to determine if/when the next line can be removed
CONFIGURE_ENV=		ac_cv_header_sys_sysinfo_h=no

CONFLICTS_INSTALL=	emacs emacs-canna emacs-nox

SUB_FILES=	sources.el
SUB_LIST=	EMACS_VER=${DISTVERSION:R}

INFO=		auth autotype bovine calc ccmode cl dbus dired-x ebrowse ede \
		ediff edt efaq eieio eintr elisp emacs emacs-gnutls emacs-mime \
		epa erc ert eshell eudc eww flymake forms gnus htmlfontify \
		idlwave ido info mairix-el message mh-e newsticker nxml-mode \
		octave-mode org pcl-cvs pgg rcirc reftex remember sasl sc \
		semantic ses sieve smtpmail speedbar srecode todo-mode tramp \
		url vhdl-mode vip viper widget wisent woman
INFO_PATH=	${DATADIR_REL}/info
PLIST_SUB=	EMACS_VER=${DISTVERSION:R} \
		GNU_HOST=${CONFIGURE_TARGET}

OPTIONS_DEFINE=			ACL DBUS GCONF GNUTLS GSETTINGS HARFBUZZ JSON \
				LCMS2 M17N MAILUTILS MODULES OTF SCROLLBARS \
				SOURCES THREADS XFT XIM XML XWIDGETS
OPTIONS_DEFAULT=		ACL CAIRO DBUS GIF GNUTLS GSETTINGS GTK3 \
				HARFBUZZ JPEG JSON KQUEUE LCMS2 M17N MAGICK \
				MAILUTILS MODULES OSS OTF PNG SCROLLBARS \
				SOURCES SVG THREADS TIFF XFT XIM XML XPM
OPTIONS_GROUP=			GRAPHICS
OPTIONS_GROUP_GRAPHICS=		CAIRO GIF JPEG MAGICK PNG SVG TIFF XPM
OPTIONS_RADIO=			FILENOTIFY SOUND X11TOOLKIT
OPTIONS_RADIO_FILENOTIFY=	GFILE KQUEUE
OPTIONS_RADIO_SOUND=		ALSA OSS
OPTIONS_RADIO_X11TOOLKIT=	GTK2 GTK3 MOTIF XAW XAW3D
.if ${FLAVOR:U} == nox
OPTIONS_EXCLUDE=		ALSA CAIRO DBUS GCONF GFILE GIF GSETTINGS GTK2 \
				GTK3 HARFBUZZ JPEG LCMS2 M17N MAGICK MOTIF OSS \
				OTF PNG SCROLLBARS SVG TIFF XAW XAW3D XFT XIM \
				XPM XWIDGETS
.endif
OPTIONS_SUB=			YES

ACL_DESC=		Access control list support
CAIRO_DESC=		Cairo graphics library support [implies PNG, XFT]
FILENOTIFY_DESC=	File notification support
GFILE_DESC=		File notification via gfile
GRAPHICS_DESC=		Graphics support
GSETTINGS_DESC=		GSettings API for application settings
HARFBUZZ_DESC=		HarfBuzz for text shaping
KQUEUE_DESC=		File notification via kqueue
#LTO_DESC=		Enable link-time optimization
M17N_DESC=		M17N support for text-shaping [implies XFT]
MAILUTILS_DESC=		Mail framework via GNU Mailutils
MODULES_DESC=		Dynamic modules support
OTF_DESC=		Opentype fonts [implies XFT]
SCROLLBARS_DESC=	Toolkit scroll-bars
SOURCES_DESC=		Install sources
SVG_DESC=		Scalable vector graphics support [implies PNG]
X11TOOLKIT_DESC=	X11 toolkit
XAW3D_DESC=		Athena3D widgets
XAW_DESC=		Athena widgets
XIM_DESC=		X Input Method
XWIDGETS_DESC=		Experimental GTK widgets [implies GTK3]

ACL_CONFIGURE_ENABLE=		acl
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ON=		--with-sound=alsa
CAIRO_IMPLIES=			PNG XFT
CAIRO_USE=			GNOME=cairo
CAIRO_CONFIGURE_WITH=		cairo
DBUS_LIB_DEPENDS=		libdbus-1.so:devel/dbus
DBUS_CONFIGURE_WITH=		dbus
GCONF_USE=			GNOME=gconf2
GCONF_CONFIGURE_WITH=		gconf
GFILE_USE=			GNOME=glib20
GFILE_CONFIGURE_ON=		--with-file-notification=gfile
GIF_LIB_DEPENDS=		libgif.so:graphics/giflib
GIF_CONFIGURE_WITH=		gif
GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=		gnutls
GSETTINGS_IMPLIES=		DBUS
GSETTINGS_USE=			GNOME=glib20
GSETTINGS_CONFIGURE_WITH=	gsettings
GTK2_LIB_DEPENDS=		libfontconfig.so:x11-fonts/fontconfig \
				libfreetype.so:print/freetype2
GTK2_USE=			GNOME=cairo,gtk20
GTK2_CONFIGURE_ON=		--with-x-toolkit=gtk2
GTK3_USE=			GNOME=cairo,gtk30
GTK3_CONFIGURE_ON=		--with-x-toolkit=gtk3
HARFBUZZ_LIB_DEPENDS=		libharfbuzz.so:print/harfbuzz
HARFBUZZ_CONFIGURE_WITH=	harfbuzz
JPEG_USES=			jpeg
JPEG_CONFIGURE_WITH=		jpeg
JSON_LIB_DEPENDS=		libjansson.so:devel/jansson
JSON_CONFIGURE_WITH=		json
KQUEUE_CONFIGURE_ON=		--with-file-notification=kqueue
LCMS2_LIB_DEPENDS=		liblcms2.so:graphics/lcms2
LCMS2_CONFIGURE_WITH=		lcms2
#LTO_CONFIGURE_ON=		--enable-link-time-optimization
M17N_IMPLIES=			XFT
M17N_LIB_DEPENDS=		libm17n.so:devel/m17n-lib
M17N_CONFIGURE_WITH=		m17n-flt
MAGICK_LIB_DEPENDS=		libMagickCore-6.so:graphics/ImageMagick6
MAGICK_CONFIGURE_WITH=		imagemagick
MAILUTILS_LIB_DEPENDS=		libmailutils.so:mail/mailutils
MAILUTILS_CONFIGURE_WITH=	mailutils
MAILUTILS_CONFIGURE_ENV_OFF=	ac_cv_lib_lockfile_maillock=no \
				ac_cv_prog_liblockfile=no
MODULES_CONFIGURE_WITH=		modules
MOTIF_USES=			motif
MOTIF_CONFIGURE_ON=		--with-x-toolkit=motif
OSS_CONFIGURE_ON=		--with-sound=oss
OTF_IMPLIES=			XFT
OTF_LIB_DEPENDS=		libotf.so:print/libotf
OTF_CONFIGURE_WITH=		libotf
PNG_LIB_DEPENDS=		libpng.so:graphics/png
PNG_CONFIGURE_WITH=		png
SCROLLBARS_CONFIGURE_WITH=	toolkit-scroll-bars
SVG_IMPLIES=			PNG
SVG_USE=			GNOME=cairo,librsvg2
SVG_CONFIGURE_WITH=		rsvg
THREADS_CONFIGURE_WITH=		threads
TIFF_LIB_DEPENDS=		libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=		tiff
XAW3D_LIB_DEPENDS=		libXaw3d.so:x11-toolkits/Xaw3d
XAW3D_CONFIGURE_ON=		--with-x-toolkit=athena
XAW_USE=			XORG=xaw
XAW_CONFIGURE_ON=		--with-x-toolkit=athena \
				--without-xaw3d
XFT_LIB_DEPENDS=		libfontconfig.so:x11-fonts/fontconfig \
				libfreetype.so:print/freetype2
XFT_USE=			XORG=xft,xrender
XFT_CONFIGURE_WITH=		xft
XIM_CONFIGURE_WITH=		xim
XML_USES=			gnome # portlint complains, but use for nox
XML_USE=			GNOME=libxml2
XML_CONFIGURE_WITH=		xml2
XPM_USE=			XORG=xpm
XPM_CONFIGURE_WITH=		xpm
XWIDGETS_IMPLIES=		GTK3
XWIDGETS_LIB_DEPENDS=		libsoup-2.4.so:devel/libsoup \
				libwebkit2gtk-4.0.so:www/webkit2-gtk3
XWIDGETS_USE=			XORG=xcomposite
XWIDGETS_CONFIGURE_WITH=	xwidgets

.include <bsd.port.options.mk>

# has graphics/ImageMagick been compiled with OPENMP?
.if ${PORT_OPTIONS:MMAGICK} && ${:!${GREP} -sc " \-fopenmp " ${LOCALBASE}/libdata/pkgconfig/ImageMagick.pc || true!} == "1"
USES+=		compiler:openmp
.endif

.if !${PORT_OPTIONS:MGTK2} && !${PORT_OPTIONS:MGTK3} && !${PORT_OPTIONS:MMOTIF} \
	&& !${PORT_OPTIONS:MXAW} && !${PORT_OPTIONS:MXAW3D}
CONFIGURE_ARGS+=	--with-x-toolkit=no
.endif

.if ${FLAVOR} == nox
# With a desktop entry stage-qa will give a warning about requiring
# desktop-file-utils and portlint -C will give a warning about INSTALLS_ICONS,
# but don't pull in those dependencies with the nox flavor.
post-patch:
	@${REINPLACE_CMD} -e 's/^Terminal=.*$$/Terminal=true/' ${WRKSRC}/etc/emacs.desktop
.endif

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh all)
	@${REINPLACE_CMD} \
	  -e '/emacs-repository-version/s/^.*$$/(setq emacs-repository-version "${GH_TAGNAME}")/' \
	  -e '/emacs-repository-branch/s/^.*$$/(setq emacs-repository-branch "master")/' \
	  ${WRKSRC}/lisp/loadup.el

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

post-install-MAILUTILS-on:
	${LN} -sf ${PREFIX}/bin/movemail \
		${STAGEDIR}${PREFIX}/libexec/emacs/${DISTVERSION:R}/${CONFIGURE_TARGET}

post-install-SOURCES-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${DISTVERSION:R}/src
	${INSTALL_DATA} ${WRKSRC}/src/*.[ch] ${STAGEDIR}${DATADIR}/${DISTVERSION:R}/src
	${INSTALL_DATA} ${WRKDIR}/sources.el ${STAGEDIR}${DATADIR}/${DISTVERSION:R}/site-lisp/site-start.el

.include <bsd.port.mk>
