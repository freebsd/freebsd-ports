# New ports collection makefile for:	Class::ReturnValue
# Date created:				26 Jan 2003
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Class-ReturnValue
PORTVERSION=	0.40
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/Devel/StackTrace.pm:${PORTSDIR}/devel/p5-Devel-StackTrace \
		${SITE_PERL}/Test/Inline.pm:${PORTSDIR}/devel/p5-Test-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Class::ReturnValue.3

.include <bsd.port.mk>
