# New ports collection makefile for:	Class::ObjectTemplate
# Date created:				9 Nov 2001
# Whom:					Tony Maher <tonym@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	Class-ObjectTemplate-DB
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	tonym@biolateral.com.au

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/ObjectTemplate.pm:${PORTSDIR}/devel/p5-Class-ObjectTemplate

PERL_CONFIGURE=	yes

MAN3=		Class::ObjectTemplate::DB.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
