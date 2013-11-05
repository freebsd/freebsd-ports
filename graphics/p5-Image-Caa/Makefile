# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Image-Caa
PORTVERSION=	1.01
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Colored ASCII Art

RUN_DEPENDS=	p5-Curses>=0:${PORTSDIR}/devel/p5-Curses
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demos/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
