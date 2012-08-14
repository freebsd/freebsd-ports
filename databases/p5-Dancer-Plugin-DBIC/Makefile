# New ports collection makefile for:	p5-Dancer-Plugin-DBIC
# Date created:		2011-02-13
# Whom:			<ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Plugin-DBIC
PORTVERSION=	0.1504
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DBIx::Class interface for Dancer applications

BUILD_DEPENDS=	p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class\
		p5-DBIx-Class-Schema-Loader>=0.07002:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader\
		p5-Dancer>=0:${PORTSDIR}/www/p5-Dancer
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

PERL_CONFIGURE=	yes

MAN3=		Dancer::Plugin::DBIC.3

.include <bsd.port.mk>
