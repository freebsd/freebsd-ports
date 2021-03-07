# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GraphViz2
PORTVERSION=	2.66
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETJ
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper for AT&T Graphviz

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	dot:graphics/graphviz \
		p5-Data-Section-Simple>=0.02:devel/p5-Data-Section-Simple \
		p5-File-Which>=1.21:sysutils/p5-File-Which \
		p5-Graph>=0.9716,1:math/p5-Graph \
		p5-IPC-Run3>=0.048:devel/p5-IPC-Run3 \
		p5-Moo>=2.001001:devel/p5-Moo \
		p5-Type-Tiny>=1.000005:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Snapshot>=0.06:devel/p5-Test-Snapshot

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
