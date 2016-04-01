# $FreeBSD$

PORTNAME=	DBIx-Skinny-InflateColumn-DateTime
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to inflate/deflate DateTime for DBIx::Skinny

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-DBD-SQLite>0:databases/p5-DBD-SQLite \
	p5-DBIx-Skinny>=0.05:databases/p5-DBIx-Skinny \
	p5-DateTime>0:devel/p5-DateTime \
	p5-DateTime-Format-MySQL>0:devel/p5-DateTime-Format-MySQL \
	p5-DateTime-Format-Strptime>0:devel/p5-DateTime-Format-Strptime \
	p5-DateTime-TimeZone>0:devel/p5-DateTime-TimeZone
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-DBD-Mock>=0:databases/p5-DBD-Mock

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
