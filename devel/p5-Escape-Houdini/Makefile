PORTNAME=	Escape-Houdini
DISTVERSION=	0.3.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YANICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	siva@FreeBSD.org
COMMENT=	Perl API to Houdini, a zero-dependency C web escaping library
WWW=		https://metacpan.org/dist/Escape-Houdini

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Escape/Houdini/Houdini.so

.include <bsd.port.mk>
