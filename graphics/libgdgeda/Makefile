# New ports collection makefile for:	libgdgeda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	libgdgeda
PORTVERSION=	1.8
CATEGORIES=	graphics cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/ \
		http://www.geda.seul.org/devel/support/ \
		http://www.tinkerbox.org/projects/files/gEDA/

MAINTAINER=	bruno@tinkerbox.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
