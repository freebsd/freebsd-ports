# Created by: Kenneth Vestergaard Schmidt <kvs@pil.dk>
# $FreeBSD$

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}.${EMACS_REV}
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	editors ipv6
PKGNAMESUFFIX=	-devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GNU editing macros

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_9=	does not build
BROKEN_sparc64=	fails to compile at bootstrap phase
BROKEN_ia64=		Emacs 24.X does not currently build on ia64

CONFLICTS=	emacs-19.* emacs21-[0-9]* emacs22-[0-9]* emacs23-[0-9]* \
		emacs24-[0-9]* xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]* \
		emacs-nox11-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	emacs-mirror
GH_TAGNAME=	af40b76

EMACS_VER=	25.0.50
EMACS_REV=	20151126
GNU_CONFIGURE=	yes
USES=		autoreconf cpe gmake makeinfo ncurses pkgconfig tar:xz
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INFO_PATH=	${DATADIR_REL}/info
WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}
CPE_VENDOR=	gnu

SUB_LIST+=	ARCHLIBDIR=${PREFIX}/libexec/emacs/${EMACS_VER}/${CONFIGURE_TARGET}

CONFIGURE_ARGS=	--localstatedir=/var --with-gameuser=games:games

PLIST_SUB=	EMACS_VER=${EMACS_VER} GNU_HOST=${CONFIGURE_TARGET}

MAKE_ENV=	LC_ALL=C

INFO=		ada-mode auth autotype bovine calc ccmode cl dbus dired-x      \
		ebrowse ede ediff edt efaq eieio eintr elisp emacs             \
		emacs-gnutls emacs-mime epa erc ert eshell eudc eww flymake    \
		forms gnus htmlfontify idlwave ido info mairix-el message mh-e \
		newsticker nxml-mode octave-mode org pcl-cvs pgg rcirc reftex  \
		remember sasl sc semantic ses sieve smtpmail speedbar srecode  \
		todo-mode tramp url vhdl-mode vip viper widget wisent woman

OPTIONS_DEFINE=	X11 ACL DBUS GCONF GIF JPEG M17N OTF PNG SOUND SOURCES SVG TIFF SCROLLBARS \
		XFT XIM XML XPM MAGICK GNUTLS GSETTINGS LTO FILENOTIFY LLDB CAIRO

OPTIONS_SINGLE=	X11 SOUND

ACL_DESC=	ACL support
GSETTINGS_DESC=	GSettings support
SCROLLBARS_DESC=Toolkit scroll-bars
SOUND_DESC=	Sound support
SOURCES_DESC=	Install sources
XAW_DESC=	Athena widgets
XAW3D_DESC=	Athena3D widgets
XIM_DESC=	X Input Method Support
M17N_DESC=	M17N support for text-shaping
OTF_DESC=	Opentype fonts suport
FILENOTIFY_DESC=File notification support
LTO_DESC=	Enable link-time optimization (requires GCC 4.6+)
LLDB_DESC=	Enable lldb support for GUD (from llvm.org)

OPTIONS_SINGLE_X11=	GTK2 GTK3 XAW XAW3D MOTIF
OPTIONS_SINGLE_SOUND=	ALSA OSS

OPTIONS_DEFAULT=ACL DBUS FILENOTIFY GCONF GIF GNUTLS GSETTINGS GTK2 JPEG M17N \
		MAGICK OSS OTF PNG SCROLLBARS SOUND SOURCES SVG TIFF X11 XFT XIM \
		XML XPM

OPTIONS_SUB=		YES

LLDB_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-lldb-gud.el

SOUND_CONFIGURE_OFF=	--with-sound=no
ALSA_CONFIGURE_ON=	--with-sound=alsa
ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
OSS_CONFIGURE_ON=	--with-sound=oss

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_WITH=	dbus

GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

XML_USE=		GNOME=libxml2
XML_CONFIGURE_WITH=	xml2

SVG_USE=		GNOME=librsvg2
SVG_CONFIGURE_WITH=	rsvg

X11_CONFIGURE_WITH=	x
X11_USE=		XORG=x11
X11_USES=		desktop-file-utils

GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_ON=	--with-x-toolkit=gtk2

GTK3_USE=		GNOME=gtk30
GTK3_CONFIGURE_ON=	--with-x-toolkit=gtk3

XAW3D_LIB_DEPENDS=	libXaw3d.so:${PORTSDIR}/x11-toolkits/Xaw3d
XAW3D_CONFIGURE_ON=	--with-x-toolkit=athena

XAW_USE=		XORG=xaw
XAW_CONFIGURE_ON+=	--with-x-toolkit=athena --without-xaw3d

MOTIF_USES=		motif
MOTIF_CONFIGURE_ON+=	--with-x-toolkit=motif

SCROLLBARS_CONFIGURE_WITH=	toolkit-scroll-bars

