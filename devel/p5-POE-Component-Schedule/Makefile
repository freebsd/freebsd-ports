# Created by: mat
# $FreeBSD$

PORTNAME=	POE-Component-Schedule
PORTVERSION=	0.95
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Schedule POE Events using a cron spec

BUILD_DEPENDS=	p5-POE>=0:devel/p5-POE \
		p5-DateTime-Set>=0:devel/p5-DateTime-Set
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
