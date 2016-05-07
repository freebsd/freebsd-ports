# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Event-Sunrise
PORTVERSION=	0.05.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DateTime Objects for sunrise and sunset for a given day

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0.21:devel/p5-DateTime \
		p5-DateTime-Set>=0.16:devel/p5-DateTime-Set \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Set-Infinite>=0:devel/p5-Set-Infinite
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
