# New ports collection makefile for:	xothello
# Version required:			0.01
# Date created:				31 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.5 1998/09/26 23:18:05 steve Exp $
#

DISTNAME=	xothello
PKGNAME=	xothello-0.01
CATEGORIES=	games
MASTER_SITES=	http://makosteszta.sote.hu/linux/othello/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms

NO_CDROM=	Possible trademark infringement

USE_X_PREFIX=	yes

pre-build:
	@ ${RM} ${WRKSRC}/xothello

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xothello ${PREFIX}/bin

.include <bsd.port.mk>
