# ex:ts=8
# New ports collection makefile for:	liboop
# Date created:			Jun 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	liboop
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.ofb.net/liboop/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A low-level event loop management library for POSIX-based OS

LIB_DEPENDS=	adns.1:${PORTSDIR}/net/adns \
		wwwcore.1:${PORTSDIR}/www/libwww

USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include/w3c-libwww -I${LOCALBASE}/include 
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|glib-config|${GLIB_CONFIG:T}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
