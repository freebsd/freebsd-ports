# ex:ts=8
# Ports collection makefile for:	recmpeg
# Date created:			Mar 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	recmpeg
PORTVERSION=	1.0.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fame

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	fame-0.9.0:${PORTSDIR}/graphics/libfame

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	recmpeg.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if !exists(/usr/include/getopt.h)
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
LDFLAGS+=	-lgnugetopt
.endif

.include <bsd.port.mk>
