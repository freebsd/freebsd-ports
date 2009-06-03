# New ports collection makefile for:	tgif-j
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tgif-resource
PORTVERSION=	4.1.45
PORTREVISION=	6
CATEGORIES=	japanese graphics
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese Resource and Configuration for TGIF

RUN_DEPENDS=	tgif:${PORTSDIR}/graphics/tgif \
		${LOCALBASE}/share/fonts/TTF/ipagui.ttf:${PORTSDIR}/japanese/font-ipa-uigothic \
		${LOCALBASE}/share/fonts/std.ja_JP/Ryumin-Light:${PORTSDIR}/japanese/font-std

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_XORG=	x11
PLIST_SUB=	XAPPLRESDIR=${XAPPLRESDIR}

XAPPLRESDIR=	lib/X11/ja_JP.eucJP/app-defaults

do-install:
	${MKDIR} ${PREFIX}/${XAPPLRESDIR}
	${INSTALL_DATA} ${FILESDIR}/Tgif.in ${PREFIX}/${XAPPLRESDIR}/Tgif.ja-dist
	if ! test -r ${PREFIX}/${XAPPLRESDIR}/Tgif; then \
		${INSTALL_DATA} ${FILESDIR}/Tgif.in \
			${PREFIX}/${XAPPLRESDIR}/Tgif; \
	fi

.include <bsd.port.mk>
