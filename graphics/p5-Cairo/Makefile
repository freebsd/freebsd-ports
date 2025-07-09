PORTNAME=	Cairo
PORTVERSION=	1.109
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN \
		SF/gtk2-perl/Cairo/${PORTVERSION}
MASTER_SITE_SUBDIR=	CPAN:XAOC
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl bindings to the cairo graphics library
WWW=		https://gtk2-perl.sourceforge.net/

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.200:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1:devel/p5-ExtUtils-PkgConfig
LIB_DEPENDS=	libcairo.so:graphics/cairo
TEST_DEPENDS=	p5-Font-FreeType>=0:print/p5-Font-FreeType \
		p5-Test-Number-Delta>=1:devel/p5-Test-Number-Delta

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Cairo/Cairo.so

.include <bsd.port.mk>
