# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	liquibase
PORTVERSION=	3.3.2
DISTVERSIONSUFFIX=	-bin
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/Liquibase%20Core

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Database Change Management

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_JAVA=	yes

PLIST_FILES=	bin/liquibase %%DATADIR%%/liquibase.jar

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} liquibase \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} liquibase.jar \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
