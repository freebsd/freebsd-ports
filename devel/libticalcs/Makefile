# New ports collection makefile for:	libticalcs
# Date created:		27 August 2003
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticalcs
PORTVERSION=	4.5.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator library

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	ticables.10:${PORTSDIR}/comms/libticables \
		tifiles.5:${PORTSDIR}/devel/libtifiles

USE_GETTEXT=	yes
USE_GNOME=	glib20
WANT_AUTOMAKE_VER=	15
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	ticalcs-config.1

.include <bsd.port.mk>
