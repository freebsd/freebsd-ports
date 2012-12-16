# New ports collection makefile for:	Class::ReturnValue
# Date created:				26 Jan 2003
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Class-ReturnValue
PORTVERSION=	0.55
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A return-value object that can be treated as a boolean, array, or object

BUILD_DEPENDS=	p5-Devel-StackTrace>=0:${PORTSDIR}/devel/p5-Devel-StackTrace
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::ReturnValue.3

.include <bsd.port.mk>
