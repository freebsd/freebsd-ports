# New ports collection makefile for: 	p5-Test-DatabaseRow
# Date created:				June 3 2006
# Whom:					Joshua D. Abraham <jabra@ccs.neu.edu>
#
# $FreeBSD$
#

PORTNAME=	Test-DatabaseRow
PORTVERSION=	1.04
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Simple database tests

BUILD_DEPENDS=	${SITE_PERL}/mach/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Test/Builder/Module.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::DatabaseRow.3

.include <bsd.port.mk>
