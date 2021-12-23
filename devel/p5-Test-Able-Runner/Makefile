# Created by: Anes Mukhametov <anes@anes.su>

PORTNAME=	Test-Able-Runner
PORTVERSION=	1.002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Use Test::Able without a bunch of boilerplate

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-Pluggable>=3.6:devel/p5-Module-Pluggable \
		p5-Moose>=0.94:devel/p5-Moose \
		p5-Test-Able>=0.09:devel/p5-Test-Able

USES=		perl5
USE_PERL5=	configure

post-extract:
	${FIND} ${WRKSRC} -type f \( -name '*.orig' -o -name '*.rej' \) -delete


.include <bsd.port.mk>
