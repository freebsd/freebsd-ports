PORTNAME=	Class-DBI-Untaint
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Class::DBI constraints using CGI::Untaint

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-DBI>=0:databases/p5-Class-DBI \
		p5-CGI-Untaint>=0:www/p5-CGI-Untaint
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
