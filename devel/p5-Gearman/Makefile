PORTNAME=	Gearman
PORTVERSION=	2.004.015
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:PALIK
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Gearman client libraray for Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Which>=0:sysutils/p5-File-Which \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-Proc-Guard>=0.07:devel/p5-Proc-Guard
RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-String-CRC32>=0:devel/p5-String-CRC32
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-TCP>=2.17:devel/p5-Test-TCP \
		p5-Test-Timer>=0:devel/p5-Test-Timer

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
