# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DateTime-Astro
PORTVERSION=	0.99.999
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}_03

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Functions For Astromical Calendars

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Set>=0:${PORTSDIR}/devel/p5-DateTime-Set
LIB_DEPENDS=	mpfr:${PORTSDIR}/math/mpfr
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USE_PERL5=	configure
USES=		perl5
USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAN3=		DateTime::Astro.3 \
		DateTime::Event::SolarTerm.3

post-configure:
	@${REINPLACE_CMD} -e '/^INC = / s|$$| -I${LOCALBASE}/include|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
