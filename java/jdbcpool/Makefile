# New ports collection makefile for:    JDBC connection pool
# Date created:		1999/07/04
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	jdbcpool
PORTVERSION=	0.99
CATEGORIES=	java
MASTER_SITES=	http://www.bitmechanic.com/projects/jdbcpool/dist/

MAINTAINER=	noway@nohow.demon.co.uk

USE_JAVA=	1.2+
NO_BUILD=	yes
TARGET_DIR=	${PREFIX}/share/java/${PORTNAME}
JAR_DEST=	${PREFIX}/share/java/classes
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}

do-install:
	${MKDIR} ${TARGET_DIR} ${JAR_DEST}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${JAR_DEST}/${PORTNAME}.jar
	cd ${WRKSRC}; \
		${RM} -rf `${FIND} examples javadoc -name CVS -type dir`; \
		${CP} -R examples javadoc CHANGES LICENSE README ${TARGET_DIR}

.include <bsd.port.mk>
