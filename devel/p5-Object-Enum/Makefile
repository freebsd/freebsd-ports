# New ports collection makefile for:	Object-Enum
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Object-Enum
PORTVERSION=	0.07.2
DISTVERSION=	${PORTVERSION:C/\.(.)$/\1/}
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replacement for if ($$foo eq 'bar')

RUN_DEPENDS=	${SITE_PERL}/Sub/Install.pm:${PORTSDIR}/devel/p5-Sub-Install \
		${SITE_PERL}/Sub/Exporter.pm:${PORTSDIR}/devel/p5-Sub-Exporter \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=	Object::Enum.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
