# $FreeBSD$

PORTNAME=	DBIx-Class-Tree-NestedSet
PORTVERSION=	0.10
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to manage trees of data using the nested set model

RUN_DEPENDS=	\
	p5-DBIx-Class>=0.08:${PORTSDIR}/databases/p5-DBIx-Class
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-DBICx-TestDatabase>=0:${PORTSDIR}/databases/p5-DBICx-TestDatabase \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::Class::Tree::NestedSet.3

NO_STAGE=	yes
.include <bsd.port.mk>
