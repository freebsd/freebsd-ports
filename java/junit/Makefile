# New ports collection makefile for:	JUnit
# Date created:		Jun 15 1999
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	junit
PORTVERSION=	3.2
CATEGORIES=	java devel
MASTER_SITES=	http://www.xprogramming.com/ftp/TestingFramework/JUnit/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	okazaki@be.to

RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

JDK_VERSION?=	1.1.8

.if ${JDK_VERSION} == "1.1.8"
RUN_DEPENDS+=	${LOCALBASE}/share/java/classes/jfc-1.1.1/swing.jar:${PORTSDIR}/java/jfc
.endif

FIND?=		/usr/bin/find

USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
JUNIT_SUBDIR=	${PORTNAME}-${PORTVERSION}
JUNIT_DESTDIR=	${PREFIX}/share/java/${JUNIT_SUBDIR}

PLIST_SUB=	JUNIT_SUBDIR=${JUNIT_SUBDIR}
DATADIRS=	doc javadoc junit vaj

do-install:
	${MKDIR} ${PREFIX}/share/java/classes ${JUNIT_DESTDIR}
	cd ${INSTALL_WRKSRC}; \
		${INSTALL_DATA} junit.jar ${PREFIX}/share/java/classes; \
		${INSTALL_DATA} README.html ${JUNIT_DESTDIR}; \
		${INSTALL_DATA} src.zip ${JUNIT_DESTDIR}
.if defined(DATADIRS)
.for DIR in ${DATADIRS}
	cd ${INSTALL_WRKSRC}; \
		${FIND} ${DIR} -type d -exec ${MKDIR} ${JUNIT_DESTDIR}/\{} \; ;\
		${FIND} ${DIR} -type f -exec ${INSTALL_DATA} \{} ${JUNIT_DESTDIR}/\{} \;
.endfor
.endif

.include <bsd.port.mk>
