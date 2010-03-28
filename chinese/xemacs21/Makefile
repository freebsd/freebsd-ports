# New ports collection makefile for:	zh-xemacs21
# Date created:		1 October 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	2
CATEGORIES=	chinese

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	XEmacs text editor version 21, with XIM support and Big5 settings

MASTERDIR=	${.CURDIR}/../../editors/xemacs21-mule

PLIST_FILES+=	lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5/Emacs \
		lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5/sample.emacs
PLIST_DIRS+=	lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5 \
		lib/xemacs-${XEMACS_VER}/etc/app-defaults \
		lib/xemacs-${XEMACS_VER}/etc \
		lib/xemacs-${XEMACS_VER}

PKGMESSAGE=	${.CURDIR}/pkg-message

WITH_XCIN25=	yes

post-install::
	@${MKDIR} ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${INSTALL_DATA} ${.CURDIR}/files/Emacs ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${INSTALL_DATA} ${.CURDIR}/files/sample.emacs ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${CAT} ${PKGMESSAGE}

.include	"${MASTERDIR}/Makefile"
