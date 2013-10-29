# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	wolfendoom
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.ijs.si/~lesi/distfiles/doom/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wolfenstein 3D levels ported to Doom II

USE_BZIP2=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${DMDIR}/${PORTNAME}

NO_STAGE=	yes
.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

do-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKDIR}/${PORTNAME}
	${FIND} ${WRKDIR}/${PORTNAME} ! -type d -exec ${CHMOD} 0644 {} \;
	${FIND} ${WRKDIR}/${PORTNAME} -type d -exec ${CHMOD} 0755 {} \;
	${MKDIR} ${DATADIR}
	${TAR} -cf - -C ${WRKDIR}/${PORTNAME} . | ${TAR} -xpvf - -C ${DATADIR}

.include <bsd.port.post.mk>
