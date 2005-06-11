# New ports collection makefile for:	Class-Fields
# Date created:		15 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Fields
PORTVERSION=	0.201
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Set of modules to operate with class fields and members access

BUILD_DEPENDS=	${SITE_PERL}/Carp/Assert.pm:${PORTSDIR}/devel/p5-Carp-Assert \
		${SITE_PERL}/base.pm:${PORTSDIR}/devel/p5-base
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Fields.3 Class::Fields::Attribs.3 \
		Class::Fields::Fuxor.3 Class::Fields::Inherit.3 private.3 \
		protected.3 public.3

.include <bsd.port.mk>
