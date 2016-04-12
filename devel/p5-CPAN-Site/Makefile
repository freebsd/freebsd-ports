# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	CPAN-Site
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Extend CPAN with private packages

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Tar>=1.00:archivers/p5-Archive-Tar \
		p5-Compress-Bzip2>=0:archivers/p5-Compress-Bzip2 \
		p5-CPAN-Checksums>=0:devel/p5-CPAN-Checksums \
		p5-libwww>=0:www/p5-libwww \
		p5-IO-Zlib>=0:archivers/p5-IO-Zlib \
		p5-Log-Report>=0.25:devel/p5-Log-Report
RUN_DEPENDS=	p5-Archive-Tar>=1.00:archivers/p5-Archive-Tar \
		p5-Compress-Bzip2>=0:archivers/p5-Compress-Bzip2 \
		p5-CPAN-Checksums>=0:devel/p5-CPAN-Checksums \
		p5-libwww>=0:www/p5-libwww \
		p5-IO-Zlib>=0:archivers/p5-IO-Zlib \
		p5-Log-Report>=0.25:devel/p5-Log-Report

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
