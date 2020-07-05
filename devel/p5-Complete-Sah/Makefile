# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Complete-Sah
PORTVERSION=	0.007
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLANCAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sah-related completion Perl routines

RUN_DEPENDS=	p5-Complete-Common>=0.22:devel/p5-Complete-Common \
		p5-Complete-Util>=0.608:devel/p5-Complete-Util \
		p5-Data-Sah-Normalize>=0:devel/p5-Data-Sah-Normalize
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
