# New ports collection makefile for:   at-spi
# Date Created:			12 April 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/at-spi/Makefile,v 1.85 2009/03/17 13:55:06 kwm Exp $
#

PORTNAME=	at-spi
PORTVERSION=	1.26.0
PORTREVISION?=	1
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An Assistive Technology Service Provider Interface

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomehier intlhack gtk20 libbonobo
USE_XORG=	x11 xtst
USE_PYTHON=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	at-spi.schemas

post-extract:
	@${RM} -f ${WRKSRC}/registryd/Accessibility_Registry.server

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/test//" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/docs//" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
