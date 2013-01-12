# $FreeBSD$

PORTNAME=	DBIx-Skinny-Schema-Loader
PORTVERSION=	0.25
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NEKOYA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to load schema for DBIx::Skinny

RUN_DEPENDS=	\
	p5-DBIx-Skinny>=0.0733:${PORTSDIR}/databases/p5-DBIx-Skinny
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable

PERL_CONFIGURE=	yes

MAN3=	DBIx::Skinny::Schema::Loader.3

.include <bsd.port.mk>
