# ex:ts=8
# Ports collection makefile for:	Data-Bind
# Date created:			Jul. 12, 2006
# Whom:				Ying-Chieh Chen
#
# $FreeBSD$
#

PORTNAME=	Data-Bind
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A perl module to bind and alias variables

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor	\
		${SITE_PERL}/${PERL_ARCH}/Devel/Caller.pm:${PORTSDIR}/devel/p5-Devel-Caller \
		${SITE_PERL}/${PERL_ARCH}/Devel/LexAlias.pm:${PORTSDIR}/devel/p5-Devel-LexAlias \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Data::Bind.3

.include <bsd.port.mk>
