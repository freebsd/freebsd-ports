PORTNAME=	DateTime-Format-Epoch
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert DateTimes to/from epoch seconds
WWW=		https://metacpan.org/pod/DateTime::Format::Epoch

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0.31:devel/p5-DateTime \
		p5-Params-Validate>=0:devel/p5-Params-Validate

PORTSCOUT=	skipv:0.801

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
