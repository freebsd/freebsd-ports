# New ports collection makefile for:	tgif-j
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tgif-resource
PORTVERSION=	4.1.45
CATEGORIES=	japanese graphics
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	mita@FreeBSD.org
COMMENT=	Japanese Resource and Configuration for TGIF

RUN_DEPENDS=	tgif:${PORTSDIR}/graphics/tgif \
		${LOCALBASE}/share/ipa-ttfonts/fonts/ipag.ttf:${PORTSDIR}/japanese/ipa-ttfonts

BROKEN=		Wrong plist

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
PLIST_SUB=	XAPPLRESDIR=${XAPPLRESDIR}

XAPPLRESDIR=	lib/X11/ja_JP.eucJP/app-defaults

do-install:
	${MKDIR} ${PREFIX}/${XAPPLRESDIR}
	${INSTALL_DATA} ${FILESDIR}/Tgif.in ${PREFIX}/${XAPPLRESDIR}/Tgif.ja-dist
.if !exists(${PREFIX}/${XAPPLRESDIR}/Tgif)
	${INSTALL_DATA} ${FILESDIR}/Tgif.in ${PREFIX}/${XAPPLRESDIR}/Tgif
.endif

.include <bsd.port.mk>
