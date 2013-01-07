# $FreeBSD$

PORTNAME=	Color-Scheme
PORTVERSION=	1.04
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Color
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Generate pleasant color schemes

BUILD_DEPENDS=	p5-Test-Differences>=0.47:${PORTSDIR}/devel/p5-Test-Differences
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Color::Scheme.3

.include <bsd.port.mk>
