# $FreeBSD$

PORTNAME=	DBIx-Skinny
PORTVERSION=	0.0742
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NEKOKAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple DBI wrapper/ORMapper

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-DBI>0:databases/p5-DBI \
	p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require \
	p5-Class-Accessor-Lite>0:devel/p5-Class-Accessor-Lite \
	p5-Try-Tiny>0:lang/p5-Try-Tiny \
	p5-DBIx-TransactionManager>=1.07:databases/p5-DBIx-TransactionManager \
	p5-Class-Load>0:devel/p5-Class-Load

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
