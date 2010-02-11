# New ports collection makefile for:	Object-Simple
# Date created:		27 December 2009
# Whom:			Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	Object-Simple
PORTVERSION=	3.0303
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Simple class builder

BUILD_DEPENDS=	p5-Scalar-List-Utils>=1.14:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES
MAN3=	Object::Simple.3

.include <bsd.port.mk>
