# New ports collection makefile for:	Class-Default
# Date created:	   10 December 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Default
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Static calls apply to a default instantiation

BUILD_DEPENDS=	${SITE_PERL}/Class/Inspector.pm:${PORTSDIR}/devel/p5-Class-Inspector
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Default.3

post-patch:
	@${PERL} -pi -e 's/^auto_install.*$$//' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
