# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	SWF-Builder
PORTVERSION=	0.16
CATEGORIES=	graphics www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create SWF movie

BUILD_DEPENDS=	p5-SWF-File>=0:${PORTSDIR}/graphics/p5-SWF-File \
		p5-Math-Bezier-Convert>=0:${PORTSDIR}/math/p5-Math-Bezier-Convert \
		p5-Font-TTF>=0:${PORTSDIR}/x11-fonts/p5-Font-TTF
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
