# New ports collection makefile for:	species
# Date created:				2008-01-15
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	species
PORTVERSION=	1.2d
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver
DISTNAME=	redcoder

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Corewars evolver - generates warriors using genetic algorithms

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	VISITOOL "Buil GUI tool for displaying evolution" off

.include <bsd.port.pre.mk>

.if defined(WITH_VISITOOL)
USE_WX=		2.4
ALL_TARGET=	all visitool
PLIST_SUB+=	VISITOOL=""
.else
PLIST_SUB+=	VISITOOL="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} koen.* species.ini *.rc ${DATADIR}
	cd ${WRKSRC} && ${CP} -r bench evolver_hill wilfiz ${DATADIR}
.if defined(WITH_VISITOOL)
	${INSTALL_PROGRAM} ${WRKSRC}/visitool \
		${PREFIX}/bin/${PORTNAME}-visitool
.endif

.include <bsd.port.post.mk>
