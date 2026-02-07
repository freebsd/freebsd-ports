PORTNAME=	MIDI-Perl
PORTVERSION=	0.84
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for handling MIDI files
WWW=		https://metacpan.org/release/MIDI-Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	GD

GD_BUILD_DEPENDS=	p5-GD>=0:graphics/p5-GD
GD_RUN_DEPENDS=		p5-GD>=0:graphics/p5-GD

.include <bsd.port.mk>
