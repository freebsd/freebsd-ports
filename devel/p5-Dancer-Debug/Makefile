# Created by: Geistteufel <geistteufel@yahoo.fr>
# $FreeBSD$

PORTNAME=	Dancer-Debug
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Plack::Middleware::Debug extension Perl module

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-Dancer>=0:www/p5-Dancer \
		p5-Plack-Middleware-Debug>=0:www/p5-Plack-Middleware-Debug

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
