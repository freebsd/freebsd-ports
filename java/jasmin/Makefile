# New ports collection makefile for:	jasmin
# Date created:			May 26, 2004
# Whom:				Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jasmin
PORTVERSION=	1.06
CATEGORIES=	java
MASTER_SITES=	http://www.cat.nyu.edu/~meyer/jasmin/

MAINTAINER=	plexus@snafu.de
COMMENT=	Java Assembler Interface

USE_JAVA=	1.1+
NEED_JAVAC=	yes

WRKSRC=		${WRKDIR}/jasmin

post-extract:
	@${MKDIR} ${WRKSRC}/FreeBSD
	@${ECHO_CMD} Main-Class: jasmin.Main >${WRKSRC}/FreeBSD/manifest

do-build:
	cd ${WRKSRC}/lib/cup && ${JAVAC} -d ${WRKSRC}/FreeBSD java_cup/*.java java_cup/runtime/*.java
	cd ${WRKSRC}/lib/jas/src && ${JAVAC} -d ${WRKSRC}/FreeBSD jas/*.java
	cd ${WRKSRC}/FreeBSD && ${JAVA} java_cup.Main < ${WRKSRC}/src/jasmin/parser.cup
	@${RM} ${WRKSRC}/src/jasmin/parser.java
	@${RM} ${WRKSRC}/src/jasmin/sym.java
	@${MV} ${WRKSRC}/FreeBSD/sym.java ${WRKSRC}/FreeBSD/parser.java ${WRKSRC}/src/jasmin
	cd ${WRKSRC}/FreeBSD && ${JAVAC} -d ../FreeBSD ../src/jasmin/*.java
	cd ${WRKSRC}/FreeBSD && ${JAR} -cmf manifest jasmin.jar jas jasmin java_cup

do-install:
	${INSTALL_DATA} ${WRKSRC}/FreeBSD/jasmin.jar ${PREFIX}/share/java
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples ; \
	  ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; ;\
	  ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	cd ${WRKSRC}/doc ; \
	  ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; ;\
	  ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

post-install:
	${ENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
