# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	Graphics-ColorNames-WWW
PORTVERSION=	1.13
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	WWW color names and equivalent RGB values

RUN_DEPENDS=	p5-Graphics-ColorNames>=0.32:${PORTSDIR}/graphics/p5-Graphics-ColorNames
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
