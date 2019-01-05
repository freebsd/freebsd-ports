# $FreeBSD$

PORTNAME=	Time-Moment-Role-TimeZone
PORTVERSION=	0.002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:DBOOK
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Adjust Time::Moment with time zone objects

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Role-Tiny>=2.000001:devel/p5-Role-Tiny \
		p5-Time-Moment>=0.18:devel/p5-Time-Moment
TEST_DEPENDS=	p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5

NO_ARCH=	yes
USE_PERL5=	configure

PLIST_FILES=	${SITE_PERL}/Time/Moment/Role/TimeZone.pm \
		${SITE_MAN3_REL}/Time::Moment::Role::TimeZone.3.gz

.include <bsd.port.mk>
