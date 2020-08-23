# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mojolicious-Plugin-NYTProf
PORTVERSION=	0.23
CATEGORIES=	devel www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Auto handling of Devel::NYTProf in your Mojolicious app

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-NYTProf>=6.06:devel/p5-Devel-NYTProf \
		p5-File-Which>=1.09:sysutils/p5-File-Which \
		p5-Mojolicious>=8.00:www/p5-Mojolicious
TEST_DEPENDS=	p5-Algorithm-Combinatorics>=0:math/p5-Algorithm-Combinatorics \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
