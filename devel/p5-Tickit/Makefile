PORTNAME=	Tickit
PORTVERSION=	0.72
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal Interface Construction KIT

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libtickit>=0.4.2:devel/libtickit \
		p5-Module-Build-Using-PkgConfig>=0:devel/p5-Module-Build-Using-PkgConfig \
		${RUN_DEPENDS}
LIB_DEPENDS=	libtickit.so:devel/libtickit
RUN_DEPENDS=	p5-Struct-Dumb>=0.04:devel/p5-Struct-Dumb
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-HexString>=0:devel/p5-Test-HexString \
		p5-Test-Refcount>=0:devel/p5-Test-Refcount

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Tickit/Tickit.so

.include <bsd.port.mk>
