# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	pip
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl Installation Program

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Zip>=1.29:archivers/p5-Archive-Zip \
		p5-CPAN-Inject>=0.07:devel/p5-CPAN-Inject \
		p5-File-Which>=1.08:sysutils/p5-File-Which \
		p5-File-pushd>=0.32:devel/p5-File-pushd \
		p5-PAR-Dist>=0.25:devel/p5-PAR-Dist \
		p5-Params-Util>=1.00:devel/p5-Params-Util \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-LWP-Online>=0:www/p5-LWP-Online \
		p5-Test-Script>=0:devel/p5-Test-Script \
		p5-Compress-Bzip2>=0:archivers/p5-Compress-Bzip2

USES=		perl5
USE_PERL5=	configure

post-configure:
	@${REINPLACE_CMD} 's|(INST_SCRIPT)/pip|(INST_SCRIPT)/pip-perl|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
