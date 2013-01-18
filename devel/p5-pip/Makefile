# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	pip
PORTVERSION=	1.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Perl Installation Program

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Zip>=1.29:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-CPAN-Inject>=0.07:${PORTSDIR}/devel/p5-CPAN-Inject \
		p5-File-Which>=1.08:${PORTSDIR}/sysutils/p5-File-Which \
		p5-File-pushd>=0.32:${PORTSDIR}/devel/p5-File-pushd \
		p5-PAR-Dist>=0.25:${PORTSDIR}/devel/p5-PAR-Dist \
		p5-Params-Util>=1.00:${PORTSDIR}/devel/p5-Params-Util \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-LWP-Online>=0:${PORTSDIR}/www/p5-LWP-Online \
		p5-Test-Script>=0:${PORTSDIR}/devel/p5-Test-Script \
		p5-Compress-Bzip2>=0:${PORTSDIR}/archivers/p5-Compress-Bzip2

PERL_CONFIGURE=	YES

MAN3=		Module::Plan::Base.3 \
		Module::Plan::Lite.3 \
		pip.3

post-configure:
	@${REINPLACE_CMD} 's|(INST_SCRIPT)/pip|(INST_SCRIPT)/pip-perl|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
