PORTNAME=	Linux-Inotify2
PORTVERSION=	2.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MLEHMANN
PKGNAMEPREFIX=	p5-

MAINTAINER=	martin@waschbuesch.de
COMMENT=	Scalable directory/file change notification using Inotify syscalls
WWW=		https://metacpan.org/release/Linux-Inotify2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-common-sense>=3.75:devel/p5-common-sense \
		p5-Scalar-List-Utils>=1.70:lang/p5-Scalar-List-Utils
TEST_DEPENDS=	p5-Test-Simple>=1.302214:devel/p5-Test-Simple

USES=		inotify perl5
USE_PERL5=	configure

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
