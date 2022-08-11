PORTNAME=	Imager-Plot
PORTVERSION=	0.09
PORTREVISION=	7
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl extension for generating fancy graphic plots in color

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Imager>=0:graphics/p5-Imager

USES=		perl5 shebangfix
SHEBANG_FILES=	plot.pl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
