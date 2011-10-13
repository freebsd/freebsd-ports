# New ports collection makefile for:	Module-Runtime
# Date created:				01 Jun 2008
# Whom:					brix@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Module-Runtime
PORTVERSION=	0.010
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Perl module for runtime module handling

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	${SITE_PERL}/parent.pm:${PORTSDIR}/devel/p5-parent \
		${SITE_PERL}/${PERL_ARCH}/Params/Classify.pm:${PORTSDIR}/devel/p5-Params-Classify
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Module::Runtime.3

.include <bsd.port.mk>
