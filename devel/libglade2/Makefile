# New ports collection makefile for:	libglade
# Version required:			0.12
# Date created:				18 August 1999
# Whom:					Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

DISTNAME=	libglade-0.12
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/libglade

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs \
		xml.5:${PORTSDIR}/textproc/libxml

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_PERL5=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
