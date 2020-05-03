# Created by: ijliao
# $FreeBSD$

PORTNAME=	Astro-Catalog
PORTVERSION=	4.35
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic stellar catalogue object

LICENSE=	GPLv3

# p5-Astro-FITS-CFITSIO is a recommended dependency
BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Astro-Coords>=0.12:astro/p5-Astro-Coords \
		p5-Astro-FITS-CFITSIO>=1.03:astro/p5-Astro-FITS-CFITSIO \
		p5-Astro-Flux>=0.01:astro/p5-Astro-Flux \
		p5-Astro-Telescope>=0.50:astro/p5-Astro-Telescope \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-ISO8601>=0:devel/p5-DateTime-Format-ISO8601 \
		p5-Misc-Quality>=0.1:astro/p5-Misc-Quality \
		p5-Number-Uncertainty>=0.1:math/p5-Number-Uncertainty \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite \
		p5-libwww>=5.53:www/p5-libwww

NO_ARCH=	yes
USES=		localbase perl5
USE_PERL5=	modbuild

post-patch:
	@${REINPLACE_CMD} -e '/\.cfg/ s|\.cfg|&.sample|2' ${WRKSRC}/Build.PL

.include <bsd.port.mk>
