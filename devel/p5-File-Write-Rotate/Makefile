# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Write-Rotate
PORTVERSION=	0.28
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write to files that archive/rotate themselves

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Flock-Retry>=0:${PORTSDIR}/devel/p5-File-Flock-Retry \
		p5-Proc-PID-File>=0:${PORTSDIR}/devel/p5-Proc-PID-File \
		p5-Taint-Runtime>=0.03:${PORTSDIR}/devel/p5-Taint-Runtime
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-Perl-osnames>=0.09:${PORTSDIR}/devel/p5-Perl-osnames
TEST_DEPENDS=	p5-File-Slurp-Tiny>=0:${PORTSDIR}/devel/p5-File-Slurp-Tiny \
		p5-File-chdir>=0:${PORTSDIR}/devel/p5-File-chdir \
		p5-Test-Exception>=0.31:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Warnings>=0.014:${PORTSDIR}/devel/p5-Test-Warnings

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
