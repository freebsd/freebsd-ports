# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	Log-Handler
PORTVERSION=	0.90
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object-oriented handler for logging, tracing, and debugging in Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Params-Validate>=0:devel/p5-Params-Validate
TEST_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Email-Date>=0:mail/p5-Email-Date

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
