# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Color-Palette
PORTVERSION=	0.100003
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Handle sets of named colors in Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Graphics-Color>=0.21:graphics/p5-Graphics-Color \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
