PORTNAME=	dnstable-convert
PORTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Conversion utility for passive DNS data in dnstable format
WWW=		https://github.com/farsightsec/dnstable-convert

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	sie-nmsg>0:net/sie-nmsg
LIB_DEPENDS=	libdnstable.so:dns/dnstable \
		libmtbl.so:devel/mtbl \
		libnmsg.so:net/nmsg \
		libwdns.so:dns/wdns
RUN_DEPENDS=	sie-nmsg>0:net/sie-nmsg

USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/dnstable_convert bin/dnstable_unconvert \
		share/man/man1/dnstable_convert.1.gz \
		share/man/man1/dnstable_unconvert.1.gz

.include <bsd.port.mk>
