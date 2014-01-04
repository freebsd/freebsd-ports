# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}
PORTREVISION?=	2
PORTEPOCH=	3
CATEGORIES=	editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX?=	24

PATCH_SITE_SUBDIR+=	ashish
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GNU editing macros

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_SAFE=	yes

CONFLICTS=	emacs-19.* emacs21-* emacs22-* emacs23-* \
		xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]* \
		emacs-devel-*

EMACS_VER=	24.3
GNU_CONFIGURE=	yes
USES=		ncurses gmake pkgconfig
USE_XZ=		yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INFO_PATH=	${DATADIR_REL}/info
CONFIGURE_ARGS=	--localstatedir=/var --without-compress-info
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		ctags.1 ebrowse.1 emacs.1 emacsclient.1 etags.1 \
		grep-changelog.1
PLIST_SUB=	EMACS_VER=${EMACS_VER} INFODIR=${INFO_PATH}

EMACS_DIRS=	${DATADIR}/${EMACS_VER}/leim ${DATADIR}/${EMACS_VER}/lisp ${DATADIR}/${EMACS_VER}/src \
		${PREFIX}/libexec/${PORTNAME}

MAKE_ENV=	LC_ALL=C

INFO=		ada-mode auth autotype bovine calc ccmode cl dbus dired-x \
		ebrowse ede ediff edt efaq eieio eintr elisp emacs-mime emacs-gnutls emacs epa \
		erc ert eshell eudc flymake forms gnus htmlfontify idlwave info \
		mairix-el message mh-e newsticker nxml-mode \
		org pcl-cvs pgg rcirc reftex remember sasl sc semantic ses sieve \
		smtpmail speedbar srecode tramp url vip viper widget wisent woman

CONFLICTS+=	emacs-nox11-[0-9]*
OPTIONS_DEFINE=	CANNA DBUS GCONF GIF JPEG M17N OTF PNG SOUND SOURCES SVG TIFF SYNC_INPUT SCROLLBARS X11 XFT \
		XIM XML XPM MAGICK GNUTLS GSETTINGS

OPTIONS_SINGLE=	X11

CANNA_DESC=		Canna support
GSETTINGS_DESC=		GSettings support (requires DBUS)
SCROLLBARS_DESC=	Toolkit scroll-bars
SOUND_DESC=		Sound support
SOURCES_DESC=		Install sources
SYNC_INPUT_DESC=	Synchronously process asynchronous input
XAW_DESC=		Athena widgets
XAW3D_DESC=		Athena3D widgets
XIM_DESC=		X Input Method Support
M17N_DESC=		M17N support for text-shaping
OTF_DESC=		Opentype fonts suport

OPTIONS_SINGLE_X11=	GTK2 GTK3 XAW XAW3D MOTIF

.if !defined(EMACS_NO_X11_SLAVE)
OPTIONS_DEFAULT=DBUS GCONF GIF GTK2 JPEG M17N OTF PNG SOUND SOURCES SVG TIFF SYNC_INPUT \
		SCROLLBARS XFT XIM XML XPM MAGICK GNUTLS GSETTINGS X11
.else
OPTIONS_DEFAULT=SOURCES GNUTLS XML
.endif

OPTIONS_SUB=		SOURCES

CANNA_CONFIGURE_ON=	--with-canna \
			--with-canna-includes=${LOCALBASE}/include \
			--with-canna-libraries=${LOCALBASE}/lib
CANNA_PATCH_SITES=	http://distfiles.pirateparty.in/%SUBDIR%/ ${MASTER_SITE_LOCAL}
CANNA_PATCHFILES=	emacs24.3canna-20130321.diff.gz
CANNA_LIB_DEPENDS=	canna:${PORTSDIR}/japanese/canna-lib

SOUND_CONFIGURE_WITH=		sound

DBUS_LIB_DEPENDS=		dbus-1:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_WITH=		dbus

GNUTLS_LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

XML_USE=		GNOME=libxml2
XML_CONFIGURE_WITH=	xml2

