# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	App-Cmd
PORTVERSION=	0.331
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Write command-line programs with less suffering

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0.13:devel/p5-Capture-Tiny \
		p5-Class-Load>=0.06:devel/p5-Class-Load \
		p5-Getopt-Long-Descriptive>=0.084:devel/p5-Getopt-Long-Descriptive \
		p5-IO-TieCombine>=0:devel/p5-IO-TieCombine \
		p5-String-RewritePrefix>=0:textproc/p5-String-RewritePrefix \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Sub-Install>=0:devel/p5-Sub-Install \
		p5-Module-Pluggable>=5.1:devel/p5-Module-Pluggable
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-PathTools>=0:devel/p5-PathTools \
		p5-IPC-Cmd>=0:devel/p5-IPC-Cmd

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
