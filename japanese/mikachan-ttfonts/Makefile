# New ports collection makefile for:	TrueTypeFont Mika-chan
# Date created:		12 October 2002
# Whom:			sada
# Based on:		KANOU Hiroki's kochi-ttfonts
#
# $FreeBSD$
#

PORTNAME=	mikachan-ttfonts
PORTVERSION=	8.7
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://members.tripod.co.jp/mikachan_font/ \
		${MASTER_SITE_PORTS_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ver${PORTVERSION}
EXTRACT_SUFX=	.lzh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Handwritten Japanese TrueType fonts by Mika-chan

EXTRACT_DEPENDS=	lha:${PORTSDIR}/archivers/lha

NO_CDROM=	"Don't sell distfile"
EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	pq
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/mika.ttf
DIST_SUBDIR=	${PORTNAME}
USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

FONTSDIR=	lib/X11/fonts/TrueType

do-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${INSTALL_DATA} \
		${WRKDIR}/mika.ttf ${FILESDIR}/fonts.dir.mika \
		${PREFIX}/${FONTSDIR}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
