# New ports collection makefile for:	libglade
# Date created:				18 August 1999
# Whom:					Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	libglade
PORTVERSION=	0.16
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/libglade

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml

USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOMELIBS=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
