# New ports collection makefile for:	kcfonts
# Date Created:				5 Dec 1997
# Whom:					Ming-I Hseh <PA@FreeBSD.Ntu.edu.TW>
#
# $FreeBSD$
#

PORTNAME=	kcfonts
PORTVERSION=	1.05
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/distfiles/ \
		ftp://wm28.csie.ncu.edu.tw/pub/distfiles/

MAINTAINER=	PA@FreeBSD.ee.Ntu.edu.TW

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

NO_WRKSUBDIR=	yes

.include <bsd.port.post.mk>
