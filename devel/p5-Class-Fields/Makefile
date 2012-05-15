# New ports collection makefile for:	Class-Fields
# Date created:		15 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Fields
PORTVERSION=	0.204
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Set of modules to operate with class fields and members access

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp-Assert>=0:${PORTSDIR}/devel/p5-Carp-Assert
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	considered obsolete by upstream
EXPIRATION_DATE=	2012-07-11

PERL_CONFIGURE=	yes

MAN3=		Class::Fields.3 Class::Fields::Attribs.3 \
		Class::Fields::Fuxor.3 Class::Fields::Inherit.3 private.3 \
		protected.3 public.3

.include <bsd.port.mk>
