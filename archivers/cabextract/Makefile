# New ports collection makefile for:	cabextract
# Date Created:				30 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cabextract
PORTVERSION=	0.6
CATEGORIES=	archivers
MASTER_SITES=	http://www.kyz.uklinux.net/downloads/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=		cabextract.1

.include <bsd.port.mk>
