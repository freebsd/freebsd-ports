PORTNAME=	Inline-Java
PORTVERSION=	0.540
PORTREVISION=	2
CATEGORIES=	devel java perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write Perl subroutines and classes in Java
WWW=		https://metacpan.org/release/Inline-Java

LICENSE=	ARTPERL10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Inline>=0.68:devel/p5-Inline \
		p5-Inline-C>=0.62:devel/p5-Inline-C

USES=		java perl5
JAVA_OS=	native
USE_PERL5=	configure

CONFIGURE_ARGS=	J2SDK=${JAVA_HOME} </dev/null

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
