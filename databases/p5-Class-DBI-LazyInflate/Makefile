# New ports collection makefile for:	databases/p5-Class-DBI-LazyInflate
# Date created:				05 February 2006
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-LazyInflate
PORTVERSION=	0.06
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Defer inflating of columns until they are used

BUILD_DEPENDS=	${SITE_PERL}/Data/Lazy.pm:${PORTSDIR}/devel/p5-Data-Lazy \
		${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::DBI::LazyInflate.3

.include <bsd.port.mk>
