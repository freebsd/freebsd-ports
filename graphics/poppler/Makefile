# New ports collection makefile for:	poppler
# Date created:         03 March 2005
# Whom:                 marcus@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	poppler
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A PDF rendering library

LIB_DEPENDS=	cairo.1:${PORTSDIR}/graphics/cairo

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix gnomehack gtk20
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|poppler-[@]VERSION[@]|poppler|g' \
		${WRKSRC}/poppler-cairo.pc.in \
		${WRKSRC}/poppler-splash.pc.in

.include <bsd.port.mk>
