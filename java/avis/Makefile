# Created by: Benjamin Close <benjsc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avis
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	java net
MASTER_SITES=	SF/${PORTNAME}/Avis%20router/Release%20${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	benjsc@FreeBSD.org
COMMENT=	Elvin Publish/Subscribe Message Bus server based on the Elvin protocol

USES=		zip
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if !defined(WITHOUT_COMPILE)
BUILD_DEPENDS+=	${ANT_CMD}:devel/apache-ant
ANT_CMD?=	${LOCALBASE}/bin/ant
ANT=		${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT_CMD}
ANT_TARGETS=	jar-server
JAVA_BUILD=	yes
.endif

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.txt\
		LICENSE.txt\
		history.txt

.include <bsd.port.pre.mk>

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITHOUT_COMPILE=yes    Install the pre-compiled .jar file"
	@${ECHO_MSG} ""

do-build:
.if !defined(WITHOUT_COMPILE)
	@cd ${WRKSRC}/server && ${ANT} ${ANT_TARGETS}
.endif

do-install:
	@${ECHO_CMD} -n  ">> Installing avisd..."
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/avis/
	@${INSTALL_SCRIPT} ${WRKSRC}/server/bin/avisd ${STAGEDIR}${PREFIX}/sbin/avisd
	@${INSTALL_DATA} ${WRKSRC}/server/lib/avis-router.jar ${STAGEDIR}${PREFIX}/libexec/avis/avis-router.jar
	@${ECHO_CMD} " [DONE]"
	@${INSTALL_DATA} ${WRKSRC}/server/etc/avisd.config ${STAGEDIR}${PREFIX}/etc/avisd.conf.sample

	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/server/doc && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
