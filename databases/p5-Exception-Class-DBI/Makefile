# New ports collection makefile for:	p5-Exception-Class
# Date created:				15 October 2005
# Whom:	      				Rod Taylor <ports@rbt.ca>
#
# $FreeBSD$
#

PORTNAME=	Exception-Class-DBI
PORTVERSION=	1.00
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI Exception objects

RUN_DEPENDS=	${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_MODBUILD=	5.8.0+

MAN3=		Exception::Class::DBI.3

.include <bsd.port.mk>
