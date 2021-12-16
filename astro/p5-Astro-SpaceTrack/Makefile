# Created by: Gea-Suan Lin <gslin@gslin.org>

PORTNAME=	Astro-SpaceTrack
PORTVERSION=	0.148
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve orbital data from www.space-track.org

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSES/Artistic
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSES/Copying

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Date>=0:www/p5-HTTP-Date \
		p5-HTTP-Message>=6.03:www/p5-HTTP-Message \
		p5-JSON>=0:converters/p5-JSON \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	-y
NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

.include <bsd.port.mk>
