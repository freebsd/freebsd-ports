# ex:ts=8
# Ports collection makefile for:	recmpeg
# Date created:			Mar 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	recmpeg
PORTVERSION=	1.0.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fame

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt \
		fame:${PORTSDIR}/graphics/libfame

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=	recmpeg.1

.include <bsd.port.mk>
