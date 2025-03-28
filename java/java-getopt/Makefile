PORTNAME=	java-getopt
PORTVERSION=	1.0.14
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://www.urbanophile.com/arenn/hacking/getopt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java version of GNU getopt family functions
WWW=		https://www.urbanophile.com/arenn/hacking/download.html #getopt

LICENSE=	LGPL20

USES=		java:ant,run

OPTIONS_DEFINE=	DOCS

ALL_TARGET=	jar

NO_WRKSUBDIR=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
OTHERDOCS=	COPYING.LIB ChangeLog README
PORTDOCS=	api ${OTHERDOCS}
ALL_TARGET+=	javadoc
.endif

post-extract:
	@${CP} ${WRKSRC}/gnu/getopt/buildx.xml ${WRKSRC}/build.xml

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/build/lib/gnu.getopt.jar \
		${STAGEDIR}/${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}/api
	@cd ${WRKSRC}/build/ && ${FIND} api \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} \
	  ${STAGEDIR}/${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/gnu/getopt/,} \
		${STAGEDIR}/${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
