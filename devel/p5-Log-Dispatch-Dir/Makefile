# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Log-Dispatch-Dir
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Log messages to separate files in a directory, with rotate options

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Probe-Perl>=0:${PORTSDIR}/sysutils/p5-Probe-Perl \
		p5-Taint-Util>=0:${PORTSDIR}/devel/p5-Taint-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-LibMagic>=0:${PORTSDIR}/devel/p5-File-LibMagic \
		p5-Media-Type-Simple>=0:${PORTSDIR}/devel/p5-Media-Type-Simple

USE_PERL5=	modbuild
USES=		perl5

MAN3=		Log::Dispatch::Dir.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
