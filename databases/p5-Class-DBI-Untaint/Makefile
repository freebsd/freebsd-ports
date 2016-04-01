# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Class-DBI-Untaint
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Class::DBI constraints using CGI::Untaint

BUILD_DEPENDS=	p5-Class-DBI>=0:databases/p5-Class-DBI \
		p5-CGI-Untaint>=0:www/p5-CGI-Untaint
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
