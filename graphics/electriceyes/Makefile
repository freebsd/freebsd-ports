# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	electriceyes
PORTVERSION=	0.3.12
PORTREVISION=	11
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/ee/0.3
DISTNAME=	ee-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A graphic view base imlib & gtk

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
USES=		gettext
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
post-install:
	${MV} ${PREFIX}/bin/ee ${PREFIX}/bin/ElectricEyes

.include <bsd.port.mk>
