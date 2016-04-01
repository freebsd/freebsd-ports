# Created by: Yuan-Chung Hsiao <ychsiao@ychsiao.org>
# $FreeBSD$

PORTNAME=	SVN-Agent
PORTVERSION=	0.04
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Simple svn manipulation

BUILD_DEPENDS=	p5-subversion>=0:devel/p5-subversion \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-File-Slurp>=0:devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
