# New ports collection makefile for:	p5-Graphics-ColorNames
# Date Created:				1 July 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	Graphics-ColorNames
PORTVERSION=	2.04
PORTREVISION=	0
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl class that defines RGB values for common color names

BUILD_DEPENDS=	p5-Module-Load>=0.10:${PORTSDIR}/devel/p5-Module-Load
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Graphics::ColorNames.3 \
	Graphics::ColorNames::HTML.3 \
	Graphics::ColorNames::Netscape.3 \
	Graphics::ColorNames::Windows.3 \
	Graphics::ColorNames::X.3

.include <bsd.port.mk>
