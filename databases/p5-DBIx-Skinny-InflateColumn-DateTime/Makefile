# $FreeBSD$

PORTNAME=	DBIx-Skinny-InflateColumn-DateTime
PORTVERSION=	0.06
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to inflate/deflate DateTime for DBIx::Skinny

RUN_DEPENDS=	\
	p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-DBIx-Skinny>=0.05:${PORTSDIR}/databases/p5-DBIx-Skinny \
	p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime \
	p5-DateTime-Format-MySQL>0:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
	p5-DateTime-Format-Strptime>0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
	p5-DateTime-TimeZone>0:${PORTSDIR}/devel/p5-DateTime-TimeZone
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-DBD-Mock>=0:${PORTSDIR}/databases/p5-DBD-Mock

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
