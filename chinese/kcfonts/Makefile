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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kuo Chauo Chinese Fonts collection

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not build on sparc64"
.endif

NO_WRKSUBDIR=	yes

.include <bsd.port.post.mk>
