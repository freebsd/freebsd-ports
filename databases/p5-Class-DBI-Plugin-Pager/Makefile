# $FreeBSD$

PORTNAME=	Class-DBI-Plugin-Pager
PORTVERSION=	0.566
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to paged queries for CDBI

BUILD_DEPENDS=	p5-Class-DBI>=0:databases/p5-Class-DBI \
		p5-SQL-Abstract>=1.61:databases/p5-SQL-Abstract \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require \
		p5-Data-Page>=0:databases/p5-Data-Page \
		p5-Class-DBI-Plugin-AbstractCount>=0:databases/p5-Class-DBI-Plugin-AbstractCount
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Text-Exception>0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
