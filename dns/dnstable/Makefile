# $FreeBSD$

PORTNAME=	dnstable
PORTVERSION=	0.10.2
CATEGORIES=	dns
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Encoding format, library, and utilities for passive DNS data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libmtbl.so:devel/mtbl	\
		libyajl.so:devel/yajl	\
		libwdns.so:dns/wdns

USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-install:
.for i in 1 3 5 7
	${INSTALL_MAN} ${WRKSRC}/man/*.${i} ${STAGEDIR}/${PREFIX}/man/man${i}
.endfor

.include <bsd.port.mk>
