# Created by: Mita Yoshio <mita@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	tgif
PORTVERSION=	4.2.2
PORTREVISION=	1
CATEGORIES=	japanese graphics
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-resource
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese Resource and Configuration for TGIF

RUN_DEPENDS=	tgif:graphics/tgif \
		${LOCALBASE}/share/fonts/TTF/ipagui.ttf:japanese/font-ipa-uigothic \
		${LOCALBASE}/share/fonts/std.ja_JP/Ryumin-Light:japanese/font-std

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		xorg
USE_XORG=	x11
PLIST_SUB=	XAPPLRESDIR=${XAPPLRESDIR}

XAPPLRESDIR=	lib/X11/ja_JP.eucJP/app-defaults

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${XAPPLRESDIR}
	${INSTALL_DATA} ${FILESDIR}/Tgif.in \
	    ${STAGEDIR}${PREFIX}/${XAPPLRESDIR}/Tgif.sample

.include <bsd.port.mk>
