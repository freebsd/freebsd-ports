# New ports collection makefile for:    jext
# Date created:		17 Febrary 2000
# Whom:			Maxim Sobolev <sobomax@altavista.net>
#
# $FreeBSD$
#

PORTNAME=	jext
PORTVERSION=	2.8.0.2
CATEGORIES=	editors java
MASTER_SITES=	http://members.xoom.com/romainguy/
DISTFILES=	${PORTNAME}${EXTRACT_SUFX} swingall.jar

MAINTAINER=	sobomax@altavista.net

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/jdk

FETCH_BEFORE_ARGS=	-b

EXTRACT_ONLY=	${PORTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}
USE_ZIP=	yes
USE_XLIB=	yes
NO_BUILD=	yes

JDK_VERSION=	1.1.8
JAVAVM=		${LOCALBASE}/jdk${JDK_VERSION}/bin/java

.if defined(USE_JIT)
RUN_DEPENDS+=	${LOCALBASE}/jdk${JDK_VERSION}/lib/${ARCH}/green_threads/libshujit.so:${PORTSDIR}/java/shujit
JAVAJIT=	shujit
.else
JAVAJIT=
.endif

INSTSBDR=	${PREFIX}/share/java/jext
DATATARG=	jext.jar icons plugins scripts xtools

post-extract:
		@${PERL} -pi -e "s.\x0D.." ${WRKSRC}/jext

do-configure:
		@${PERL} -pi -e "s|%JAVAVM%|${JAVAVM}|g" ${WRKSRC}/jext
		@${PERL} -pi -e "s|%JEXT_HOME%|${INSTSBDR}|g" ${WRKSRC}/jext
		@${PERL} -pi -e "s|%JAVAJIT%|${JAVAJIT}|g" ${WRKSRC}/jext
		@${PERL} -pi -e "s|%JFC%|${INSTSBDR}/swingall.jar|g" ${WRKSRC}/jext

do-install:
		@${MKDIR} ${INSTSBDR}
		@${INSTALL_SCRIPT} ${WRKSRC}/jext ${PREFIX}/bin
		@(cd ${WRKSRC} && ${TAR} -c -f - ${DATATARG}) \
			| (cd ${INSTSBDR} && ${TAR} --unlink -x -f -)
		@${INSTALL_DATA} ${DISTDIR}/swingall.jar ${INSTSBDR}
.if !defined(NOPORTDOCS)
		@${MKDIR} ${PREFIX}/share/doc/java/jext
		@(cd ${WRKSRC}/doc && ${TAR} -c -f - * ) \
			| (cd ${PREFIX}/share/doc/java/jext && ${TAR} --unlink -x -f -)
.endif

.include <bsd.port.mk>
