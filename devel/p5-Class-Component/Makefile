# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	Class-Component
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pluggable component framework

BUILD_DEPENDS=	p5-Carp-Clan>0:devel/p5-Carp-Clan \
		p5-Class-Accessor>0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>0:devel/p5-Class-Data-Inheritable \
		p5-Class-Inspector>0:devel/p5-Class-Inspector \
		p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
