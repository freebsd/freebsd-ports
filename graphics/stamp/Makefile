# New ports collection makefile for:	stamp
# Version required:	2.0.8
# Date created:	11 August 1998
# Whom:		Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

DISTNAME=	stamp-2.0.8
CATEGORIES=	graphics
MASTER_SITES=	http://stamp.netpedia.net/

MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt"
USE_GMAKE=	unfortunatly

.include <bsd.port.mk>
