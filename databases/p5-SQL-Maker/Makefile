# New ports collection makefile for:	SQL::Maker
# Date created:		27 Feb 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SQL-Maker
PORTVERSION=	1.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for yet another SQL builder

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>=0.05:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash

PERL_MODBUILD=	yes

MAN3=	SQL::Maker.3 \
	SQL::Maker::Condition.3 \
	SQL::Maker::Plugin::InsertMulti.3 \
	SQL::Maker::SQLType.3 \
	SQL::Maker::Select.3 \
	SQL::Maker::SelectSet.3

.include <bsd.port.mk>
