# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBICx-Deploy
PORTVERSION=	0.02
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JROCKWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Perl 5 module to deploy a DBIx::Class schema

BUILD_DEPENDS=	p5-DBIx-Class>=0.07003:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-SQL-Translator>=0:${PORTSDIR}/databases/p5-SQL-Translator \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS=	p5-DBIx-Class>=0.07003:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-SQL-Translator>=0:${PORTSDIR}/databases/p5-SQL-Translator

USES=		perl5
USE_PERL5=	configure

MAN1=	dbicdeploy.1
MAN3=	DBICx::Deploy.3

.include <bsd.port.mk>
