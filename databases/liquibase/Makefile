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

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/liquibase.jar ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/liquibase ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
