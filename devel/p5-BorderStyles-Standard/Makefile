# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	BorderStyles-Standard
PORTVERSION=	0.014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLANCAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standard collection of border styles

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-BorderStyle>=0:devel/p5-BorderStyle \
		p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
