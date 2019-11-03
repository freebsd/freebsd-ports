# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Astro-App-Satpass2
PORTVERSION=	0.041
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Forecast satellite visibility

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Astro-SIMBAD-Client>=0:astro/p5-Astro-SIMBAD-Client \
		p5-Astro-satpass>=0.077:astro/p5-Astro-satpass \
		p5-Clone>=0:devel/p5-Clone \
		p5-File-HomeDir>=0.93:devel/p5-File-HomeDir \
		p5-IPC-System-Simple>=0:devel/p5-IPC-System-Simple \
		p5-Template-Toolkit>=2.21:www/p5-Template-Toolkit

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
