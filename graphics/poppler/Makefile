# New ports collection makefile for:	poppler
# Date created:         03 March 2005
# Whom:                 marcus@FreeBSD.org
#
# $FreeBSD$
#   $MCom: ports/graphics/poppler/Makefile,v 1.14 2005/09/03 04:44:58 ahze Exp $
#

PORTNAME=	poppler
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A PDF rendering library

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-zlib \
		--disable-poppler-qt
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
