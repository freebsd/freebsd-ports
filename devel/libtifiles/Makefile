# New ports collection makefile for:	libtifiles
# Date created:		27 August 2003
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libtifiles
PORTVERSION=	0.5.7
CATEGORIES=	devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator file types library

BUILD_DEPENDS=  pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=    pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

WANT_AUTOMAKE_VER=	15
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	tifiles-config.1

.include <bsd.port.mk>
