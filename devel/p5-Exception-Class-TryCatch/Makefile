# New ports collection makefile for:	p5-Exception-Class-TryCatch
# Date created:		2008-02-14
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Exception-Class-TryCatch
PORTVERSION=	1.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippemail@gmail.com
COMMENT=	Syntactic try/catch sugar for use with Exception::Class

BUILD_DEPENDS+=	${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		Exception::Class::TryCatch.3

.include <bsd.port.mk>
