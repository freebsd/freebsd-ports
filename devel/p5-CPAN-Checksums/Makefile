# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	CPAN-Checksums
PORTVERSION=	2.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to write a CHECKSUMS file for a directory as on CPAN

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Compare>=0:devel/p5-Data-Compare \
		p5-Compress-Bzip2>=0:archivers/p5-Compress-Bzip2 \
		p5-Module-Signature>=0:security/p5-Module-Signature
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
