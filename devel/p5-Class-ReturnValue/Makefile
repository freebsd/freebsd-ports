# New ports collection makefile for:	Class::ReturnValue
# Date created:				26 Jan 2003
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Class-ReturnValue
PORTVERSION=	0.52
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A return-value object that can be treated as a boolean,array or object

BUILD_DEPENDS=	${SITE_PERL}/Devel/StackTrace.pm:${PORTSDIR}/devel/p5-Devel-StackTrace \
		${SITE_PERL}/Test/Inline.pm:${PORTSDIR}/devel/p5-Test-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::ReturnValue.3

.include <bsd.port.mk>
