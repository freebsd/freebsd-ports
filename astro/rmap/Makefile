# New ports collection makefile for:	rmap
# Date created:				29 Mar 2000
# Whom:					trevor@jpj.net
#
# $FreeBSD$
#

PORTNAME=	rmap
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	astro
MASTER_SITES=	http://www.reza.net/rmap/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Generates images of the Earth centered at a particular location

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd2 \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

MAN1=		rmap.1
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt"

.include <bsd.port.mk>
