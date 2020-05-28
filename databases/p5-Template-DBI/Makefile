# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Template-DBI
PORTVERSION=	2.65
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Template interface to the DBI Perl module

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-DBI>=0:databases/p5-DBI \
		p5-SQL-Statement>=1.28:databases/p5-SQL-Statement \
		p5-MLDBM>=0:databases/p5-MLDBM

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
