# New ports collection makefile for:  DBIx-Class-QueryProfiler
# Date created: 25 December 2009
# Whom: andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	DBIx-Class-QueryProfiler
PORTVERSION=	0.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBIx::Class profiler

BUILD_DEPENDS=	p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.9+
MAN3=	DBIx::Class::QueryProfiler.3

.include <bsd.port.mk>
