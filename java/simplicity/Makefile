# New ports collection makefile for:    Simplicity for Java
# Date created:				13 November 2002
# Whom:					Scott Lambert <lambert@lambertfam.org>
#
# $FreeBSD$
#

PORTNAME=	simplicity
PORTVERSION=	1.2.6b
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	# http://www.datarepresentations.com/products/simplicity/
DISTNAME=	simpjava

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extremely powerful and extremely simple RAD IDE for Java

BUILD_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/jdk13
RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/jdk13

JDK13DIR?=	${LOCALBASE}/jdk1.3.1
JAVAVM=		${JDK13DIR}/bin/java

RESTRICTED=	"Restrictive license"
USE_XLIB=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Simplicity
.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	You must manually fetch the source distribution (${DISTFILES}) from http://www.datarepresentations.com/products/simplicity/download.shtml (registration required), place it in ${DISTDIR} and then run make again
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%%PREFIX%%%,${PREFIX}\/share\/java," -e "s,%%%JAVAVM%%%,${JAVAVM}," ${WRKSRC}/Simplicity

do-install:
	@${CP} -r ${WRKDIR}/Simplicity ${PREFIX}/share/java
	@${INSTALL_SCRIPT} ${WRKDIR}/Simplicity/Simplicity ${PREFIX}/bin/Simplicity

post-install:
.if (NON-PURE_JAVA_OK)
		#@install the NotPureJava/datarep_common.jar in place of datarep_common.jar
		#@{CP} ${PREFIX}/share/java/Simplicity/datrep_common.jar ${PREFIX}/share/java/Simplicity/datarep_common.jar.purejava.backup
		#@{CP} ${PREFIX}/share/java/Simplicity/NotPureJava/datrep_common.jar ${PREFIX}/share/java/Simplicity/datarep_common.jar
.endif

.include <bsd.port.post.mk>
