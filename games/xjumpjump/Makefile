# New ports collection makefile for:	xjumpjump
# Version required:			0.12
# Date created:				9 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	xjumpjump
PKGNAME=	xjumpjump-0.12
CATEGORIES=	games
MASTER_SITES=	http://makosteszta.sote.hu/linux/jumpjump/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms

USE_X_PREFIX=	yes

pre-build:
	@ ${RM} ${WRKSRC}/xjumpjump

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xjumpjump ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xjumpjump
	@ ${INSTALL_DATA} ${WRKSRC}/READ.ME ${PREFIX}/share/xjumpjump
	@ ${INSTALL_DATA} ${WRKSRC}/OLVASS.EL ${PREFIX}/share/xjumpjump

.include <bsd.port.mk>
