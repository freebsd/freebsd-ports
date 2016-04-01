# $FreeBSD$

PORTNAME=	GitDDL
PORTVERSION=	0.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TYPESTER
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for database migration utility by git managed sql

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-DBI>0:databases/p5-DBI \
	p5-Git-Repository>0:devel/p5-Git-Repository \
	p5-Mouse>0:devel/p5-Mouse \
	p5-SQL-Translator>=0.11016:databases/p5-SQL-Translator
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
