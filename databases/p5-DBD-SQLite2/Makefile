# Created by: nork@cityfujisawa.ne.jp
# $FreeBSD$

PORTNAME=	DBD-SQLite2
PORTVERSION=	0.37
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides access to SQLite2 databases through the DBI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/getsqlite.pl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/SQLite2/SQLite2.so

.include <bsd.port.mk>
