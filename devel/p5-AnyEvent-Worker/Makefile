# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	AnyEvent-Worker
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Manage blocking task in external process

BUILD_DEPENDS=	p5-AnyEvent>=5:devel/p5-AnyEvent \
		p5-Storable>=0:devel/p5-Storable \
		p5-common-sense>=2:devel/p5-common-sense \
		p5-Test-NoWarnings>=1.03:devel/p5-Test-NoWarnings \
		p5-Test-TCP>=0.14:devel/p5-Test-TCP \
		p5-lib-abs>=0.90:devel/p5-lib-abs
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
