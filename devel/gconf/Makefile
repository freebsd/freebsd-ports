# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/gconf/Makefile,v 1.5 2007/05/19 21:36:05 marcus Exp $

PORTNAME=	gconf
PORTVERSION=	1.0.9
PORTREVISION=	18
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/GConf/1.0
DISTNAME=	GConf-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

LIB_DEPENDS=	guile.21:${PORTSDIR}/lang/guile

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack glib12 gtk12 oaf libxml orbit
USES=		gettext
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=yes

NO_STAGE=	yes
.include <bsd.port.mk>