SYNC_INPUT_CONFIGURE_WITH=	sync-input

JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=	jpeg

TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
TIFF_CONFIGURE_WITH=	tiff

GIF_LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib
GIF_CONFIGURE_WITH=	gif

PNG_LIB_DEPENDS+=	libpng.so:${PORTSDIR}/graphics/png
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

MAGICK_LIB_DEPENDS=	libMagickCore-6.so:${PORTSDIR}/graphics/ImageMagick
MAGICK_CONFIGURE_WITH=	imagemagick

GSETTINGS_USE=		gnome=glib20
GSETTINGS_CONFIGURE_WITH=	gsettings

GCONF_USE=		gnome=gconf2
GCONF_CONFIGURE_WITH=	gconf

XIM_CONFIGURE_WITH=	xim

LTO_CONFIGURE_ON=	--enable-link-time-optimization
LTO_USE=		GCC=4.6+

ACL_CONFIGURE_OFF=	--disable-acl

FILENOTIFY_CONFIGURE_ON=--with-file-notification=gfile
FILENOTIFY_CONFIGURE_OFF=	--without-file-notification
FILENOTIFY_USE=		GNOME=glib20

CAIRO_USE=		GNOME=cairo
CAIRO_CONFIGURE_ON=	--with-cairo

.include <bsd.port.options.mk>

# clang is broken on i386 platform in -O2, due to use of alloca, and stack realignment
# and %esi as frame pointer register
# http://llvm.org/bugs/show_bug.cgi?id=18171
# fixed in r263312 (11-CURRENT), and fixed in r263765 (10-STABLE)
.if ${ARCH} == "i386"
.if (${OSVERSION} < 1000706) || (${OSVERSION} >= 1100000 && ${OSVERSION} < 1100015)
USE_GCC=		any
.endif
.endif

DBUS_PTHREAD_LIBS=	${CC} -dumpspecs | ${GREP} -m 1 pthread: | ${SED} -e 's|^.*%{\!pg: %{pthread:||' -e 's|}.*$$||' || ${TRUE}

.if ${PORT_OPTIONS:MX11}
INSTALLS_ICONS=	yes
.if !${PORT_OPTIONS:MXFT}
.if ${PORT_OPTIONS:MM17N}
IGNORE=		m17n support for text-shaping requires Xft. Please run 'make config'
.elif ${PORT_OPTIONS:MOTF}
IGNORE=		opentype fonts support requires Xft. Please run 'make config'
.endif
.endif
.else
.for OPT in 	GCONF GIF GSETTINGS GTK2 GTK3 JPEG M17N MAGICK MOTIF PNG \
		SCROLLBARS SVG TIFF XAW XAW3D XFT XIM XPM
.if ${PORT_OPTIONS:M${OPT}}
IGNORE=		option ${OPT} requires X11 option
.endif
.endfor
.endif

.if !${PORT_OPTIONS:MDBUS}
.if ${PORT_OPTIONS:MGSETTINGS}
IGNORE=		support for GSettings requires DBUS. Please run 'make config'
.endif
.endif

.include <bsd.port.pre.mk>

# Building with GCC 4.6+ requires it
.if ${ncurses_ARGS} == "port"
LDFLAGS+=	-ltinfo
.endif

post-patch:
	@${RM} -f ${WRKSRC}/info/*
	@${REINPLACE_CMD} -e "s/%%EMACS_VER%%/${EMACS_VER}/g" -e "s/%%DATADIR%%/${DATADIR:C/\//\\\//g}/g" ${WRKSRC}/sources.el
.if empty(PORT_OPTIONS:MX11)
	@${REINPLACE_CMD} -e 's/^Terminal=.*$$/Terminal=true/' ${WRKSRC}/etc/emacs.desktop
.endif

post-configure:
	@${REINPLACE_CMD} -e \
	"s/^\(DBUS_LIBS.*\)-pthread\(.*\)$$/\1$$(${DBUS_PTHREAD_LIBS})\2/" \
	${WRKSRC}/src/Makefile

pre-configure:
	@cd ${WRKSRC} && ./autogen.sh

post-install:
.if ${PORT_OPTIONS:MSOURCES}
	@${MKDIR} ${STAGEDIR}${DATADIR}/${EMACS_VER}/src
	${INSTALL_DATA} ${WRKSRC}/src/*.[ch] ${STAGEDIR}${DATADIR}/${EMACS_VER}/src
	${INSTALL_DATA} ${WRKSRC}/sources.el ${STAGEDIR}${DATADIR}/${EMACS_VER}/site-lisp/site-start.el
.endif
	@${FIND} ${STAGEDIR}${PREFIX}/${INFO_PATH} -type f -name '*.gz' -exec ${GUNZIP_CMD} '{}' \;

.if !defined(WITHOUT_X11)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "====> To disable X11 support, define: WITHOUT_X11."
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
