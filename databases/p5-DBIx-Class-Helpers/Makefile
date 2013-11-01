# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-Helpers
PORTVERSION=	2.019000
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Simplify the common case stuff for DBIx::Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-DBIx-Class>=0.08123:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DBIx-Class-Candy>=0:${PORTSDIR}/databases/p5-DBIx-Class-Candy \
		p5-String-CamelCase>=0:${PORTSDIR}/textproc/p5-String-CamelCase \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean \
		p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-Sub-Exporter-Progressive>=0:${PORTSDIR}/devel/p5-Sub-Exporter-Progressive \
		p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DateTime-Format-SQLite>=0:${PORTSDIR}/devel/p5-DateTime-Format-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
