# ex:ts=8
# Ports collection makefile for:	Speex
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	speex
PORTVERSION=	0.5.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Speex-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

.include <bsd.port.mk>
