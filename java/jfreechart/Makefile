# ex:ts=8
# Ports collection makefile for:	jfreechart
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jfreechart
PORTVERSION=	0.9.16
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free Java class library for generating charts

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

PLIST_FILES=	share/java/classes/jfreechart.jar
USE_JAVA=	1.2+

ANT?=		${LOCALBASE}/bin/ant

ANT_TARGETS=	compile
.if !defined(NOPORTDOCS)
ANT_TARGETS+=	javadoc
PORTDOCS=	*
.endif

do-build:
	@cd ${WRKSRC}/ant && ${ANT} ${ANT_TARGETS}

do-install:
	@${ECHO_CMD} -n  ">> Installing .jar file..."
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_CMD} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/javadoc && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_CMD} " [DONE]"
.endif

.include <bsd.port.mk>
