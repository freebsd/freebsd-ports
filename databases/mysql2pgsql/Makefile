PORTNAME=	mysql2pgsql
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1535/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.perl

MAINTAINER=	klossalex@gmail.com
COMMENT=	Convert a MySQL dump to a PostgreSQL dump

USES=		perl5 shebangfix
NO_BUILD=	yes

SHEBANG_FILES=	mysql2pgsql.perl
PLIST_FILES=	bin/mysql2pgsql

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} -p ${DISTDIR}/mysql2pgsql.perl ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mysql2pgsql.perl \
		${STAGEDIR}${PREFIX}/bin/mysql2pgsql

.include <bsd.port.mk>
