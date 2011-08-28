# New ports collection makefile for:	p5-File-Map
# Date created:				2010-04-15
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	File-Map
PORTVERSION=	0.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jupengfei@gmail.com
COMMENT=	Memory mapping made simple and safe

BUILD_DEPENDS=	p5-Const-Fast>=0:${PORTSDIR}/devel/p5-Const-Fast \
		p5-PerlIO-Layers>=0.007:${PORTSDIR}/devel/p5-PerlIO-Layers \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS=	p5-Const-Fast>=0:${PORTSDIR}/devel/p5-Const-Fast \
		p5-PerlIO-Layers>=0.007:${PORTSDIR}/devel/p5-PerlIO-Layers \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	yes

MAN3=		File::Map.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-ExtUtils-CBuilder>=0:${PORTSDIR}/devel/p5-ExtUtils-CBuilder \
		p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build
.endif

.include <bsd.port.post.mk>
