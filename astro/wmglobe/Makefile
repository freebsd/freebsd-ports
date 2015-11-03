# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	wmglobe
PORTVERSION=	1.3
PORTREVISION=	10
CATEGORIES=	astro windowmaker geography
MASTER_SITES=	http://hamete.org/static/wmg/

MAINTAINER=	will@FreeBSD.org
COMMENT=	Neat xearth-like WindowMaker dockapp

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

LIB_DEPENDS=	libwraster.so:${PORTSDIR}/x11-wm/libwraster

PLIST_FILES=	bin/wmglobe \
		man/man1/wmglobe.1.gz
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
