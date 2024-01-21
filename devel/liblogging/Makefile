PORTNAME=	liblogging
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/liblogging/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Easy to use system logging library
WWW=		https://www.liblogging.org/

LICENSE=	BSD2CLAUSE

USES=		cpe libtool pathfix pkgconfig
CPE_VENDOR=	adiscon

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=		--disable-journal --enable-rfc3195
USE_LDCONFIG=			yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblogging-rfc3195.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblogging-stdlog.so.0.1.0

.include <bsd.port.mk>
