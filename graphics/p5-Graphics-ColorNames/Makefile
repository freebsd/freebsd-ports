# New ports collection makefile for:	p5-Graphics-ColorNames
# Date Created:				1 July 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	Graphics-ColorNames
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Graphics
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl class that defines RGB values for common color names

BUILD_DEPENDS=	${SITE_PERL}/Module/Load.pm:${PORTSDIR}/devel/p5-Module-Load
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Graphics::ColorNames.3 \
	Graphics::ColorNames::HTML.3 \
	Graphics::ColorNames::Netscape.3 \
	Graphics::ColorNames::Windows.3 \
	Graphics::ColorNames::X.3 \
	Graphics::ColourNames.3

post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' \
		${WRKSRC}/lib/Graphics/ColorNames.pm

.include <bsd.port.mk>
