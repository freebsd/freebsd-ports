PORTNAME=	Test-NoWarnings
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Hide and store warnings while running test scripts

LICENSE=	LGPL21

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	DEVEL_STACKTRACE
DEVEL_STACKTRACE_DESC=	Stack trace support

DEVEL_STACKTRACE_BUILD_DEPENDS=	p5-Devel-StackTrace>=0:devel/p5-Devel-StackTrace
DEVEL_STACKTRACE_RUN_DEPENDS=	p5-Devel-StackTrace>=0:devel/p5-Devel-StackTrace

.include <bsd.port.mk>
