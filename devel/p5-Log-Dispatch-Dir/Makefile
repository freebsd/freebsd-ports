# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Log-Dispatch-Dir
PORTVERSION=	0.160
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Log messages to separate files in a directory, with rotate options

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-Log-Dispatch>=0:devel/p5-Log-Dispatch \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Probe-Perl>=0:sysutils/p5-Probe-Perl
TEST_DEPENDS=	p5-File-LibMagic>=0:devel/p5-File-LibMagic \
		p5-Media-Type-Simple>=0:devel/p5-Media-Type-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
