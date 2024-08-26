PORTNAME=	DNS-nsdiff
PORTVERSION=	1.85
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Create an "nsupdate" script from DNS zone file differences
WWW=		https://dotat.at/prog/nsdiff/

LICENSE=	BSD0CLAUSE MIT
LICENSE_COMB=	dual

RUN_DEPENDS=	nsupdate:dns/bind-tools

OPTIONS_RADIO=	BIND
OPTIONS_RADIO_BIND=	BIND918 BIND920 BINDDEVEL
OPTIONS_DEFAULT=	BIND920

BIND918_DESC=	Use Bind 9.18 for named-compilezone
BIND920_DESC=	Use Bind 9.20 for named-compilezone
BINDDEVEL_DESC=	Use Bind 9-devel for named-compilezone

BIND918_RUN_DEPENDS=	named-compilezone:dns/bind918
BIND920_RUN_DEPENDS=	named-compilezone:dns/bind920
BINDDEVEL_RUN_DEPENDS=	named-compilezone:dns/bind9-devel

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
