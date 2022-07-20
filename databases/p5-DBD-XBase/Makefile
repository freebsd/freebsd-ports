PORTNAME=	DBD-XBase
PORTVERSION=	1.08
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides access to XBase (dBase, Fox*) database files through DBI

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI

USES=		perl5
USE_PERL5=	configure

CONFLICTS_INSTALL=	shapelib

NO_ARCH=	yes

.include <bsd.port.mk>
