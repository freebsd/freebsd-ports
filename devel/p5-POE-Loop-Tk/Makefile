# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	POE-Loop-Tk
PORTVERSION=	1.305
PORTREVISION=	2
CATEGORIES=	devel tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bridge that allows POE to be driven by Tk

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-POE>=1.356:devel/p5-POE \
		p5-Tk>=804.031:x11-toolkits/p5-Tk

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '/POE::Test::Loops/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
