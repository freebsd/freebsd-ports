# New ports collection makefile for:	p5-Class-DBI-Pg
# Date created:	   21 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Pg
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Extensions to Class::DBI for PostgreSQL

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::Pg.3

.include <bsd.port.mk>
