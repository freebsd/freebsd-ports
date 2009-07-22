# New ports collection makefile for:	p5-IO-YAML
# Date created:		2006-08-17
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IO-YAML
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write YAML streams incrementally

BUILD_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML

PERL_MODBUILD=	yes

MAN3=		IO::YAML.3

.include <bsd.port.mk>
