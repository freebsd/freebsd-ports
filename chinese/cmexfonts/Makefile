# New ports collection makefile for:   cmexfonts
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	cmexfonts
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/fonts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Big5+ Chinese Mingti bitmap font (by CMEX & DynaLab) for X11

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_XORG=	x11
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/cmexfonts

post-install:
	@${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
