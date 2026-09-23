PORTNAME=	DateTime-Format-IBeat
DISTVERSION=	0.161
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EMARTIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Format times in .beat notation
WWW=		https://metacpan.org/release/EMARTIN/DateTime-Format-IBeat-0.161

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

DEPRECATED=	Upstream distribution has never had an authorized release on CPAN
EXPIRATION_DATE=	2026-10-23

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
