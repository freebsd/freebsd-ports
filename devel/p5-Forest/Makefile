# Created by: chinsan
# $FreeBSD$

PORTNAME=	Forest
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Collection of n-ary tree related modules

RUN_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.17:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-MooseX-Clone>=0.05:${PORTSDIR}/devel/p5-MooseX-Clone
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
