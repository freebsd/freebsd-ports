# New ports collection makefile for:	p5-Class-DBI-Plugin-Type
# Date created:				Apr 3 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Class-DBI-Plugin-Type
PORTVERSION=	0.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Determine type information for columns

BUILD_DEPENDS=	p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

MAN3=		Class::DBI::Plugin::Type.3

.include <bsd.port.mk>
