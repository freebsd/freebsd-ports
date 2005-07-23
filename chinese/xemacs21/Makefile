# New ports collection makefile for:	zh-xemacs21
# Date created:		1 October 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	chinese

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XEmacs text editor version 21, with XIM support and Big5 settings

PLIST=		${.CURDIR}/pkg-plist
PKGMESSAGE=	${.CURDIR}/pkg-message

BROKEN=		Incorrect pkg-plist
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

XEMACS_MAJOR_VER=	21
WITH_XIM=	--with-xim=xlib
BUILD_INPUT_METHOD=	xcin2.5:${PORTSDIR}/chinese/xcin25

# xemacs21-mule-common needs this.
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/../../editors/xemacs21-mule/work

SLAVE_PORT=	yes
MASTER_PORT=	editors/xemacs21-mule

post-install::
	@${MKDIR} ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${INSTALL_DATA} ${.CURDIR}/../xemacs/files/Emacs ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${INSTALL_DATA} ${.CURDIR}/../xemacs/files/sample.emacs ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${CAT} ${PKGMESSAGE}

.include	"${.CURDIR}/../../editors/xemacs21-mule/Makefile"
