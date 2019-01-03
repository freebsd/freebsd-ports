# Created by: nork@cityfujisawa.ne.jp
# $FreeBSD$

PORTNAME=	DBD-SQLite
PORTVERSION=	1.62
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides access to SQLite3 databases through the DBI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=1.57:databases/p5-DBI

PORTSCOUT=	limit:^[0-9\.]*$$

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	BUNDLED_SQLITE
OPTIONS_DEFAULT=BUNDLED_SQLITE

BUNDLED_SQLITE_DESC=		Use bundled SQLite (otherwise, from databases/sqlite3)
BUNDLED_SQLITE_LIB_DEPENDS_OFF=	libsqlite3.so:databases/sqlite3
BUNDLED_SQLITE_CONFIGURE_OFF=	USE_LOCAL_SQLITE=0 SQLITE_LOCATION=${LOCALBASE}

post-patch-BUNDLED_SQLITE-off:
	${REINPLACE_CMD} -e 's/if ( 0 )/if ( 1 )/' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/SQLite/SQLite.so

.include <bsd.port.mk>
