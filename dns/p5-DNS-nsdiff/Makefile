# Created by: Matthew Seaman

PORTNAME=	DNS-nsdiff
PORTVERSION=	1.82
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Create an "nsupdate" script from DNS zone file differences

LICENSE=	CC0-1.0

RUN_DEPENDS=	nsupdate:dns/bind-tools \
		named-compilezone:dns/bind916

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
