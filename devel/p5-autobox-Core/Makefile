# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	autobox-Core
PORTVERSION=	1.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Core functions exposed as methods in primitive types

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Want>=0.26:devel/p5-Want \
		p5-autobox>=2.71:devel/p5-autobox
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
