# New ports collection makefile for:	GNU emacs
# Date created:		11 October 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}
PORTREVISION?=	2
CATEGORIES=	editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GNU editing macros

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	emacs-19.* emacs-21.* emacs-22.* emacs-24.* \
		xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]* \
		emacs-nox11-[0-9]*

EMACS_VER=	23.4
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_NCURSES=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=/var
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		b2m.1 ctags.1 ebrowse.1 emacs.1 emacsclient.1 etags.1 \
		grep-changelog.1 rcs-checkin.1
PLIST_SUB=	EMACS_VER=${EMACS_VER}

EMACS_DIRS=	${DATADIR}/${EMACS_VER}/leim ${DATADIR}/${EMACS_VER}/lisp ${DATADIR}/${EMACS_VER}/src \
		${PREFIX}/libexec/${PORTNAME}

MAKE_ENV=	LC_ALL=C

INFO=		ada-mode auth autotype calc ccmode cl dbus dired-x \
		ebrowse ede ediff edt efaq eieio eintr elisp emacs-mime emacs epa \
		erc eshell eudc flymake forms gnus idlwave info \
		mairix-el message mh-e newsticker nxml-mode \
		org pcl-cvs pgg rcirc reftex remember sasl sc semantic ses sieve \
		smtpmail speedbar tramp url vip viper widget woman

OPTIONS_DEFINE=	CANNA DBUS GCONF GIF JPEG M17N OTF PNG SOUND SOURCES SVG TIFF SYNC_INPUT SCROLLBARS XFT \
		XIM XPM

OPTIONS_SINGLE=	X11TOOLKIT

CANNA_DESC=		Canna support
SCROLLBARS_DESC=	Toolkit scroll-bars
SOUND_DESC=		Sound support
SOURCES_DESC=		Install sources
SYNC_INPUT_DESC=	Synchronously process asynchronous input
XAW_DESC=		Athena widgets
XAW3D_DESC=		Athena3D widgets
XIM_DESC=		X Input Method Support
M17N_DESC=		M17N support for text-shaping
OTF_DESC=		Opentype fonts suport

OPTIONS_SINGLE_X11TOOLKIT=	GTK2 XAW XAW3D MOTIF

OPTIONS_DEFAULT=DBUS GCONF GIF GTK2 JPEG M17N OTF PNG SOUND SOURCES SVG TIFF SYNC_INPUT \
		SCROLLBARS XFT XIM XPM

.include <bsd.port.options.mk>

DBUS_PTHREAD_LIBS=	${CC} -dumpspecs | ${GREP} -m 1 pthread: | ${SED} -e 's|^.*%{\!pg: %{pthread:||' -e 's|}.*$$||' || ${TRUE}

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x

.else
USE_XORG=	x11
USE_GNOME=

.if ${PORT_OPTIONS:MSVG}
USE_GNOME+=	librsvg2
.else
CONFIGURE_ARGS+=	--without-rsvg
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-x-toolkit=gtk
.elif ${PORT_OPTIONS:MXAW3D}
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.elif ${PORT_OPTIONS:MXAW}
USE_XORG=	xaw
CONFIGURE_ARGS+=	--with-x-toolkit=athena --without-xaw3d
.elif ${PORT_OPTIONS:MMOTIF}
USE_MOTIF=	yes
CONFIGURE_ARGS+=	--with-x-toolkit=motif
.endif

.if !${PORT_OPTIONS:MSCROLLBARS}
CONFIGURE_ARGS+=	--without-toolkit-scroll-bars
.endif

.if !${PORT_OPTIONS:MSYNC_INPUT}
CONFIGURE_ARGS+=	--without-sync-input
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
.else
CONFIGURE_ARGS+=	--without-jpeg
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

.if ${PORT_OPTIONS:MGIF}
LIB_DEPENDS+=	gif.5:${PORTSDIR}/graphics/giflib
.else
CONFIGURE_ARGS+=	--without-gif
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if ${PORT_OPTIONS:MXPM}
USE_XORG+=	xpm
.else
CONFIGURE_ARGS+=	--without-xpm
.endif

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-xft
.if ${PORT_OPTIONS:MM17N}
CONFIGURE_ARGS+=	--with-m17n-flt
LIB_DEPENDS+=	m17n.4:${PORTSDIR}/devel/m17n-lib
.else
CONFIGURE_ARGS+=	--without-m17n-flt
.endif
.if ${PORT_OPTIONS:MOTF}
CONFIGURE_ARGS+=	--with-otf
LIB_DEPENDS+=	otf.0:${PORTSDIR}/print/libotf
.else
CONFIGURE_ARGS+=	--without-libotf
.endif
.else
CONFIGURE_ARGS+=	--without-xft
.if ${PORT_OPTIONS:MM17N}
IGNORE=	m17n support for text-shaping requires Xft. Please run 'make config'
.elif ${PORT_OPTIONS:MOTF}
IGNORE=	opentype fonts support requires Xft. Please run 'make config'
.endif
CONFIGURE_ARGS+=	--without-otf --without-m17n-flt
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
.else
CONFIGURE_ARGS+=	--without-gconf
.endif

