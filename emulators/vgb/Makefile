# New ports collection makefile for:   vgb
# Version required:    0.7
# Date created:        31 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	VGB
PKGNAME=	vgb-0.7
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	nakai@FreeBSD.org

WRKSRC=		${WRKDIR}/GB

USE_X_PREFIX=	yes
CONFIGURE_ENV=  X11BASE=${X11BASE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gblist ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/libexec/VGB ${PREFIX}/share/VGB
	@${INSTALL_PROGRAM} ${WRKSRC}/vgb ${PREFIX}/libexec/VGB
	@${INSTALL_DATA} ${WRKSRC}/CART.GB ${PREFIX}/share/VGB
	@${INSTALL_SCRIPT} ${WRKSRC}/vgb.sh ${PREFIX}/bin/vgb

.include <bsd.port.mk>
