# New ports collection makefile for:    JDBC connection pool
# Date created:		1999/07/04
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	jdbcpool
PORTVERSION=	0.94
CATEGORIES=	java
MASTER_SITES=	http://www.bitmechanic.com/projects/jdbcpool/dist/

MAINTAINER=	noway@nohow.demon.co.uk

RUN_DEPENDS=	${PREFIX}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk

JDK_VERSION=	1.1.8
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes ${PREFIX}/share/java/jdbcpool
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${PREFIX}/share/java/classes/jdbcpool.jar
	@cd ${WRKSRC}; \
	  ${RM} -rf CVS; \
	  ${RM} -rf examples/CVS; \
	  ${RM} -rf examples/gsp/CVS; \
	  ${CP} CHANGES ${PREFIX}/share/java/jdbcpool; \
	  ${CP} LICENSE ${PREFIX}/share/java/jdbcpool; \
	  ${CP} README ${PREFIX}/share/java/jdbcpool; \
	  ${CP} -R examples ${PREFIX}/share/java/jdbcpool; \
	  ${CP} -R javadoc ${PREFIX}/share/java/jdbcpool

.include <bsd.port.mk>
