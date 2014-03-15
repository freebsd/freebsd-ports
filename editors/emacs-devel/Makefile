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

EMACS_VER=	24.3.50
EMACS_REV=	116732
GNU_CONFIGURE=	yes
USES=		ncurses pkgconfig
USE_GMAKE=	yes
USE_XZ=		yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INFO_PATH=	${DATADIR_REL}/info
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_AUTOTOOLS=	autoconf:env automake:env aclocal:env autoheader:env

# Append --without-compress-install to prevent emacs from compressing info
# which bsd.port.mk is not able to detect
CONFIGURE_ARGS=	--localstatedir=/var --without-compress-install

EMACS_DIRS=	${DATADIR}/${EMACS_VER}/lisp ${DATADIR}/${EMACS_VER}/src \
		${PREFIX}/libexec/${PORTNAME}

PLIST_SUB=	EMACS_VER=${EMACS_VER} INFODIR=${INFO_PATH}

MAKE_ENV=	LC_ALL=C

INFO=		ada-mode auth autotype bovine calc ccmode cl dbus dired-x \
		ebrowse ede ediff edt efaq eieio eintr elisp emacs-mime emacs-gnutls emacs epa \
		erc ert eshell eudc flymake forms gnus htmlfontify idlwave ido info \
		mairix-el message mh-e newsticker nxml-mode \
		org pcl-cvs pgg rcirc reftex remember sasl sc semantic ses sieve \
		smtpmail speedbar srecode todo-mode tramp url vip viper widget wisent woman

OPTIONS_DEFINE=	X11 ACL DBUS GCONF GIF JPEG M17N OTF PNG SOUND SOURCES SVG TIFF SCROLLBARS \
		XFT XIM XML XPM MAGICK GNUTLS GSETTINGS LTO FILENOTIFY

OPTIONS_SINGLE=	X11 SOUND GNUTLS

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
GNUTLS2_DESC=		GnuTLS 2.x
GNUTLS3_DESC=		GnuTLS 3.x

OPTIONS_SINGLE_X11=	GTK2 GTK3 XAW XAW3D MOTIF
OPTIONS_SINGLE_SOUND=		ALSA OSS
OPTIONS_SINGLE_GNUTLS=		GNUTLS2 GNUTLS3

OPTIONS_DEFAULT=ACL DBUS GCONF GIF GTK2 JPEG M17N OTF PNG SOUND SOURCES SVG TIFF \
		SCROLLBARS XFT XIM XML XPM MAGICK GNUTLS GSETTINGS FILENOTIFY OSS X11 GNUTLS3

OPTIONS_SUB=		SOURCES

SOUND_CONFIGURE_OFF=	--with-sound=no
ALSA_CONFIGURE_ON=		--with-sound=alsa
OSS_CONFIGURE_ON=		--with-sound=oss

DBUS_LIB_DEPENDS=		dbus-1:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_WITH=		dbus

GNUTLS_CONFIGURE_WITH=	gnutls

GNUTLS3_LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls3
GNUTLS2_LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls

XML_USE=		GNOME=libxml2
XML_CONFIGURE_WITH=	xml2

SVG_USE=	GNOME=librsvg2
SVG_CONFIGURE_WITH=	rsvg

X11_CONFIGURE_WITH=	x
X11_USE=	XORG=x11

GTK2_USE=	GNOME=gtk20
GTK2_CONFIGURE_ON=	--with-x-toolkit=gtk2

GTK3_USE=	GNOME=gtk30
GTK3_CONFIGURE_ON=	--with-x-toolkit=gtk3

XAW3D_LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d
XAW3D_CONFIGURE_ON=	--with-x-toolkit=athena

XAW_USE=	XORG=xaw
XAW_CONFIGURE_ON+=	--with-x-toolkit=athena --without-xaw3d

MOTIF_USES=	motif
MOTIF_CONFIGURE_ON+=	--with-x-toolkit=motif

SCROLLBARS_CONFIGURE_WITH=	toolkit-scroll-bars

