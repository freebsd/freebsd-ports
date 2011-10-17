# New ports collection makefile for:	GNU emacs
# Date created:		11 October 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}
PORTREVISION=	6
PORTEPOCH=	2
CATEGORIES=	editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}a

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GNU editing macros

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	emacs-19.* emacs-21.* emacs-22.* emacs-24.* \
		xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]* \
		emacs-nox11-[0-9]*

EMACS_VER=	23.3
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

OPTIONS=	CANNA	"Canna support"			OFF \
		DBUS	"DBus support"			ON \
		GCONF	"GConf support"			ON \
		GIF	"GIF images support"		ON \
		GTK2	"Use GTK+ widgets"		ON \
		JPEG	"JPEG images support"		ON \
		M17N	"M17N support for text-shaping"	ON \
		MOTIF	"Use Motif widgets"		OFF \
		OTF	"Opentype fonts support"	ON \
		PNG	"PNG images support"		ON \
		SOUND	"Sound support"			ON \
		SOURCES	"Install source code"		ON \
		SVG	"SVG images support"		ON \
		TIFF	"TIFF images support"		ON \
		XAW	"Use Athena widgets"		OFF \
		XAW3D	"Use Athena3D widgets"		OFF \
		SYNC_INPUT	"Synchronously process asynchronous input"	ON \
		SCROLLBARS	"Without toolkit scroll-bars"			ON \
		XFT	"Freetype fonts support"	ON \
		XIM	"X Input Method support"	ON \
		XPM	"XPM images support"		ON

.include <bsd.port.options.mk>

DBUS_PTHREAD_LIBS=	${CC} -dumpspecs | ${GREP} -m 1 pthread: | ${SED} -e 's|^.*%{\!pg: %{pthread:||' -e 's|}.*$$||' || ${TRUE}

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
INSTALLS_ICONS=	yes
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-x-toolkit=gtk
.endif

.if defined(WITHOUT_SCROLLBARS)
CONFIGURE_ARGS+=	--without-toolkit-scroll-bars
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
. if exists(${LOCALBASE}/lib/libgif.so)
LIB_DEPENDS+=	gif.5:${PORTSDIR}/graphics/giflib
. else
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
. endif
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
.else
.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=	m17n.4:${PORTSDIR}/devel/m17n-lib
.endif
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

.if defined(WITH_CANNA)
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

.if defined(WITHOUT_SOUND)
CONFIGURE_ARGS+=	--without-sound
.endif

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=	--without-dbus
.else
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
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
