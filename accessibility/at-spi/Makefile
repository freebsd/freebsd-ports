# New ports collection makefile for:   at-spi
# Date Created:			12 April 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	at-spi
PORTVERSION=	1.6.6
PORTREVISION=	2
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.6
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An Assistive Technology Service Provider Interface

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier intltool gail libbonobo \
		intlhack
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/test//" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
