PORTNAME=	Ima-DBI
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERRIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Database connection caching and organization

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBIx-ContextualFetch>=0:databases/p5-DBIx-ContextualFetch \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
