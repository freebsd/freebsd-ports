PORTNAME=	liblogging
PORTVERSION=	1.0.6
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/liblogging/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Easy to use system logging library

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USES=		cpe libtool pathfix pkgconfig
CPE_VENDOR=	adiscon

CONFIGURE_ARGS+=	--disable-journal --enable-rfc3195

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblogging-rfc3195.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblogging-stdlog.so.0.1.0

.include <bsd.port.mk>
