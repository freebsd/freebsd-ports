# New ports collection makefile for:	JavaSVN
# Date created:				6 Aug 2005
# Whom:					tux@pinguru.net
#
# $FreeBSD$
#

PORTNAME=	javasvn
PORTVERSION=	0.9.2
CATEGORIES=	devel java
MASTER_SITES=	http://tmate.org/svn/
DISTNAME=	org.tmatesoft.svn_${PORTVERSION}.standalone

MAINTAINER=	tux@pinguru.net
COMMENT=	The only pure Java Subversion client library in the world

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

NO_BUILD=	yes
USE_ZIP=	yes
USE_REINPLACE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DATA_FILES=	COPYING JAVAHL-LICENSE JSCH-LICENSE SEQUENCE-LICENSE \
		changelog.txt logging.properties.disabled javasvnsrc.zip \
		javasvn-cli.jar javasvn-javahl.jar javasvn.jar jsch.jar

PLIST_FILES=	bin/javasvn ${DATA_FILES:S,^,%%DATADIR%%/,}
PLIST_DIRS=	%%DATADIR%%

SUB_FILES=	javasvn.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	${MKDIR} ${DATADIR}
.for file in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/javasvn.sh ${PREFIX}/bin/javasvn
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc/javadoc && \
		${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/doc/javadoc && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

.include <bsd.port.mk>
