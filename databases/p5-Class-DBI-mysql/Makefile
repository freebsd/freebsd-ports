PORTNAME=	Class-DBI-mysql
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensions to Class::DBI for MySQL
WWW=		https://metacpan.org/release/Class-DBI-mysql

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-DBI>=0:databases/p5-Class-DBI \
		${DBD_MYSQL}

USES=		mysql perl5
USE_PERL5=	configure

.include <bsd.port.mk>
