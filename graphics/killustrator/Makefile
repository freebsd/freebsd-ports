# New ports collection makefile for:   killustrator
# Date created:        07 May 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	killustrator
PORTVERSION=	0.7.2
CATEGORIES=	graphics kde
MASTER_SITES=	http://wwwiti.cs.uni-magdeburg.de/~sattler/pub/killustrator/

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_KDEBASE_VER=1
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"

.include <bsd.port.mk>
