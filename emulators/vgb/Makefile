# New ports collection makefile for:   vgb
# Date created:        31 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	vgb
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	VGB
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo GameBoy(tm) emulator

DEPRECATED=     Distfile is no more available (lastest binaries provided by upstream are for 5.x)
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/GB

USE_XORG=	x11 xext

do-configure:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' ${FILESDIR}/vgb.sh \
		> ${WRKSRC}/vgb.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gblist ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/libexec/VGB ${PREFIX}/share/VGB
	${INSTALL_PROGRAM} ${WRKSRC}/vgb ${PREFIX}/libexec/VGB
	${INSTALL_DATA} ${WRKSRC}/CART.GB ${PREFIX}/share/VGB
	${INSTALL_SCRIPT} ${WRKSRC}/vgb.sh ${PREFIX}/bin/vgb

.include <bsd.port.mk>
