# New ports collection makefile for:	devel/p5-Getopt-Long-Descriptive
# Date created:				28 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Getopt-Long-Descriptive
PORTVERSION=	0.077
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Getopt::Long with usage text

RUN_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Params-Validate>=0.74:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Getopt::Long::Descriptive.3 Getopt::Long::Descriptive::Usage.3

.include <bsd.port.mk>
