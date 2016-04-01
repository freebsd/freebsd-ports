# Created by: Yuan-Chung Hsiao <ychsiao@ychsiao.org>
# $FreeBSD$

PORTNAME=	SVN-Log
PORTVERSION=	0.03
PORTREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	SVN::Log - Extract change logs from a Subversion server

BUILD_DEPENDS=	p5-subversion>=0:devel/p5-subversion \
		p5-Test-Simple>=0:devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
