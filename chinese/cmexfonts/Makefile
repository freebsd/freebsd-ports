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

MAINTAINER=	statue@freebsd.sinica.edu.tw

USE_X_PREFIX=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

WRKSRC=		${WRKDIR}/cmexfonts

post-install:
	@${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
