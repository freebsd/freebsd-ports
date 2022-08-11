PORTNAME=	DBIx-Safe
PORTVERSION=	1.2.5
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TURNSTEP
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Safer access to your database through a DBI database handle

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBD-Pg>=1.49:databases/p5-DBD-Pg \
		p5-DBI>=1.490:databases/p5-DBI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
