PORTNAME=	Net-DNS-ZoneFile-Fast
DISTVERSION=	1.27
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HARDAKER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to parse BIND8/9 zone files
WWW=		https://metacpan.org/release/Net-DNS-ZoneFile-Fast

LICENSE=	BSD3CLAUSE

DEPRECATED=	Upstream module marked obsolete by its author
EXPIRATION_DATE=	2026-10-23

BUILD_RUN_DEPENDS=	p5-Net-DNS>=0.65:dns/p5-Net-DNS \
		p5-Net-DNS-SEC>=0.15:dns/p5-Net-DNS-SEC

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
