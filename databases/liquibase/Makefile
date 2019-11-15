# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	liquibase
PORTVERSION=	3.8.1
CATEGORIES=	databases java
MASTER_SITES=	https://github.com/liquibase/liquibase/releases/download/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Database Change Management

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_JAVA=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/liquibase ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${WRKSRC}/liquibase.jar \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
