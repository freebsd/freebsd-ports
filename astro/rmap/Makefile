# New ports collection makefile for:	rmap
# Date created:				29 Mar 2000
# Whom:					trevor@jpj.net
#
# $FreeBSD$
#

PORTNAME=	rmap
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://www.reza.net/rmap/

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

MAN1=		rmap.1
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I ${LOCALBASE}/include/gd/" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt"

.include <bsd.port.mk>
