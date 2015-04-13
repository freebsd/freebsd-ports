# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Format-Epoch
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert DateTimes to/from epoch seconds

RUN_DEPENDS=	p5-DateTime>=0.31:${PORTSDIR}/devel/p5-DateTime \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS:=	${RUN_DEPENDS}

PORTSCOUT=	skipv:0.801

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
