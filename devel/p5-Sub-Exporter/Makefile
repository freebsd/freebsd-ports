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

BUILD_DEPENDS=	p5-Data-OptList>=0.100:${PORTSDIR}/devel/p5-Data-OptList \
		p5-Params-Util>=0.14:${PORTSDIR}/devel/p5-Params-Util \
		p5-Sub-Install>=0.920:${PORTSDIR}/devel/p5-Sub-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Sub::Exporter.3 \
	Sub::Exporter::Cookbook.3 \
	Sub::Exporter::Tutorial.3 \
	Sub::Exporter::Util.3

.include <bsd.port.mk>
