# New ports collection makefile for:	p5-Data-Page
# Date created:	   21 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Data-Page
PORTVERSION=	2.00
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Pager utility for Class::DBI

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor/Chained.pm:${PORTSDIR}/devel/p5-Class-Accessor-Chained
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Data::Page.3

.include <bsd.port.mk>
