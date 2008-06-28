# New ports collection makefile for:	p5-Scalar-Defer
# Date created:		2006-07-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Scalar-Defer
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Calculate values on demand

RUN_DEPENDS=	${SITE_PERL}/Class/InsideOut.pm:${PORTSDIR}/devel/p5-Class-InsideOut \
		${SITE_PERL}/Exporter/Lite.pm:${PORTSDIR}/devel/p5-Exporter-Lite

PERL_CONFIGURE=	yes

MAN3=		Scalar::Defer.3

.include <bsd.port.mk>
