# $FreeBSD$

PORTNAME=	DBIx-Class-AsFdat
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension like CDBI::Plugin::AsFdat

RUN_DEPENDS=	\
	p5-DBIx-Class>0:${PORTSDIR}/databases/p5-DBIx-Class
BUILD_DEPENDS=	\
	p5-DBIx-Class>0:${PORTSDIR}/databases/p5-DBIx-Class
TEST_DEPENDS=	p5-Test-Declare>=0:${PORTSDIR}/devel/p5-Test-Declare \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn \
		p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Test-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		p5-DateTime-Format-SQLite>=0:${PORTSDIR}/devel/p5-DateTime-Format-SQLite

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::Class::AsFdat.3

.include <bsd.port.mk>
