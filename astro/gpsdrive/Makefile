# New ports collection makefile for:	gpsdrive
# Date Created:				16 April 2002
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	gpsdrive
PORTVERSION=	1.20.r1
CATEGORIES=	astro
MASTER_SITES=	http://www.kraftvoll.at/software/ \
		http://ganter.quant-x.at/software/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/pre/}

MAINTAINER=	molter@gufi.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_GLIB=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include   \
		LDFLAGS=-L${LOCALBASE}/lib
INSTALLS_SHLIB=	yes

MAN1=		gpsdrive.1
MANLANG=	"" de es

.include <bsd.port.mk>
