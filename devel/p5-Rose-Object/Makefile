# New ports collection makefile for:	devel/p5-Rose-Object
# Date created:				09 June 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Rose-Object
PORTVERSION=	0.853
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0+$//}

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	A simple object base class

BUILD_DEPENDS=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	Rose::Class.3 \
	Rose::Class::MakeMethods::Generic.3 \
	Rose::Class::MakeMethods::Set.3 \
	Rose::Object.3 \
	Rose::Object::MakeMethods.3 \
	Rose::Object::MakeMethods::DateTime.3 \
	Rose::Object::MakeMethods::Generic.3 \
	Rose::Object::MixIn.3 \

.include <bsd.port.mk>
