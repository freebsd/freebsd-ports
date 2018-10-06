# Created by: Andrey Kostenko <andrey@kostenko.name>
# $FreeBSD$

PORTNAME=	DBIx-Custom
PORTVERSION=	0.4000
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/00$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Customizable DBI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBD-SQLite>=1.25:databases/p5-DBD-SQLite \
		p5-DBI>=1.60.5:databases/p5-DBI \
		p5-DBIx-Connector>=0.56:databases/p5-DBIx-Connector \
		p5-Object-Simple>=3.1000:devel/p5-Object-Simple

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
