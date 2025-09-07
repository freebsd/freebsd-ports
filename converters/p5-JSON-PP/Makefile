PORTNAME=	JSON-PP
PORTVERSION=	4.16
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ISHIGAKI
PKGNAMEPREFIX=	p5-

PATCH_SITES=	https://github.com/makamaka/JSON-PP/commit/
PATCHFILES=	7052740e158491666e4f27d75241617a16170102.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON::XS compatible pure-Perl module
WWW=		https://metacpan.org/release/JSON-PP

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

post-patch:
	@${MV} ${WRKSRC}/bin/json_pp ${WRKSRC}/bin/p5json_pp

.include <bsd.port.mk>
