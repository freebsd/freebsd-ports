PORTNAME=	Form-Sensible
PORTVERSION=	0.20023
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sensible way to handle form based user interface

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-Natural>=0:devel/p5-DateTime-Format-Natural \
		p5-DateTime-Set>=0:devel/p5-DateTime-Set \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Moose>=2:devel/p5-Moose \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/lib/Form/Sensible/Renderer/HTML/RenderedForm.pm.orig

.include <bsd.port.mk>
