# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Format-ICal
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse and format ICal datetime and duration strings

RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-TimeZone>=0:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-DateTime-Event-ICal>=0:${PORTSDIR}/devel/p5-DateTime-Event-ICal \
		p5-DateTime-Set>=0:${PORTSDIR}/devel/p5-DateTime-Set \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
