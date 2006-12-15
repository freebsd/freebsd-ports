# New ports collection makefile for:	slimserver-lazysearch
# Date created:		10 December 2006
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lazysearch
PORTVERSION=	2.3
CATEGORIES=	audio
# Distfile mirrored due to being unversioned on author's site
MASTER_SITES=	ftp://ftp.i-scream.org/pub/slimserver/${PORTNAME}/ \
		http://ftp.i-scream.org/pub/slimserver/${PORTNAME}/
PKGNAMEPREFIX=	slimserver-
DIST_SUBDIR=	slimserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SlimServer plugin for performing lazy searches

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/slimserver

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	slimserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins
	${INSTALL_DATA} ${WRKSRC}/LazySearch2.pm ${PREFIX}/${SLIMDIR}/Plugins

.include <bsd.port.mk>
