# New ports collection makefile for:	p5-File-Map
# Date created:				2010-04-15
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	File-Map
PORTVERSION=	0.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Memory mapping made simple and safe

BUILD_DEPENDS=	p5-Const-Fast>=0:${PORTSDIR}/devel/p5-Const-Fast \
		p5-PerlIO-Layers>=0:${PORTSDIR}/devel/p5-PerlIO-Layers \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS=	p5-Const-Fast>=0:${PORTSDIR}/devel/p5-Const-Fast \
		p5-PerlIO-Layers>=0:${PORTSDIR}/devel/p5-PerlIO-Layers \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

PERL_MODBUILD=	yes

MAN3=		File::Map.3

.include <bsd.port.mk>
