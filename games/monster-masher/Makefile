# New ports collection makefile for:	Monster-Masher
# Date created:			26 Oct 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	monster
PORTVERSION=	1.4
CATEGORIES=	games gnome
MASTER_SITES=	http://www.cs.auc.dk/~olau/monster-masher/source/
PKGNAMESUFFIX=	-masher
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	einekoai@chello.nl
COMMENT=	Gnomemm puzzle game where you have to clean the caves of monsters

LIB_DEPENDS=	gnomeuimm-2.0:${PORTSDIR}/x11-toolkits/libgnomeuimm

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500010
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src-vector.hpp
.endif

.include <bsd.port.post.mk>
