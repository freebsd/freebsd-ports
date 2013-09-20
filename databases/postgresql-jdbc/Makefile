# Created by: Palle Girgensohn <girgen@partitur.se>
# $FreeBSD$

PORTNAME=	postgresql
PORTVERSION=	9.1.902
PORTREVISION=	1
DISTVERSIONSUFFIX=.src
CATEGORIES=	databases java
MASTER_SITES=	http://jdbc.postgresql.org/download/
PKGNAMESUFFIX=	-jdbc
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION:C/.([0-9][0-9][0-9]*)/-\1/g}${DISTVERSIONSUFFIX}

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	The Java JDBC implementation for PostgreSQL

DIST_SUBDIR=	postgresql

USE_ANT=	yes
USE_JAVA=	yes

PLIST_FILES=	%%JAVAJARDIR%%/postgresql.jar
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
SUB_FILES=	pkg-message

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} 's,/usr/local/pgsql/share/java,${JAVAJARDIR},' ${WRKSRC}/README

.include <bsd.port.options.mk>

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/jars/postgresql.jar ${JAVAJARDIR}/postgresql.jar
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
