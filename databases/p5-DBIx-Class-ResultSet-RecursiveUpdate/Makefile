# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-ResultSet-RecursiveUpdate
PORTVERSION=	0.30
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Like update_or_create - but recursive

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp-Clan>=6.04:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-DBD-SQLite>=1.21:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBIx-Class>=0.08103:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DBIx-Class-IntrospectableM2M>=0:${PORTSDIR}/databases/p5-DBIx-Class-IntrospectableM2M \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly \
		p5-SQL-Translator>=0.11016:${PORTSDIR}/databases/p5-SQL-Translator
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-NonMoose>=0:${PORTSDIR}/devel/p5-MooseX-NonMoose \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Trap>=0.2.2:${PORTSDIR}/devel/p5-Test-Trap \
		p5-Test-Warn>=0.20:${PORTSDIR}/devel/p5-Test-Warn \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
