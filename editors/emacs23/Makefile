# New ports collection makefile for:	GNU emacs
# Date created:		11 October 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}
PORTEPOCH=	1
CATEGORIES=	editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wahjava@gmail.com
COMMENT=	GNU editing macros

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	emacs-19.* emacs-21.* emacs-22.* \
		xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]*

INSTALLS_ICONS=	yes

EMACS_VER=	23.2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

USE_GETTEXT=	yes

MAN1=		b2m.1 ctags.1 ebrowse.1 emacs.1 emacsclient.1 etags.1 \
		grep-changelog.1 rcs-checkin.1
PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${CONFIGURE_TARGET}

MAKE_ENV=	LC_ALL=C

INFO=		ada-mode auth autotype calc ccmode cl dbus dired-x \
		ebrowse ede ediff edt efaq eieio eintr elisp emacs-mime emacs epa \
		erc eshell eudc flymake forms gnus idlwave info \
		mairix-el message mh-e newsticker nxml-mode \
		org pcl-cvs pgg rcirc reftex remember sasl sc semantic ses sieve \
		smtpmail speedbar tramp url vip viper widget woman

OPTIONS=	DBUS	"DBus support"			ON \
		GCONF	"GConf support"			ON \
		GIF	"GIF support"			ON \
		GTK2	"GTK+ support"			ON \
		JPEG	"JPEG support"			ON \
		M17N	"M17N support for text-shaping"	ON \
		MOTIF	"Motif support"			OFF \
		OTF	"Opentype Font"			ON \
		PNG	"PNG support"			ON \
		SOUND	"Sound support"			ON \
		SOURCES	"Install source code"		ON \
		SVG	"SVG support"			ON \
		TIFF	"TIFF support"			ON \
		X11	"X11 support"			ON \
		XAW	"XAW support"			OFF \
		XAW3D	"XAW3D support"			OFF \
		SYNC_INPUT	"Synchronously process asynchronous input"	ON \
		SCROLLBARS	"Without toolkit scroll-bars"			ON \
		XFT	"Xft support"			ON \
		XIM	"XIM support"			ON \
		XPM	"XPM support"			ON

.include <bsd.port.options.mk>

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
.else
USE_XORG=	x11
USE_GNOME=

.if defined(WITHOUT_SVG)
CONFIGURE_ARGS+=	--without-rsvg
.else
USE_GNOME+=	librsvg2
.endif

.if defined(WITHOUT_GTK2)
.if defined(WITH_XAW)
.if defined(WITH_XAW3D) || defined(WITH_MOTIF)
IGNORE=	please choose only one toolkit: GTK+/Motif/Xaw/Xaw3d
.endif
USE_XORG=	xaw
CONFIGURE_ARGS+=	--with-x-toolkit=athena --without-xaw3d
.elif defined(WITH_XAW3D)
.if defined(WITH_MOTIF)
IGNORE=	please choose only one toolkit: GTK+/Motif/Xaw/Xaw3d
.endif
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.elif defined(WITH_MOTIF)
USE_MOTIF=	yes
CONFIGURE_ARGS+=	--with-x-toolkit=motif
.else
IGNORE=	please choose a toolkit: GTK+/Motif/Xaw/Xaw3d, or build without X11 support
.endif
.else
.if defined(WITH_XAW) || defined(WITH_XAW3D) || defined(WITH_MOTIF)
IGNORE=	please choose only one toolkit: GTK+/Motif/Xaw/Xaw3d
.endif
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-x-toolkit=gtk
.endif

.if defined(WITHOUT_SCROLLBARS)
CONFIGURE_ARGS+=	--without-toolkit-scroll-bars
.endif

.if defined(WITHOUT_SOUND)
CONFIGURE_ARGS+=	--without-sound
.endif

.if defined(WITHOUT_SYNC_INPUT)
CONFIGURE_ARGS+=	--without-sync-input
.endif

.if defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=	--without-jpeg
.else
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
.endif

.if defined(WITHOUT_TIFF)
CONFIGURE_ARGS+=	--without-tiff
.else
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.endif

.if defined(WITHOUT_GIF)
CONFIGURE_ARGS+=	--without-gif
.else
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--without-png
.else
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
.endif

.if defined(WITHOUT_XPM)
CONFIGURE_ARGS+=	--without-xpm
.else
USE_XORG+=	xpm
.endif

.if defined(WITHOUT_XFT)
.if defined(WITH_M17N)
IGNORE=	m17n support requires Xft. Please run 'make config'
.elif defined(WITH_OTF)
IGNORE=	otf support requires Xft. Please run 'make config'
.else
CONFIGURE_ARGS+=	--without-xft
.endif
.else
USE_XORG+=	xft
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.endif

.if defined(WITHOUT_M17N)
CONFIGURE_ARGS+=	--without-m17n-flt
CONFIGURE_ENV+=		LDFLAGS="-L${LOCALBASE}/lib"
.else
.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=	m17n.4:${PORTSDIR}/devel/m17n-lib
.endif
CONFIGURE_ENV+=		LDFLAGS="-L${LOCALBASE}/lib -lintl"
.endif

.if defined(WITHOUT_OTF)
CONFIGURE_ARGS+=	--without-libotf
.else
.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=	otf.0:${PORTSDIR}/print/libotf
.endif
.endif

.if defined(WITHOUT_GCONF)
CONFIGURE_ARGS+=	--without-gconf
.else
USE_GNOME+=	gconf2
.endif

.if defined(WITHOUT_XIM)
CONFIGURE_ARGS+=	--without-xim
.endif

.endif

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=	--without-dbus
.else
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
.endif

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SOURCES)
PLIST_SUB+=	SOURCES="@comment "
.else
PLIST_SUB+=	SOURCES=""
.endif

.if ${ARCH} == "ia64"
BROKEN=	Emacs 22.X does not currently build on ia64
.endif

post-patch:
	@${RM} -f ${WRKSRC}/info/*
	@${REINPLACE_CMD} -e "s/%%EMACS_VER%%/${EMACS_VER}/g" -e "s/%%DATADIR%%/${DATADIR:C/\//\\\//g}/g" ${WRKSRC}/sources.el

.if defined(WITH_SOURCES)
post-install:
	@${MKDIR} ${DATADIR}/${EMACS_VER}/src
	@${INSTALL_DATA} ${WRKSRC}/src/*.[ch] ${DATADIR}/${EMACS_VER}/src
	@${INSTALL_DATA} ${WRKSRC}/sources.el ${DATADIR}/${EMACS_VER}/site-lisp/site-start.el
.endif

.include <bsd.port.post.mk>
