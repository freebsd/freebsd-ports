# New ports collection makefile for:	zh-xemacs21
# Date created:		1 October 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	chinese editors

MAINTAINER=	keith@FreeBSD.org

COMMENT=	${.CURDIR}/pkg-comment
PLIST=		${.CURDIR}/pkg-plist
PKGMESSAGE=	${.CURDIR}/pkg-message

XEMACS_MAJOR_VER=	21
WITH_XIM=	xlib
BUILD_INPUT_METHOD=	xcin2.5:${PORTSDIR}/chinese/xcin25

# xemacs21-mule-common needs this.
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/../../editors/xemacs21-mule/work

post-install::
	@${MKDIR} ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${INSTALL_DATA} ${.CURDIR}/../xemacs/files/Emacs ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${INSTALL_DATA} ${.CURDIR}/../xemacs/files/sample.emacs ${PREFIX}/lib/xemacs-${XEMACS_VER}/etc/app-defaults/zh_TW.Big5
	@${CAT} ${PKGMESSAGE}

.include	"${.CURDIR}/../../editors/xemacs21-mule/Makefile"
