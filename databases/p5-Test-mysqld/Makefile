# $FreeBSD$

PORTNAME=	Test-mysqld
PORTVERSION=	0.17
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for mysqld test runner

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-File-Copy-Recursive>0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
	p5-Test-SharedFork>=0.06:${PORTSDIR}/devel/p5-Test-SharedFork
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::mysqld.3

.include <bsd.port.mk>
