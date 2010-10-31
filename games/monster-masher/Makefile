# New ports collection makefile for:	Monster-Masher
# Date created:			26 Oct 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	monster
PORTVERSION=	1.8.1
CATEGORIES=	games gnome
MASTER_SITES=	http://people.iola.dk/olau/monster-masher/source/
PKGNAMESUFFIX=	-masher
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gnomemm puzzle game where you have to clean the caves of monsters

LIB_DEPENDS=	gnomecanvasmm-2.6.1:${PORTSDIR}/graphics/libgnomecanvasmm26 \
		gconfmm-2.6.1:${PORTSDIR}/devel/gconfmm26 \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24

USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget intlhack libgnome esound
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lesd"

GCONF_SCHEMAS=	monster-masher.schemas

.include <bsd.port.mk>
