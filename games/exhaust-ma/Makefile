# New ports collection makefile for:	games/exhaust-ma
# Date created:			7 Aug 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	exhaust-ma
PORTVERSION=	1.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Redcode simulator easy to embed into applications

USE_ZIP=	yes
USE_GMAKE=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|||'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exhaust ${PREFIX}/bin/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
