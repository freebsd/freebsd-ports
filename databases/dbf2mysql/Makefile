# Created by: jedgar@fxp.org
# $FreeBSD$

PORTNAME=	dbf2mysql
PORTVERSION=	1.14
PORTREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Contrib/Old-Versions

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to convert .dbf files to MySQL tables and vice versa

USE_MYSQL=	yes

PORTDOCS=	README
PLIST_FILES=	bin/dbf2mysql bin/mysql2dbf

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbf2mysql ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mysql2dbf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
