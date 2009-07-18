# New ports collection makefile for:	GNU emacs
# Date created:		11 October 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}
PORTREVISION=	1
CATEGORIES=	editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	keramida@ceid.upatras.gr
COMMENT=	GNU editing macros

.if !defined(WITHOUT_X11)
.if defined(WITHOUT_GTK)
LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png
.endif

CONFLICTS=	emacs-19.* emacs-21.* \
		xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]*

EMACS_VER=	22.3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if !defined(WITHOUT_X11)
.if !defined(WITHOUT_GTK)
USE_GNOME=	gtk20
.else
USE_XORG=	x11
.endif
USE_XORG=	xpm xft
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS=		--with-x=no
.else
.if !defined(WITHOUT_GTK)
CONFIGURE_ARGS=		--with-gtk
.endif
.endif

.if defined(WITHOUT_XIM)
CONFIGURE_ARGS+=	--without-xim
.endif

MAN1=		ctags.1 emacs.1 emacsclient.1 etags.1
PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${CONFIGURE_TARGET}

MAKE_ENV=	LC_ALL=C

INFO=		ada-mode autotype calc ccmode cl dired-x ebrowse ediff \
		efaq eintr elisp emacs-mime emacs erc eshell eudc \
		flymake forms gnus idlwave info message mh-e newsticker \
		org pcl-cvs pgg rcirc reftex sc ses sieve smtpmail speedbar \
		tramp url vip viper widget woman

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=	Emacs 22.X does not currently build on ia64
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

.include <bsd.port.post.mk>
