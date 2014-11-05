# Created by: Kenneth Vestergaard Schmidt <kvs@pil.dk>
# $FreeBSD$

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}.${EMACS_REV}
PORTEPOCH=	2
CATEGORIES=	editors ipv6
MASTER_SITES=	http://distfiles.pirateparty.in/%SUBDIR%/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ashish
PKGNAMESUFFIX=	-devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GNU editing macros

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	emacs-19.* emacs21-[0-9]* emacs22-[0-9]* emacs23-[0-9]* \
		emacs24-[0-9]* xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]* \
		emacs-nox11-[0-9]*

EMACS_VER=	25.0.50
EMACS_REV=	118251
GNU_CONFIGURE=	yes
USES=		gmake makeinfo ncurses pkgconfig shebangfix tar:xz
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INFO_PATH=	${DATADIR_REL}/info
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_AUTOTOOLS=	autoconf:env aclocal:env automake:env autoheader:env

SHEBANG_FILES=	${WRKSRC}/lib-src/grep-changelog

# Append --without-compress-install to prevent emacs from compressing info
# which bsd.port.mk is not able to detect
CONFIGURE_ARGS=	--localstatedir=/var --without-compress-install

EMACS_DIRS=	${DATADIR}/${EMACS_VER}/lisp ${DATADIR}/${EMACS_VER}/src \
		${PREFIX}/libexec/${PORTNAME}

PLIST_SUB=	EMACS_VER=${EMACS_VER} GNU_HOST=${CONFIGURE_TARGET}

MAKE_ENV=	LC_ALL=C

INFO=		ada-mode auth autotype bovine calc ccmode cl dbus dired-x \
		ebrowse ede ediff edt efaq eieio eintr elisp emacs-mime emacs-gnutls emacs epa \
		erc ert eshell eudc eww flymake forms gnus htmlfontify idlwave ido info \
		mairix-el message mh-e newsticker nxml-mode octave-mode \
		org pcl-cvs pgg rcirc reftex remember sasl sc semantic ses sieve smtpmail speedbar \
		srecode todo-mode tramp url vhdl-mode vip viper widget wisent woman

OPTIONS_DEFINE=	X11 ACL DBUS GCONF GIF JPEG M17N OTF PNG SOUND SOURCES SVG TIFF SCROLLBARS \
		XFT XIM XML XPM MAGICK GNUTLS GSETTINGS LTO FILENOTIFY

OPTIONS_SINGLE=	X11 SOUND

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

OPTIONS_SINGLE_X11=	GTK2 GTK3 XAW XAW3D MOTIF
OPTIONS_SINGLE_SOUND=		ALSA OSS

OPTIONS_DEFAULT=ACL DBUS GCONF GIF GTK2 JPEG M17N OTF PNG SOUND SOURCES SVG TIFF \
		SCROLLBARS XFT XIM XML XPM MAGICK GNUTLS GSETTINGS FILENOTIFY OSS X11

OPTIONS_SUB=		SOURCES

SOUND_CONFIGURE_OFF=	--with-sound=no
ALSA_CONFIGURE_ON=		--with-sound=alsa
OSS_CONFIGURE_ON=		--with-sound=oss

DBUS_LIB_DEPENDS=		libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_WITH=		dbus

GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

XML_USE=		GNOME=libxml2
XML_CONFIGURE_WITH=	xml2

SVG_USE=	GNOME=librsvg2
SVG_CONFIGURE_WITH=	rsvg

X11_CONFIGURE_WITH=	x
X11_USE=	XORG=x11
X11_PLIST_DIRSTRY_OFF=	share/icons/hicolor/scalable/mimetypes \
			share/icons/hicolor/scalable/apps \
			share/icons/hicolor/scalable \
			share/icons/hicolor/48x48/apps \
			share/icons/hicolor/48x48 \
			share/icons/hicolor/32x32/apps \
			share/icons/hicolor/32x32 \
			share/icons/hicolor/24x24/apps \
			share/icons/hicolor/24x24 \
			share/icons/hicolor/16x16/apps \
			share/icons/hicolor/16x16 \
			share/icons/hicolor/128x128/apps \
			share/icons/hicolor/128x128 \
			share/icons/hicolor \
			share/icons

GTK2_USE=	GNOME=gtk20
GTK2_CONFIGURE_ON=	--with-x-toolkit=gtk2

GTK3_USE=	GNOME=gtk30
GTK3_CONFIGURE_ON=	--with-x-toolkit=gtk3

XAW3D_LIB_DEPENDS=	libXaw3d.so:${PORTSDIR}/x11-toolkits/Xaw3d
XAW3D_CONFIGURE_ON=	--with-x-toolkit=athena

XAW_USE=	XORG=xaw
XAW_CONFIGURE_ON+=	--with-x-toolkit=athena --without-xaw3d

MOTIF_USES=	motif
MOTIF_CONFIGURE_ON+=	--with-x-toolkit=motif

SCROLLBARS_CONFIGURE_WITH=	toolkit-scroll-bars

