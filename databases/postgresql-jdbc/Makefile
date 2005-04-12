# New ports collection makefile for:	PostgreSQL JDBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTVERSION=	8.0.311
DISTVERSIONSUFFIX=.src
PORTREVISION=	0
CATEGORIES=	databases java
MASTER_SITES=	http://jdbc.postgresql.org/download/
PKGNAMESUFFIX=	-jdbc
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION:C/.([0-9][0-9][0-9]*)/-\1/g}${DISTVERSIONSUFFIX}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	The Java JDBC implementation for PostgreSQL

DIST_SUBDIR=	postgresql

USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION?=	"1.1+"
USE_REINPLACE=	yes

PKGMESSAGE=	${WRKDIR}/.pkg-message

post-patch:
	${REINPLACE_CMD} 's,/usr/local/pgsql/share/java,${PREFIX}/share/java/classes,' ${WRKSRC}/README

do-install:
	@- ${MKDIR} -m 0755 ${PREFIX}/share/java/classes ;\
	  ${INSTALL_DATA} ${WRKSRC}/jars/postgresql.jar \
		${PREFIX}/share/java/classes/postgresql.jar ;\
	  ${MKDIR} -m 0755 ${DOCSDIR} ;\
	  ${INSTALL_DATA} ${WRKSRC}/README \
			  ${DOCSDIR}/README-jdbc
.if !defined(NOPORTDOCS)
	@- ${MKDIR} -m 0755 ${EXAMPLESDIR}/jdbc ;\
	  ${INSTALL_DATA} ${WRKSRC}/jars/postgresql-examples.jar \
			  ${EXAMPLESDIR}/jdbc/postgresql-examples.jar ;\
	  cd ${WRKSRC}/example ;\
	  ${PAX} -rw . ${EXAMPLESDIR}/jdbc
.endif

post-install:
	@ ${SED} "s|%%PREFIX%%|${PREFIX}|g" \
	  < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
