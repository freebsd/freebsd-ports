# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	CPAN-Meta
PORTVERSION=	2.150005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Distribution metadata for a CPAN dist

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Parse-CPAN-Meta>=1.44.14:devel/p5-Parse-CPAN-Meta
RUN_DEPENDS+=	p5-Parse-CPAN-Meta>=1.44.14:devel/p5-Parse-CPAN-Meta
.endif

.include <bsd.port.post.mk>
