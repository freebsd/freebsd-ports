# ex:ts=8
# New ports collection makefile for:	source-highlight
# Date created:			Aug 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	source-highlight
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

.include <bsd.port.mk>
