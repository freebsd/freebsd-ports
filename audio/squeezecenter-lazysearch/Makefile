# New ports collection makefile for:	squeezecenter-lazysearch
# Date created:		21 June 2008
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lazysearch
PORTVERSION=	3.0
CATEGORIES=	audio
# Distfile mirrored due to being unversioned on author's site
MASTER_SITES=	ftp://ftp.i-scream.org/pub/slimserver/${PORTNAME}/ \
		http://ftp.i-scream.org/pub/slimserver/${PORTNAME}/
PKGNAMEPREFIX=	squeezecenter-
DIST_SUBDIR=	squeezecenter

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SqueezeCenter plugin for performing lazy searches

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/squeezecenter

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	squeezecenter
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/LazySearch2
	${CP} -R ${WRKSRC}/LazySearch2/* ${PREFIX}/${SLIMDIR}/Plugins/LazySearch2

.include <bsd.port.mk>
