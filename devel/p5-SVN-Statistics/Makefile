# Created by: Yuan-Chung Hsiao <ychsiao@ychsiao.org>
# $FreeBSD$

PORTNAME=	SVN-Statistics
PORTVERSION=	0.041
PORTREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	SVN::Statistics - perl module to create subversion statistics

BUILD_DEPENDS=	p5-subversion>=0:${PORTSDIR}/devel/p5-subversion \
		p5-RRDTool-OO>=0:${PORTSDIR}/devel/p5-RRDTool-OO \
		p5-Data-Dumper-Simple>=0:${PORTSDIR}/devel/p5-Data-Dumper-Simple \
		p5-IO-Toolkit>=0:${PORTSDIR}/devel/p5-IO-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
