# New ports collection makefile for:	Class-Data-Inheritable
# Date created:		17 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Data-Inheritable
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Inheritable, overridable class data

BUILD_DEPENDS=	${SITE_PERL}/base.pm:${PORTSDIR}/devel/p5-Class-Fields
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Data::Inheritable.3

.include <bsd.port.mk>
