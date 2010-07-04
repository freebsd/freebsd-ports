# New ports collection makefile for:	squeezeboxserver-lazysearch
# Date created:		21 June 2008
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lazysearch
PORTVERSION=	3.5.6
CATEGORIES=	audio
MASTER_SITES=	http://www.hickinbottom.com/sc-plugins/
PKGNAMEPREFIX=	squeezeboxserver-
DISTNAME=	LazySearch2-7-${PORTVERSION}
DIST_SUBDIR=	squeezeboxserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Squeezebox Server plugin for performing lazy searches

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/squeezeboxserver

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	squeezeboxserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/LazySearch2
	${CP} -R ${WRKSRC}/LazySearch2/* ${PREFIX}/${SLIMDIR}/Plugins/LazySearch2

.include <bsd.port.mk>
