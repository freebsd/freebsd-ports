# New ports collection makefile for:	motor
# Date created:				20 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	motor
PORTVERSION=	2.20.14
CATEGORIES=	devel
MASTER_SITES=	http://konst.org.ua/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl -lgnugetopt"

MAN1=		motor.1

.include <bsd.port.mk>
