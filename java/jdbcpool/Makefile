# New ports collection makefile for:    JDBC connection pool
# Date created:		1999/07/04
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	jdbcpool
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	java databases
MASTER_SITES=	http://www.bitmechanic.com/projects/jdbcpool/dist/

MAINTAINER=	java@FreeBSD.org
COMMENT=	JDBC connection pool

USE_JAVA=	yes
JAVA_VERSION=	1.2+
NO_BUILD=	yes

PORTDOCS=	CHANGES LICENSE README
.if !defined(NOPORTDOCS)
PORTDOCS+=	javadoc
.endif

post-extract:
	@${FIND} ${WRKSRC} -name CVS -type dir | ${XARGS} ${RM} -rf

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	cd ${WRKSRC}/examples \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;

.include <bsd.port.mk>
