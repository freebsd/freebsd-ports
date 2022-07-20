PORTNAME=	DNS-nsdiff
PORTVERSION=	1.82
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Create an "nsupdate" script from DNS zone file differences

LICENSE=	CC0-1.0

RUN_DEPENDS=	nsupdate:dns/bind-tools

OPTIONS_RADIO=	BIND
OPTIONS_RADIO_BIND=	BIND916 BIND918 BINDDEVEL
OPTIONS_DEFAULT=	BIND918

BIND916_DESC=	Use Bind 9.16 for named-compilezone
BIND918_DESC=	Use Bind 9.18 for named-compilezone
BINDDEVEL_DESC=	Use Bind 9-devel for named-compilezone

BIND916_RUN_DEPENDS=	named-compilezone:dns/bind916
BIND918_RUN_DEPENDS=	named-compilezone:dns/bind918
BINDDEVEL_RUN_DEPENDS=	named-compilezone:dns/bind9-devel

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
