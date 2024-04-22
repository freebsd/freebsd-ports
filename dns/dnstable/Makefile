PORTNAME=	dnstable
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Encoding format, library, and utilities for passive DNS data
WWW=		https://github.com/farsightsec/dnstable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libmtbl.so:devel/mtbl	\
		libwdns.so:dns/wdns

USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
