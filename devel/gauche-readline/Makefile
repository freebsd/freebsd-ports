# New ports collection makefile for:	Gauche Readline
# Date created:		15 Jan 2004
# Whom:			Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	readline
PORTVERSION=	0.1
CATEGORIES=	devel scheme
MASTER_SITES=	http://www.shiro.dreamhost.com/scheme/vault/
PKGNAMEPREFIX=	gauche-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	gauche

MAINTAINER=	erik@smluc.org
COMMENT=	A pure gauche/scheme implementation of the Readline library

RUN_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
BUILD_DEPENDS=	gauche-config:${PORTSDIR}/lang/gauche

.include <bsd.port.pre.mk>
GAUCHE_CONFIG=	${LOCALBASE}/bin/gauche-config
GAUCHE_LIBDIR=	${GAUCHE_CONFIG} --sitelibdir
PLIST_SUB+=	GAUCHE_LIBDIR=${GAUCHE_LIBDIR:S/${LOCALBASE}\///}

do-install:
	@${CP} -r ${WRKSRC}/readline* ${GAUCHE_LIBDIR}

.include <bsd.port.post.mk>
