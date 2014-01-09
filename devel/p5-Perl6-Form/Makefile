# Created by: Yuan-Chung Hsiao <ychsiao@ychsiao.idv.tw>
# $FreeBSD$

PORTNAME=	Perl6-Form
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Implements the Perl 6 'form' built-in

BUILD_DEPENDS=	p5-Perl6-Export>=0:${PORTSDIR}/devel/p5-Perl6-Export \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
