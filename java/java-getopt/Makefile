# Ports collection makefile for:	java-getopt
# Date created:			Apr 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	getopt
PORTVERSION=	1.0.13
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	http://www.urbanophile.com/~arenn/hacking/getopt/
PKGNAMEPREFIX=	java-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java version of GNU getopt family functions

USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	jar

NO_WRKSUBDIR=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
.if !defined(NOPORTDOCS)
OTHERDOCS=	COPYING.LIB ChangeLog README
PORTDOCS=	api ${OTHERDOCS}
ALL_TARGET+=	javadoc
.endif

post-extract:
	@${CP} ${WRKSRC}/gnu/getopt/buildx.xml ${WRKSRC}/build.xml

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/build/lib/gnu.getopt.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}/api
	@cd ${WRKSRC}/build/ && ${FIND} api \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/gnu/getopt/,} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
