# New ports collection makefile for:	gearmand
# Date created:		2009-01-29
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	gearmand
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/gearmand/trunk/${PORTVERSION}/+download/

MAINTAINER=	gslin@gslin.org
COMMENT=	Gearman C Server and Library

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFLICTS=	p5-Gearman-Server-[0-9]*
FETCH_ARGS=	-pRr
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_RC_SUBR=	gearmand.sh

.include <bsd.port.mk>
