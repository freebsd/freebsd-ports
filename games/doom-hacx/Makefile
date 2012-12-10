# New ports collection makefile for:	doom-hacx
# Date created:				21 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	hacx
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.ijs.si/~lesi/distfiles/doom/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.wad
EXTRACT_SUFX=	.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full TC using the Doom II engine

USE_BZIP2=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${DMDIR}/${PORTNAME}

PLIST_FILES=	%%DATADIR%%/${DISTNAME}
PLIST_DIRS=	%%DATADIR%%

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKDIR}
	@${BZIP2_CMD} -dc ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > \
		${WRKDIR}/${DISTNAME}

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${DATADIR}

.include <bsd.port.post.mk>
