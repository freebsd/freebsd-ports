# New ports collection makefile for:    emacs22
# Date created:				April 12 2005
# Whom:	      				Kenneth Vestergaard Schmidt <kvs@pil.dk>
#
# $FreeBSD$
#

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}.${SNAPSHOT}
CATEGORIES=	editors ipv6
MASTER_SITES=	http://dl.droso.net/FreeBSD/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	erwin/kvs
DISTNAME=	${PORTNAME}-cvs-snapshot-2006-02-28

MAINTAINER=	kvs@pil.dk
COMMENT=	GNU editing macros

.if !defined(WITHOUT_X11)
.if defined(WITHOUT_GTK)
LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png
.endif

CONFLICTS=	emacs-19.* emacs-21.* \
		xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]*

EMACS_VER=	22.0.50
SNAPSHOT=	20060228
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:259
.if !defined(WITHOUT_X11)
.if !defined(WITHOUT_GTK)
USE_GNOME=	gtk20
.else
USE_XLIB=	yes
.endif
USE_XPM=	yes
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}

CONFIGURE_TARGET=	${MACHINE_ARCH}--freebsd
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

INFO=		ada-mode autotype calc ccmode cl dired-x ebrowse ediff \
		efaq eintr elisp emacs emacs-mime emacs-xtra eshell eudc \
		flymake forms gnus idlwave info message mh-e newsticker \
		org pcl-cvs pgg reftex sc ses sieve smtpmail speedbar tramp \
		url vip viper widget woman rcirc erc

LATEST_LINK=	emacs22

pre-build:
	(cd ${WRKSRC} ; make bootstrap)

.include <bsd.port.mk>