SYNC_INPUT_CONFIGURE_WITH=	sync-input

JPEG_LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg
JPEG_CONFIGURE_WITH=	jpeg

TIFF_LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff
TIFF_CONFIGURE_WITH=	tiff

GIF_LIB_DEPENDS=	gif:${PORTSDIR}/graphics/giflib
GIF_CONFIGURE_WITH=	gif

PNG_LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
PNG_CONFIGURE_WITH=	png

XPM_USE=		XORG=xpm
XPM_CONFIGURE_WITH=	xpm

XFT_USE=		XORG=xft
XFT_LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2
XFT_CONFIGURE_WITH=	xft

M17N_LIB_DEPENDS=	m17n:${PORTSDIR}/devel/m17n-lib
M17N_CONFIGURE_WITH=	m17n-flt

OTF_LIB_DEPENDS=	otf:${PORTSDIR}/print/libotf
OTF_CONFIGURE_WITH=	libotf

MAGICK_LIB_DEPENDS=	MagickCore:${PORTSDIR}/graphics/ImageMagick
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
IGNORE=	${OPT} option depends on X11 option
.endif
.endfor

.endif

.if !${PORT_OPTIONS:MDBUS}
.if ${PORT_OPTIONS:MGSETTINGS}
IGNORE=	GSettings support requires DBUS. Please run 'make config'
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

.if ${PORT_OPTIONS:MGNUTLS3}
GNUTLS3_RPATH=	-Wl,-rpath,${LOCALBASE}/lib/gnutls3
.else
GNUTLS3_RPATH=
.endif

post-patch:
	@${RM} -f ${WRKSRC}/info/*
	@${REINPLACE_CMD} -e "s/%%EMACS_VER%%/${EMACS_VER}/g" -e "s/%%DATADIR%%/${DATADIR:C/\//\\\//g}/g" ${WRKSRC}/sources.el
.if defined(WITHOUT_X11)
	@${REINPLACE_CMD} -e 's/^Terminal=.*$$/Terminal=true/' ${WRKSRC}/etc/emacs.desktop
.endif
.if ${PORT_OPTIONS:MGNUTLS3}
	@${REINPLACE_CMD} -e '/HAVE_GNUTLS3=yes/s/gnutls >=/gnutls3 >=/' ${WRKSRC}/configure.ac
.endif

post-configure:
	@${REINPLACE_CMD} -e "s/^\(DBUS_LIBS.*\)-pthread\(.*\)$$/\1$$(${DBUS_PTHREAD_LIBS})\2/" \
			  -e 's|%%GNUTLS3_RPATH%%|${GNUTLS3_RPATH}|g' \
			  ${WRKSRC}/src/Makefile

add-plist-data:
.for i in ${EMACS_DIRS}
	@${FIND} ${STAGEDIR}${i} -type f |${SED} -E -e 's,^${STAGEDIR}${PREFIX}/,,g'  >>${TMPPLIST}
.endfor
	@${FIND} ${WRKSRC}/etc -type f |${SED} -E -e 's,^${WRKSRC},${DATADIR_REL}/${EMACS_VER},g' -e '/etc\/(\..*|ChangeLog)$$/d' >>${TMPPLIST}
	@${FIND} ${WRKSRC}/etc -type d -depth |${SED} -E -e 's,^${WRKSRC},@dirrm ${DATADIR_REL}/${EMACS_VER},g' >>${TMPPLIST}
.for i in ${EMACS_DIRS}
	@${FIND} ${STAGEDIR}${i} -type d -depth |${SED} -E -e 's,^${STAGEDIR}${PREFIX}/,@dirrm ,g' >>${TMPPLIST}
.endfor
	@${ECHO} "@unexec rmdir %D/${DATADIR_REL}/${EMACS_VER} 2>/dev/null || true" >>${TMPPLIST}

pre-configure:
	@cd ${WRKSRC} && ./autogen.sh

.if ${PORT_OPTIONS:MSOURCES}
post-install:
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
