# $FreeBSD$

PORTNAME=	Validation-Class
PORTVERSION=	7.900052
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for centralized input validation for any application

RUN_DEPENDS=	\
	p5-Class-Forward>0:${PORTSDIR}/devel/p5-Class-Forward \
	p5-Hash-Flatten>0:${PORTSDIR}/devel/p5-Hash-Flatten \
	p5-Hash-Merge>0:${PORTSDIR}/textproc/p5-Hash-Merge \
	p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Module-Find>0:${PORTSDIR}/devel/p5-Module-Find \
	p5-Module-Runtime>0:${PORTSDIR}/devel/p5-Module-Runtime
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-Class-Method-Modifiers>0:${PORTSDIR}/devel/p5-Class-Method-Modifiers

USES=	perl5
USE_PERL5=	configure

.include <bsd.port.mk>
