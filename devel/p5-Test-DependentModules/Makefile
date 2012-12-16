# New ports collection makefile for:	p5-Test-DependentModules
# Date created:		2012-01-06
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-DependentModules
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test all modules which depend on your module

BUILD_DEPENDS=	p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-File-chdir>=0:${PORTSDIR}/devel/p5-File-chdir \
		p5-Parallel-ForkManager>=0.7.6:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-IO-Handle-Util>=0:${PORTSDIR}/devel/p5-IO-Handle-Util \
		p5-IPC-Run3>=0:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-MetaCPAN-API>=0:${PORTSDIR}/devel/p5-MetaCPAN-API \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-autodie>=0:${PORTSDIR}/devel/p5-autodie
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::DependentModules.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
