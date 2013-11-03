# $FreeBSD$

PORTNAME=	DBD-CSV
PORTVERSION=	0.41
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI driver for CSV files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=1.614:${PORTSDIR}/databases/p5-DBI \
		p5-SQL-Statement>=1.33:${PORTSDIR}/databases/p5-SQL-Statement \
		p5-Text-CSV_XS>=0.71:${PORTSDIR}/textproc/p5-Text-CSV_XS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
