# New ports collection makefile for:   cmexfonts
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	cmexfonts
PORTVERSION=	0.1
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/cmexfonts/ \
		ftp://sunsite.unc.edu/pub/Linux/X11/fonts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Big5+ Chinese Mingti bitmap font (by CMEX & DynaLab) for X11

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/cmexfonts

post-install:
	@${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
