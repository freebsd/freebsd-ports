# $FreeBSD$

PORTNAME=	dnstable
PORTVERSION=	0.9.1
CATEGORIES=	dns
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Encoding format, library, and utilities for passive DNS data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	sie-nmsg>0:net/sie-nmsg
LIB_DEPENDS=	libmtbl.so:devel/mtbl	\
		libyajl.so:devel/yajl	\
		libwdns.so:dns/wdns 	\
		libnmsg.so:net/nmsg
RUN_DEPENDS=	sie-nmsg>0:net/sie-nmsg

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/yajl
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
.for i in 1 3 5 7
	${INSTALL_MAN} ${WRKSRC}/man/*.${i} ${STAGEDIR}/${PREFIX}/man/man${i}
.endfor

.include <bsd.port.mk>
