PORTNAME=	DBIx-Class-Cursor-Cached
PORTVERSION=	1.001004
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cursor class with built-in caching support

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Carp-Clan>=6.0:devel/p5-Carp-Clan \
		p5-DBIx-Class>=0.08124:databases/p5-DBIx-Class
TEST_DEPENDS=	p5-Cache-Cache>=0:devel/p5-Cache-Cache \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
