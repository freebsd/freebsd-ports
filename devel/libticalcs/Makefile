# New ports collection makefile for:	libticalcs
# Date created:		27 August 2003
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticalcs
PORTVERSION=	4.5.9
CATEGORIES=	devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator library

LIB_DEPENDS=	ticables.12:${PORTSDIR}/comms/libticables \
		tifiles.6:${PORTSDIR}/devel/libtifiles

USE_GETTEXT=	yes
USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
