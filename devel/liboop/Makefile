# ex:ts=8
# New ports collection makefile for:	liboop
# Date created:			Jun 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	liboop
PORTVERSION=	0.8
CATEGORIES=	devel
MASTER_SITES=	http://download.ofb.net/liboop/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	adns:${PORTSDIR}/net/adns \
		wwwcore:${PORTSDIR}/www/libwww

USE_GLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/w3c-libwww" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s,glib-config,${GLIB_CONFIG},g" ${WRKSRC}/configure

.include <bsd.port.mk>
