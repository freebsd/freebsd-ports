# New ports collection makefile for:	monafonts
# Date created:		14 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	monafonts
PORTVERSION=	20010323
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://members.tripod.co.jp/s42335/mona/
DISTNAME=	mona-${PORTVERSION}

MAINTAINER=	nobutaka@nobutaka.com

FONTSDIR=	lib/X11/fonts/local
USE_X_PREFIX=	yes
USE_GMAKE=	yes
ALL_TARGET=	fonts
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
