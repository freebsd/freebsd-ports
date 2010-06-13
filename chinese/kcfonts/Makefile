# New ports collection makefile for:	kcfonts
# Date Created:				5 Dec 1997
# Whom:					Ming-I Hseh <PA@FreeBSD.Ntu.edu.TW>
#
# $FreeBSD$
#

PORTNAME=	kcfonts
PORTVERSION=	1.05
PORTREVISION=	2
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kuo Chauo Chinese Fonts collection

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not build on sparc64
.endif

NO_WRKSUBDIR=	yes

.include <bsd.port.post.mk>
