# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	liquibase
PORTVERSION=	2.0.5
CATEGORIES=	databases java
MASTER_SITES=	http://cloud.github.com/downloads/liquibase/liquibase/
DISTFILES=	${PORTNAME}-${PORTVERSION}-bin${EXTRACT_SUFX}

MAINTAINER=	gslin@gslin.org
COMMENT=	Database Change Management

LICENSE=	APACHE20

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_JAVA=	yes

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/liquibase.jar ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/liquibase ${PREFIX}/bin/

.include <bsd.port.mk>
