# New ports collection makefile for:    jext
# Date created:		17 Febrary 2000
# Whom:			Maxim Sobolev <sobomax@altavista.net>
#
# $FreeBSD$
#

PORTNAME=	jext
PORTVERSION=	2.7.0.6
CATEGORIES=	editors java
MASTER_SITES=	http://members.xoom.com/romainguy/
DISTNAME=	${PORTNAME}

MAINTAINER=	sobomax@altavista.net

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/jdk \
		${JFC}:${PORTSDIR}/java/jfc

FETCH_BEFORE_ARGS=	-b

WRKSRC=		${WRKDIR}
USE_ZIP=	yes
USE_XLIB=	yes
NO_BUILD=	yes

JDK_VERSION=	1.1.8
JFC_VERSION=	1.1.1
JAVAVM=		${LOCALBASE}/jdk${JDK_VERSION}/bin/java
JFC=		${LOCALBASE}/share/java/classes/jfc-${JFC_VERSION}/swing.jar

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

pre-install:
		@${PERL} -pi -e "s|%JAVAVM%|${JAVAVM}|g" ${WRKSRC}/jext
		@${PERL} -pi -e "s|%JEXT_HOME%|${INSTSBDR}|g" ${WRKSRC}/jext
		@${PERL} -pi -e "s|%JAVAJIT%|${JAVAJIT}|g" ${WRKSRC}/jext
		@${PERL} -pi -e "s|%JFC%|${JFC}|g" ${WRKSRC}/jext

do-install:
		@${MKDIR} ${INSTSBDR}
		@${INSTALL_SCRIPT} ${WRKSRC}/jext ${PREFIX}/bin
		@(cd ${WRKSRC} && ${TAR} -c -f - ${DATATARG}) \
			| (cd ${INSTSBDR} && ${TAR} --unlink -x -f -)
.if !defined(NOPORTDOCS)
		@${MKDIR} ${PREFIX}/share/doc/java/jext
		@(cd ${WRKSRC}/doc && ${TAR} -c -f - * ) \
			| (cd ${PREFIX}/share/doc/java/jext && ${TAR} --unlink -x -f -)
.endif

.include <bsd.port.mk>
