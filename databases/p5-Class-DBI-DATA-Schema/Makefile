# New ports collection makefile for:	databases/p5-Class-DBI-DATA-Schema
# Date created:				24 October 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-DATA-Schema
PORTVERSION=	1.00
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Execute Class::DBI SQL from DATA sections

RUN_DEPENDS=	p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

MAN3=	Class::DBI::DATA::Schema.3

.include <bsd.port.mk>
