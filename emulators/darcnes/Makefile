# New ports collection makefile for:   darcnes
# Date created:        22 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcnes
PORTVERSION=	9b0401
CATEGORIES=	emulators
MASTER_SITES=	http://www.dridus.com/~nyef/darcnes/download/
DISTNAME=	dn${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nakai@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_CDROM=	Commercial use is restricted

USE_X_PREFIX=	yes
USE_GMAKE=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/darcnes ${PREFIX}/bin

.include <bsd.port.mk>
