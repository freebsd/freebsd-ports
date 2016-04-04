# Created by: ijlioa
# $FreeBSD$

PORTNAME=	DBD-AnyData
PORTVERSION=	0.110
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI access to XML, CSV, and other formats

BUILD_DEPENDS=	p5-AnyData>=0.07:devel/p5-AnyData \
		p5-DBI>1:databases/p5-DBI \
		p5-SQL-Statement>1:databases/p5-SQL-Statement
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