.if !${PORT_OPTIONS:MXIM}
CONFIGURE_ARGS+=	--without-xim
.endif

.if ${PORT_OPTIONS:MCANNA}
PATCH_SITES+=	http://distfiles.pirateparty.in/%SUBDIR%/ ${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR+=	ashish
PATCHFILES+=	emacs23.3canna-20110316.diff.gz
PATCH_DIST_STRIP=	-p1
CONFIGURE_ARGS+=	--with-canna \
			--with-canna-includes=${LOCALBASE}/include \
			--with-canna-libraries=${LOCALBASE}/lib
LIB_DEPENDS+=		canna.1:${PORTSDIR}/japanese/canna-lib
.endif

.endif

.if ${PORT_OPTIONS:MSOUND}
CONFIGURE_ARGS+=	--with-sound
.else
CONFIGURE_ARGS+=	--without-sound
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--with-dbus
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=	Emacs 23.X does not currently build on ia64
.endif

post-patch:
	@${RM} -f ${WRKSRC}/info/*
	@${REINPLACE_CMD} -e "s/%%EMACS_VER%%/${EMACS_VER}/g" -e "s/%%DATADIR%%/${DATADIR:C/\//\\\//g}/g" ${WRKSRC}/sources.el
.if defined(WITHOUT_X11)
	@${REINPLACE_CMD} -e 's/^Terminal=.*$$/Terminal=true/' ${WRKSRC}/etc/emacs.desktop
.endif

post-configure:
	@${REINPLACE_CMD} -e "s/^\(DBUS_LIBS.*\)-pthread\(.*\)$$/\1$$(${DBUS_PTHREAD_LIBS})\2/" ${WRKSRC}/src/Makefile

add-plist-data:
.for i in ${EMACS_DIRS}
	@${FIND} ${i} -type f |${SED} -E -e 's,^${PREFIX}/,,g'  >>${TMPPLIST}
.endfor
	@${FIND} ${WRKSRC}/etc -type f |${SED} -E -e 's,^${WRKSRC},${DATADIR_REL}/${EMACS_VER},g' -e '/etc\/(\..*|ChangeLog|DOC)$$/d' >>${TMPPLIST}
	@${FIND} ${WRKSRC}/etc -type d -depth |${SED} -E -e 's,^${WRKSRC},@dirrm ${DATADIR_REL}/${EMACS_VER},g' >>${TMPPLIST}
.for i in ${EMACS_DIRS}
	@${FIND} ${i} -type d -depth |${SED} -E -e 's,^${PREFIX}/,@dirrm ,g' >>${TMPPLIST}
.endfor
	@${ECHO} "@unexec rmdir %D/${DATADIR_REL}/${EMACS_VER} 2>/dev/null || true" >>${TMPPLIST}

.if defined(WITH_SOURCES)
PLIST_SUB+=	SOURCES=""

post-install:
	@${MKDIR} ${DATADIR}/${EMACS_VER}/src
	@${INSTALL_DATA} ${WRKSRC}/src/*.[ch] ${DATADIR}/${EMACS_VER}/src
	@${INSTALL_DATA} ${WRKSRC}/sources.el ${DATADIR}/${EMACS_VER}/site-lisp/site-start.el
.else
PLIST_SUB+=	SOURCES="@comment "
.endif

pre-everything::
	@${ECHO_MSG}
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} "====> To disable X11 support, define: WITHOUT_X11."
.endif
.if defined(WITH_CANNA)
	@${ECHO_MSG} "====> Canna support is not part of standard distribution"
	@${ECHO_MSG} "====> of GNU Emacs and is therefore not supported by GNU"
	@${ECHO_MSG} "====> Emacs development team."
.endif
	@${ECHO_MSG}

.include <bsd.port.post.mk>
