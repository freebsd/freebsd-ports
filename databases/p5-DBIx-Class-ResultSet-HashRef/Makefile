# New ports collection makefile for: databases/p5-DBIx-Class-ResultSet-HashRef
# Date created:				15 Sep 2009
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-ResultSet-HashRef
PORTVERSION=	1.002
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Adds syntactic sugar to skip the fancy objects

BUILD_DEPENDS=	p5-DBIx-Class>=0.04001:${PORTSDIR}/databases/p5-DBIx-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	DBIx::Class::ResultSet::HashRef.3

.include <bsd.port.mk>