SVG_USE=	GNOME=librsvg2
SVG_CONFIGURE_WITH=	rsvg

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

.include <bsd.port.options.mk>

# clang is broken on i386 platform in -O2, due to use of alloca
# and %esi as frame pointer register
.if ${ARCH} == "i386"
USE_GCC=			any
.endif

DBUS_PTHREAD_LIBS=	${CC} -dumpspecs | ${GREP} -m 1 pthread: | ${SED} -e 's|^.*%{\!pg: %{pthread:||' -e 's|}.*$$||' || ${TRUE}

.if ${PORT_OPTIONS:MX11}

CONFIGURE_ARGS+=	--with-x
USE_XORG=		x11

INSTALLS_ICONS=	yes

.if !${PORT_OPTIONS:MXFT}
.if ${PORT_OPTIONS:MM17N}
IGNORE=	m17n support for text-shaping requires Xft. Please run 'make config'
.elif ${PORT_OPTIONS:MOTF}
IGNORE=	opentype fonts support requires Xft. Please run 'make config'
.endif
.endif

.else

CONFIGURE_ARGS+=	--without-x

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

post-patch:
	@${RM} -f ${WRKSRC}/info/*
	@${REINPLACE_CMD} -e "s/%%EMACS_VER%%/${EMACS_VER}/g" -e "s/%%DATADIR%%/${DATADIR:C/\//\\\//g}/g" ${WRKSRC}/sources.el
.if !${PORT_OPTIONS:MX11}
	@${REINPLACE_CMD} -e 's/^Terminal=.*$$/Terminal=true/' ${WRKSRC}/etc/emacs.desktop
.endif

post-configure:
	@${REINPLACE_CMD} -e "s/^\(DBUS_LIBS.*\)-pthread\(.*\)$$/\1$$(${DBUS_PTHREAD_LIBS})\2/" ${WRKSRC}/src/Makefile

add-plist-data:
.for i in ${EMACS_DIRS}
	@${FIND} ${STAGEDIR}${i} -type f |${SED} -E -e 's,^${STAGEDIR}${PREFIX}/,,g'  >>${TMPPLIST}
.endfor
	@${FIND} ${WRKSRC}/etc -type f |${SED} -E -e 's,^${WRKSRC},${DATADIR_REL}/${EMACS_VER},g' -e '/etc\/(\..*|ChangeLog|DOC)$$/d' >>${TMPPLIST}
	@${FIND} ${WRKSRC}/etc -type d -depth |${SED} -E -e 's,^${WRKSRC},@dirrm ${DATADIR_REL}/${EMACS_VER},g' >>${TMPPLIST}
.for i in ${EMACS_DIRS}
	@${FIND} ${STAGEDIR}${i} -type d -depth |${SED} -E -e 's,^${STAGEDIR}${PREFIX}/,@dirrm ,g' >>${TMPPLIST}
.endfor
	@${ECHO} "@unexec rmdir %D/${DATADIR_REL}/${EMACS_VER} 2>/dev/null || true" >>${TMPPLIST}

.if ${PORT_OPTIONS:MSOURCES}
post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${EMACS_VER}/src
	@${INSTALL_DATA} ${WRKSRC}/src/*.[ch] ${STAGEDIR}${DATADIR}/${EMACS_VER}/src
	@${INSTALL_DATA} ${WRKSRC}/sources.el ${STAGEDIR}${DATADIR}/${EMACS_VER}/site-lisp/site-start.el
.endif

pre-everything::
.if ${PORT_OPTIONS:MX11}
	@${ECHO_MSG}
	@${ECHO_MSG} "====> To disable X11 support, unset option: X11."
	@${ECHO_MSG}
.endif
.if ${PORT_OPTIONS:MCANNA}
	@${ECHO_MSG} "====> Canna support is not part of standard distribution"
	@${ECHO_MSG} "====> of GNU Emacs and is therefore not supported by GNU"
	@${ECHO_MSG} "====> Emacs development team."
.endif
	@${ECHO_MSG}

.include <bsd.port.post.mk>
