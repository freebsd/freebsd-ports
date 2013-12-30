# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	commons-cli
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_BINARIES}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java library for command line arguments and options

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

JARFILE=	${PORTNAME}-${PORTVERSION}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${DESTJARFILE}
.if !defined(NOPORTDOCS)
PORTDOCS=	*
DOC_FILES=	LICENSE.txt NOTICE.txt RELEASE-NOTES.txt
.endif

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@-${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} apidocs ${DOCSDIR}
.for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
