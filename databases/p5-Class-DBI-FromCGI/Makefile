# Created by: mat
# $FreeBSD$

PORTNAME=	Class-DBI-FromCGI
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	databases www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Update Class::DBI data using CGI::Untaint

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-DBI>=0:databases/p5-Class-DBI \
		p5-CGI-Untaint>=0:www/p5-CGI-Untaint

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
