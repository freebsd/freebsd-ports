# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liblogging
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/liblogging/

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Easy to use system logging library

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig

CONFIGURE_ARGS+=	--disable-journal

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblogging-stdlog.so.0.0.0

.include <bsd.port.mk>
