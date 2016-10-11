# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liblogging
PORTVERSION=	1.0.5
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/liblogging/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Easy to use system logging library

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig

CONFIGURE_ARGS+=	--disable-journal --enable-rfc3195

post-install:
.for l in rfc3195 stdlog
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblogging-${l}.so.0.0.0
.endfor

.include <bsd.port.mk>
