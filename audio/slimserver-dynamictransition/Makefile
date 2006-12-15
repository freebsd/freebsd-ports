# New ports collection makefile for:	slimserver-dynamictransition
# Date created:		07 October 2006
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dynamictransition
PORTVERSION=	1.4
CATEGORIES=	audio
# Distfile mirrored due to being unversioned on author's site
MASTER_SITES=	ftp://ftp.i-scream.org/pub/slimserver/${PORTNAME}/ \
		http://ftp.i-scream.org/pub/slimserver/${PORTNAME}/
PKGNAMEPREFIX=	slimserver-
DISTNAME=	Transitions-${PORTVERSION}
EXTRACT_SUFX=	.pm
DIST_SUBDIR=	slimserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SlimServer plugin for determining transition behaviour between tracks

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/slimserver

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	slimserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins
	${INSTALL_DATA} ${WRKSRC}/Transitions-${PORTVERSION}.pm ${PREFIX}/${SLIMDIR}/Plugins/Transitions.pm

.include <bsd.port.mk>
