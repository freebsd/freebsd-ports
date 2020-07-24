# $FreeBSD$

PORTNAME=	DBD-Pg
PORTVERSION=	3.14.0
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides access to PostgreSQL databases through the DBI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSES/artistic.txt

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=1.614:databases/p5-DBI

USES=		perl5 pgsql
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/Pg/Pg.so

.include <bsd.port.mk>
