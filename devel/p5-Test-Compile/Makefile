# Created by: Cezary Morga <cm@therek.net>

PORTNAME=	Test-Compile
PORTVERSION=	3.0.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EGILES
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Check whether Perl module files compile correctly

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-CheckOS>=0:devel/p5-Devel-CheckOS

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
