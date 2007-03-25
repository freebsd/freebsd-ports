# New ports collection makefile for:	p5-Exception-Class
# Date created:				15 October 2005
# Whom:	      				Rod Taylor <ports@rbt.ca>
#
# $FreeBSD$
#

PORTNAME=	Exception-Class-DBI
PORTVERSION=	0.95
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Exception
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI Exception objects

RUN_DEPENDS=	${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_MODBUILD=	yes

MAN3=		Exception::Class::DBI.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800 # inherited from devel/p5-Exception-Class
IGNORE=	requires at least Perl 5.8.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
