# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Event-Easter
PORTVERSION=	1.04
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Returns Easter events for DateTime objects

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Calendar-Julian>=0:${PORTSDIR}/devel/p5-DateTime-Calendar-Julian \
		p5-DateTime-Set>=0:${PORTSDIR}/devel/p5-DateTime-Set \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
