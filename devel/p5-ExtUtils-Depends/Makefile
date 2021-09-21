# Created by: Sergey Skvortsov <skv@protey.ru>

PORTNAME=	ExtUtils-Depends
PORTVERSION=	0.8001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XAOC
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easily build XS extensions that depend on XS extensions

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 503200
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=7.44:devel/p5-ExtUtils-MakeMaker
RUN_DEPENDS+=	p5-ExtUtils-MakeMaker>=7.44:devel/p5-ExtUtils-MakeMaker
.endif

.include <bsd.port.post.mk>
