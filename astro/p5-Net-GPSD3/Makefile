# $FreeBSD$

PORTNAME=	Net-GPSD3
PORTVERSION=	0.19
CATEGORIES=	astro perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bscott@bunyatech.com.au
COMMENT=	Interface to the gpsd server daemon protocol version 3 (JSON)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-GPS-Point>=0.1:astro/p5-GPS-Point \
		p5-JSON-XS>0:converters/p5-JSON-XS \
		p5-DateTime>0:devel/p5-DateTime \
		p5-DateTime-Format-W3CDTF>=0.06:devel/p5-DateTime-Format-W3CDTF \
		p5-Test-Simple>=0.44:devel/p5-Test-Simple \
		p5-IO-Socket-INET6>0:net/p5-IO-Socket-INET6

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
