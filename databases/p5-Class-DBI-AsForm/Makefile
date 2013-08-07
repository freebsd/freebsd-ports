# New ports collection makefile for:	p5-Class-DBI-AsForm
# Date created:				Apr 3 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Class-DBI-AsForm
PORTVERSION=	2.42
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Produce HTML form elements for database columns

BUILD_DEPENDS=	p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-Class-DBI-Plugin-Type>=0:${PORTSDIR}/databases/p5-Class-DBI-Plugin-Type
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Class::DBI::AsForm.3

.include <bsd.port.mk>
