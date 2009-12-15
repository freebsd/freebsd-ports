# New ports collection makefile for:	p5-Graphics-ColorNames-WWW
# Date created:		2008-07-31
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	Graphics-ColorNames-WWW
PORTVERSION=	1.11
CATEGORIES=	graphics
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	WWW color names and equivalent RGB values

RUN_DEPENDS=	p5-Graphics-ColorNames>=0.32:${PORTSDIR}/graphics/p5-Graphics-ColorNames \
		p5-Params-Validate>=0.75:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

PERL_MODBUILD=	5.8.0+

MAN3=		Graphics::ColorNames::CSS.3 \
		Graphics::ColorNames::IE.3 \
		Graphics::ColorNames::SVG.3 \
		Graphics::ColorNames::WWW.3

.include <bsd.port.mk>