SYNC_INPUT_CONFIGURE_WITH=	sync-input

JPEG_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
JPEG_CONFIGURE_WITH=	jpeg

TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
TIFF_CONFIGURE_WITH=	tiff

GIF_LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib
GIF_CONFIGURE_WITH=	gif

PNG_LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_WITH=	png

XPM_USE=		XORG=xpm
XPM_CONFIGURE_WITH=	xpm

XFT_USE=		XORG=xft
XFT_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
XFT_CONFIGURE_WITH=	xft

M17N_LIB_DEPENDS=	libm17n.so:${PORTSDIR}/devel/m17n-lib
M17N_CONFIGURE_WITH=	m17n-flt

OTF_LIB_DEPENDS=	libotf.so:${PORTSDIR}/print/libotf
OTF_CONFIGURE_WITH=	libotf

MAGICK_LIB_DEPENDS=	libMagickCore-6.Q*.so:${PORTSDIR}/graphics/ImageMagick
MAGICK_CONFIGURE_WITH=	imagemagick

GSETTINGS_USE=			gnome=glib20
GSETTINGS_CONFIGURE_WITH=	gsettings

GCONF_USE=			gnome=gconf2
GCONF_CONFIGURE_WITH=		gconf

XIM_CONFIGURE_WITH=		xim

LTO_CONFIGURE_ON=		--enable-link-time-optimization
LTO_USE=			GCC=4.6+

ACL_CONFIGURE_OFF=		--disable-acl

FILENOTIFY_CONFIGURE_ON=	--with-file-notification=gfile
FILENOTIFY_CONFIGURE_OFF=	--without-file-notification
FILENOTIFY_USE=			GNOME=glib20

.include <bsd.port.options.mk>

# clang is broken on i386 platform in -O2, due to use of alloca, and stack realignment
# and %esi as frame pointer register
# http://llvm.org/bugs/show_bug.cgi?id=18171
.if ${ARCH} == "i386"
USE_GCC=			any
.endif

DBUS_PTHREAD_LIBS=	${CC} -dumpspecs | ${GREP} -m 1 pthread: | ${SED} -e 's|^.*%{\!pg: %{pthread:||' -e 's|}.*$$||' || ${TRUE}

.if ${PORT_OPTIONS:MX11}

INSTALLS_ICONS=	yes

.if !${PORT_OPTIONS:MXFT}
.if ${PORT_OPTIONS:MM17N}
IGNORE=	m17n support for text-shaping requires Xft. Please run 'make config'
.elif ${PORT_OPTIONS:MOTF}
IGNORE=	opentype fonts support requires Xft. Please run 'make config'
.endif
.endif

.else

.for OPT in SVG GTK2 GTK3 XAW3D XAW MOTIF SCROLLBARS JPEG TIFF GIF PNG XPM XFT M17N MAGICK GCONF GSETTINGS XIM
.if ${PORT_OPTIONS:M${OPT}}
IGNORE=	option ${OPT} requires X11 option
.endif
.endfor

.endif

.if !${PORT_OPTIONS:MDBUS}
.if ${PORT_OPTIONS:MGSETTINGS}
IGNORE=	support for GSettings requires DBUS. Please run 'make config'
.endif
.endif

.include <bsd.port.pre.mk>

# Building with GCC 4.6+ requires it
.if ${ncurses_ARGS} == "port"
LDFLAGS+=	-ltinfo
.endif

.if ${ARCH} == "ia64"
BROKEN=	Emacs 24.X does not currently build on ia64
.endif

post-patch:
	@${RM} -f ${WRKSRC}/info/*
	@${REINPLACE_CMD} -e "s/%%EMACS_VER%%/${EMACS_VER}/g" -e "s/%%DATADIR%%/${DATADIR:C/\//\\\//g}/g" ${WRKSRC}/sources.el
.if empty(PORT_OPTIONS:MX11)
	@${REINPLACE_CMD} -e 's/^Terminal=.*$$/Terminal=true/' ${WRKSRC}/etc/emacs.desktop
.endif

post-configure:
	@${REINPLACE_CMD} -e "s/^\(DBUS_LIBS.*\)-pthread\(.*\)$$/\1$$(${DBUS_PTHREAD_LIBS})\2/" \
			  ${WRKSRC}/src/Makefile

pre-configure:
	@cd ${WRKSRC} && ./autogen.sh

post-install:
	@${RM} -rf ${STAGEDIR}/var/games/emacs
.if ${PORT_OPTIONS:MSOURCES}
	@${MKDIR} ${STAGEDIR}${DATADIR}/${EMACS_VER}/src
	@${INSTALL_DATA} ${WRKSRC}/src/*.[ch] ${STAGEDIR}${DATADIR}/${EMACS_VER}/src
	@${INSTALL_DATA} ${WRKSRC}/sources.el ${STAGEDIR}${DATADIR}/${EMACS_VER}/site-lisp/site-start.el
.endif

.if !defined(WITHOUT_X11)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "====> To disable X11 support, define: WITHOUT_X11."
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
