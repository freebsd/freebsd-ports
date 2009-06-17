# New ports collection makefile for:    emacs22
# Date created:				April 12 2005
# Whom:	      				Kenneth Vestergaard Schmidt <kvs@pil.dk>
#
# $FreeBSD$
#

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}
CATEGORIES=	editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	emacs/pretest

MAINTAINER=	keramida@ceid.upatras.gr
COMMENT=	GNU editing macros

.if !defined(WITHOUT_X11)
USE_XORG=	x11
.if defined(WITHOUT_GTK)
USE_XORG+=	xaw xft xpm
.else
USE_GNOME=	gtk20
.endif
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png
.endif

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	emacs-19.* emacs-21.* emacs-22.* \
		xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]*

INSTALLS_ICONS=	yes

EMACS_VER=	23.0.94
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	bootstrap

CONFIGURE_TARGET=	${MACHINE_ARCH}-freebsd
.if defined(WITHOUT_X11)
CONFIGURE_ARGS=		--with-x=no
.else
.if !defined(WITHOUT_GTK)
CONFIGURE_ARGS=		--with-x-toolkit=gtk
.else
CONFIGURE_ARGS=		--with-x-toolkit=athena
.endif
CONFIGURE_ARGS+=	--enable-font-backend
LIB_DEPENDS+=		freetype.9:${PORTSDIR}/print/freetype2 \
			m17n.3:${PORTSDIR}/devel/m17n-lib
# also libotf, which is pulled in by m17n

# m17n depends on libintl.so too
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
USE_GETTEXT=	yes
.endif

.if defined(WITHOUT_XIM)
CONFIGURE_ARGS+=	--without-xim
.endif

MAN1=		b2m.1 ctags.1 ebrowse.1 emacs.1 emacsclient.1 etags.1 \
		grep-changelog.1 rcs-checkin.1
PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${CONFIGURE_TARGET}

MAKE_ENV=	LC_ALL=C

INFO=		ada-mode auth autotype calc ccmode cl dbus dired-x \
		ebrowse ediff efaq eintr elisp emacs-mime emacs epa \
		erc eshell eudc flymake forms gnus idlwave info \
		mairix-el message mh-e newsticker nxml-mode \
		org pcl-cvs pgg rcirc reftex remember sasl sc ses sieve \
		smtpmail speedbar tramp url vip viper widget woman

LATEST_LINK=	emacs23

OPTIONS=	SOURCES	"Install source code"	ON

.include <bsd.port.pre.mk>

.if defined(WITH_SOURCES)
PLIST_SUB+=	SOURCES=""
.else
PLIST_SUB+=	SOURCES="@comment "
.endif

.if ${ARCH} == "ia64"
BROKEN=	Emacs 22.X and later does not currently build on ia64
.endif

pre-everything::
.if !defined(WITHOUT_X11) && !defined(WITHOUT_GTK)
	@${ECHO_MSG} "====>"
	@${ECHO_MSG} "====> To disable GTK+ interface support, define WITHOUT_X11 or WITHOUT_GTK"
	@${ECHO_MSG} "====>"
.endif
.if !defined(WITHOUT_X11) && !defined(WITHOUT_XIM)
	@${ECHO_MSG} "====>"
	@${ECHO_MSG} "====> To disable X11 Input Method support, define WITHOUT_XIM"
	@${ECHO_MSG} "====>"
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
