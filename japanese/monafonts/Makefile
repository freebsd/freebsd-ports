# New ports collection makefile for:	monafonts
# Date created:		14 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	monafonts
PORTVERSION=	2.03
PORTEPOCH=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://members.tripod.co.jp/s42335/mona/dist/
EXTRACT_SUFX=	.tar.bz2.bin

MAINTAINER=	nobutaka@FreeBSD.org

FONTSDIR=	lib/X11/fonts/local
USE_BZIP2=	yes
USE_X_PREFIX=	yes
ALL_TARGET=	bdf
.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

PLIST_SUB=	FONTSDIR=${FONTSDIR}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

.include <bsd.port.post.mk>
