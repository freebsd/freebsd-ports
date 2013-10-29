# Created by: mat
# $FreeBSD$

PORTNAME=	DateTime-HiRes
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create DateTime objects with sub-second current time resolution

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
