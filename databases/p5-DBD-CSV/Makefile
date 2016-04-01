# $FreeBSD$

PORTNAME=	DBD-CSV
PORTVERSION=	0.48
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI driver for CSV files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=1.633:databases/p5-DBI \
		p5-SQL-Statement>=1.405:databases/p5-SQL-Statement \
		p5-Text-CSV_XS>=1.01:textproc/p5-Text-CSV_XS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 tar:tgz
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
