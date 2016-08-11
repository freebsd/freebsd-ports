# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Write-Rotate
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write to files that archive/rotate themselves

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-Flock-Retry>=0:devel/p5-File-Flock-Retry \
		p5-Proc-PID-File>=0:devel/p5-Proc-PID-File
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-File-chdir>=0:devel/p5-File-chdir \
		p5-Taint-Runtime>=0:devel/p5-Taint-Runtime \
		p5-Test-Exception>=0.31:devel/p5-Test-Exception \
		p5-Test-Warnings>=0.014:devel/p5-Test-Warnings

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
