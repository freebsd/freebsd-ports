# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-DateTime-Epoch
PORTVERSION=	0.10
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatic inflation/deflation of epoch-based DateTime objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DBIx-Class>=0.08103:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DBIx-Class-TimeStamp>=0.07:${PORTSDIR}/databases/p5-DBIx-Class-TimeStamp
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBICx-TestDatabase>=0:${PORTSDIR}/databases/p5-DBICx-TestDatabase \
		p5-DateTime-Format-SQLite>=0:${PORTSDIR}/devel/p5-DateTime-Format-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
