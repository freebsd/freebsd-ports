PORTNAME=	File-Finder
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Nice wrapper for File::Find ala find(1)
WWW=		https://metacpan.org/release/File-Finder

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Text-Glob>0:textproc/p5-Text-Glob
TEST_DEPENDS=	p5-File-Find-Rule>0:devel/p5-File-Find-Rule

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
