# New ports collection makefile for:	p5-Class-DBI-Loader
# Date created:	   21 july 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Loader
PORTVERSION=	0.01
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Dynamic definition of Class::DBI sub classes

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::Loader.3 \
		Class::DBI::Loader::Generic.3 \
		Class::DBI::Loader::Pg.3 \
		Class::DBI::Loader::SQLite.3 \
		Class::DBI::Loader::mysql.3

.include <bsd.port.mk>
