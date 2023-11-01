PORTNAME=	Term-TermKey
DISTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl wrapper around libtermkey
WWW=		https://metacpan.org/pod/Term::TermKey

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Build-Using-PkgConfig>=0:devel/p5-Module-Build-Using-PkgConfig
LIB_DEPENDS=	libtermkey.so:devel/libtermkey

USES=		perl5 pkgconfig
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Term/TermKey/TermKey.so

.include <bsd.port.mk>
