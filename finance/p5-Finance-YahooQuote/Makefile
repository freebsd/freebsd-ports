PORTNAME=	Finance-YahooQuote
PORTVERSION=	0.26
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Get stock quotes from Yahoo! Finance

LICENSE=	GPLv2+

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Parser>=2.2:www/p5-HTML-Parser \
		p5-libwww>=1.62:www/p5-libwww

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
