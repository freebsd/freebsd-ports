# New ports collection makefile for:	p5-Class-DBI-FromCGI
# Date created:	   21 july 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-FromCGI
PORTVERSION=	0.94
CATEGORIES=	databases www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Update Class::DBI data using CGI::Untaint

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/CGI/Untaint.pm:${PORTSDIR}/www/p5-CGI-Untaint

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::FromCGI.3

.include <bsd.port.mk>
