# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mojolicious-Plugin-NYTProf
PORTVERSION=	0.20
CATEGORIES=	devel www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Auto handling of Devel::NYTProf in your Mojolicious app

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-NYTProf>=5.07:devel/p5-Devel-NYTProf \
		p5-File-Which>=1.09:sysutils/p5-File-Which \
		p5-Mojolicious>=6.00:www/p5-Mojolicious
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Algorithm-Combinatorics>=0:math/p5-Algorithm-Combinatorics \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/README.pod

.include <bsd.port.mk>
