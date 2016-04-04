# Created by: andrew@scoop.co.nz
# $FreeBSD$

PORTNAME=	Class-DBI-mysql
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensions to Class::DBI for MySQL

BUILD_DEPENDS=	p5-Class-DBI>=0:databases/p5-Class-DBI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
