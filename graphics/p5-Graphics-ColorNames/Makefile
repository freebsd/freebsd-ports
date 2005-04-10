# New ports collection makefile for:	p5-Graphics-ColorNames
# Date Created:				1 July 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	Graphics-ColorNames
PORTVERSION=	1.05
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Graphics
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A perl class that defines RGB values for common color names

PERL_CONFIGURE=	yes

MAN3=	Graphics::ColorNames.3 \
	Graphics::ColorNames::HTML.3 \
	Graphics::ColorNames::Netscape.3 \
	Graphics::ColorNames::Windows.3 \
	Graphics::ColorNames::X.3 \
	Graphics::ColourNames.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not build on FreeBSD 4.x"
.endif

.include <bsd.port.post.mk>
