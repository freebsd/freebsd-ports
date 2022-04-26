PORTNAME=	iCal-Parser
PORTVERSION=	1.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse iCalendar files into a data structure

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime-Format-ICal>=0.08:devel/p5-DateTime-Format-ICal \
		p5-FreezeThaw>=0.4300:devel/p5-FreezeThaw \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-Text-vFile-asData>=0.02:devel/p5-Text-vFile-asData

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
