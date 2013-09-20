# $FreeBSD$

PORTNAME=	DBIx-Class-Tree
PORTVERSION=	0.03003
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to manipulate and analyze tree structured data

RUN_DEPENDS=	\
	p5-DBIx-Class>=0.08100:${PORTSDIR}/databases/p5-DBIx-Class
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::Class::Tree.3 \
	DBIx::Class::Tree::AdjacencyList.3 \
	DBIx::Class::Tree::AdjacencyList::Ordered.3

NO_STAGE=	yes
.include <bsd.port.mk>
