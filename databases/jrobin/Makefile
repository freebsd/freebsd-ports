# ex:ts=8
# Ports collection makefile for:	JRobin
# Date created:			Mar 9, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jrobin
PORTVERSION=	1.4.0
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	JRobin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pure Java alternative to RRDTool

USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	all-libs
WRKSRC=		${WRKDIR}/${DISTNAME:L}
BUILD_WRKSRC=	${WRKSRC}/ant

.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif

CLASSES=	jrobin jrobin-demo convertor inspector mrtg-client mrtg-server

do-install:
.for c in ${CLASSES}
	${INSTALL_DATA} ${WRKSRC}/lib/${c}-${PORTVERSION}.jar ${JAVAJARDIR}/${c}.jar
	@${ECHO} '${JAVAJARDIR:S,^${PREFIX}/,,}/${c}.jar' >> ${TMPPLIST}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
