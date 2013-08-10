# $FreeBSD$

PORTNAME=	Devel-KYTProf
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple profiler

BUILD_DEPENDS=	p5-Class-Data-Inheritable>0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite

USES=	perl5
USE_PERL5=	configure

MAN3=	Devel::KYTProf.3 \
	Devel::KYTProf::Logger::LTSV.3 \
	Devel::README.3

.include <bsd.port.mk>
