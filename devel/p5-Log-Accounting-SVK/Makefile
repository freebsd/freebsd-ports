# Created by: Yuan-Chung Hsiao <ychsiao@ychsiao.idv.tw>
# $FreeBSD$

PORTNAME=	Log-Accounting-SVK
PORTVERSION=	0.05
PORTREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Perl module for accounting SVK repository

BUILD_DEPENDS=	svk>=0:devel/svk \
		p5-Spiffy>=0:devel/p5-Spiffy \
		p5-Graph-SocialMap>=0:graphics/p5-Graph-SocialMap \
		p5-Graph-Writer-GraphViz>=0:graphics/p5-Graph-Writer-GraphViz \
		p5-Algorithm-Accounting>=0:devel/p5-Algorithm-Accounting
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
