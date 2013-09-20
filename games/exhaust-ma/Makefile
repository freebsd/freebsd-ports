# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	exhaust-ma
PORTVERSION=	1.9
CATEGORIES=	games
MASTER_SITES=	http://corewar.co.uk/ankerl/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Redcode simulator easy to embed into applications

USE_ZIP=	yes
USE_GMAKE=	yes

NO_WRKSUBDIR=	yes

USE_DOS2UNIX=	yes

PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exhaust ${PREFIX}/bin/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
