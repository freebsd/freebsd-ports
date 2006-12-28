# New ports collection makefile for:	JavaSVN
# Date created:				6 Aug 2005
# Whom:					tux@pinguru.net
#
# $FreeBSD$
#

PORTNAME=	svnkit
PORTVERSION=	1.1.0
CATEGORIES=	devel java
MASTER_SITES=	http://svnkit.com/
DISTNAME=	org.tmatesoft.svn_${PORTVERSION}.standalone

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	The only pure Java Subversion client library in the world

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DATA_FILES=	COPYING GANYMED-LICENSE JAVAHL-LICENSE SEQUENCE-LICENSE \
		changelog.txt logging.properties.disabled svnkitsrc.zip \
		svnkit-cli.jar svnkit-javahl.jar svnkit.jar ganymed.jar \
		README.txt

PLIST_FILES=	bin/javasvn bin/svnkit bin/svnsync \
		${DATA_FILES:S,^,%%DATADIR%%/,}
PLIST_DIRS=	%%DATADIR%%

SUB_FILES=	javasvn.sh svnsync.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	${MKDIR} ${DATADIR}
.for file in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/svnsync.sh ${PREFIX}/bin/svnsync
	${INSTALL_SCRIPT} ${WRKDIR}/javasvn.sh ${PREFIX}/bin/javasvn
	${LN} ${PREFIX}/bin/javasvn ${PREFIX}/bin/svnkit
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc/javadoc && \
		${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/doc/javadoc && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

.include <bsd.port.mk>
