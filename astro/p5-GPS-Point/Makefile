# $FreeBSD$

PORTNAME=	GPS-Point
PORTVERSION=	0.20
CATEGORIES=	astro perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bscott@bunyatech.com.au
COMMENT=	Provides an object interface for a GPS point

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Test-Number-Delta>0:devel/p5-Test-Number-Delta \
		p5-Test-Simple>=0.44:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
PLIST_FILES=	${SITE_PERL_REL}/GPS/Point.pm \
		${SITE_MAN3_REL}/GPS::Point.3.gz

.include <bsd.port.mk>
