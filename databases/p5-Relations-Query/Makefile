# New ports collection makefile for:	databases/p5-Relations-Query
# Date created:				1 Aug 2006
# Whom:					Timur I. Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Relations-Query
PORTVERSION=	0.93
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Relations
PKGNAMEPREFIX=	p5-

MAINTAINER=	bat@cpan.org
COMMENT=	Object for building queries with DBI/DBD::mysql

BUILD_DEPENDS=	${SITE_PERL}/Relations.pm:${PORTSDIR}/databases/p5-Relations
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Relations::Query.3

.include <bsd.port.mk>
