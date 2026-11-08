PORTNAME=	String-Formatter
DISTVERSION=	0.102084
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	Build sprintf-like functions of your own
WWW=		https://metacpan.org/release/String-Formatter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_RUN_DEPENDS=	p5-Params-Util>=0:devel/p5-Params-Util \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
