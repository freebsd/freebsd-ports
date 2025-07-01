PORTNAME=	Zonemaster-LDNS
DISTVERSION=	5.0.0
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ZNMSTR
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl wrapper for the ldns DNS library
WWW=		https://zonemaster.net/en/run-test

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Devel-CheckLib>0:devel/p5-Devel-CheckLib \
	p5-ExtUtils-PkgConfig>0:devel/p5-ExtUtils-PkgConfig \
	p5-Module-Install>0:devel/p5-Module-Install
LIB_DEPENDS=	libidn2.so:dns/libidn2 \
	libldns.so:dns/ldns

USES=		gmake localbase perl5 ssl
USE_PERL5=	configure
CONFIGURE_SCRIPT+=	Makefile.PL --no-internal-ldns

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Zonemaster/LDNS/LDNS.so

.include <bsd.port.mk>
