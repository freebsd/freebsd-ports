# New ports collection makefile for:	JUnit
# Date created:		Jun 15 1999
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	junit
PORTVERSION=	3.8.1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	okazaki@FreeBSD.org

USE_ZIP=	yes
USE_JAVA=	1.1+
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes

.include <bsd.port.pre.mk>

.if ${USE_JAVA} == "1.1"
RUN_DEPENDS+=	${LOCALBASE}/share/java/classes/jfc-1.1.1/swing.jar:${PORTSDIR}/java/jfc
.endif

.if !defined(NOPORTDOCS)
DATADIRS=	doc javadoc junit
.endif

do-install:
	${MKDIR} ${PREFIX}/share/java/classes ${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/junit.jar ${PREFIX}/share/java/classes
	${INSTALL_DATA} ${INSTALL_WRKSRC}/src.jar ${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/README.html ${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/cpl-v10.html ${DOCSDIR}
.if defined(DATADIRS)
.for DIR in ${DATADIRS}
	cd ${INSTALL_WRKSRC}; \
		${FIND} ${DIR} -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; ;\
		${FIND} ${DIR} -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endfor
.endif

.include <bsd.port.post.mk>
