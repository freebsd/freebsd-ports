# New ports collection makefile for:	Monster-Masher
# Date created:			26 Oct 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	monster
PORTVERSION=	1.7
PORTREVISION=	6
CATEGORIES=	games gnome
MASTER_SITES=	http://www.cs.aau.dk/~olau/monster-masher/source/
PKGNAMESUFFIX=	-masher
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnomemm puzzle game where you have to clean the caves of monsters

LIB_DEPENDS=	gnomeuimm-2.6.1:${PORTSDIR}/x11-toolkits/libgnomeuimm26

USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	monster-masher.schemas

.include <bsd.port.mk>
