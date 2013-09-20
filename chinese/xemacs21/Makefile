# Created by: Jing-Tang Keith Jang <keith@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	4
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

NO_STAGE=	yes
post-install::
	@${MKDIR} ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${INSTALL_DATA} ${.CURDIR}/files/Emacs ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${INSTALL_DATA} ${.CURDIR}/files/sample.emacs ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${CAT} ${PKGMESSAGE}

.include	"${MASTERDIR}/Makefile"
