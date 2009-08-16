# New ports collection makefile for:	devel/p5-Sub-Exporter
# Date created:				30 Apr 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sub-Exporter
PORTVERSION=	0.982
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A sophisticated exporter for custom-built routines

RUN_DEPENDS=	p5-Sub-Install>=0.92:${PORTSDIR}/devel/p5-Sub-Install \
		p5-Data-OptList>=0.100:${PORTSDIR}/devel/p5-Data-OptList \
		p5-Params-Util>=0.14:${PORTSDIR}/devel/p5-Params-Util
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.6.2+

MAN3=	Sub::Exporter.3 \
	Sub::Exporter::Cookbook.3 \
	Sub::Exporter::Tutorial.3 \
	Sub::Exporter::Util.3

.include <bsd.port.mk>
