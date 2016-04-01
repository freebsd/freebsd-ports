# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	CPAN-Inject
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Base class for injecting distributions into CPAN sources

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-chmod>=0.30:devel/p5-File-chmod \
		p5-Params-Util>=0.21:devel/p5-Params-Util \
		p5-CPAN-Checksums>=1.05:devel/p5-CPAN-Checksums
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Script-Run>=1.02:devel/p5-Test-Script-Run \
		p5-File-Remove>=0.34:devel/p5-File-Remove \
		p5-Compress-Bzip2>=0:archivers/p5-Compress-Bzip2 \
		p5-Test-Script>=1.02:devel/p5-Test-Script

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
