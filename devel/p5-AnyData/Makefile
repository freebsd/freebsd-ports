# Created by: ijliao
# $FreeBSD$

PORTNAME=	AnyData
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:REHSACK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy access to data in many formats

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI>=0:www/p5-CGI
TEST_DEPENDS=	p5-Test-Output>=0:devel/p5-Test-Output

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
