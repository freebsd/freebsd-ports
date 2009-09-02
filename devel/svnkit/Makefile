# New ports collection makefile for:	JavaSVN
# Date created:				6 Aug 2005
# Whom:					tux@pinguru.net
#
# $FreeBSD$
#

PORTNAME=	svnkit
PORTVERSION=	1.3.0
CATEGORIES=	devel java
MASTER_SITES=	http://svnkit.com/
DISTNAME=	org.tmatesoft.svn_${PORTVERSION}.standalone

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	The only pure Java Subversion client library in the world

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.5847

DATA_FILES=	COPYING \
		JNA-LICENSE JAVAHL-LICENSE SEQUENCE-LICENSE TRILEAD-LICENSE \
		changelog.txt logging.properties.disabled \
		svnkitclisrc.zip svnkitsrc.zip \
		jna.jar svnkit-cli.jar svnkit-javahl.jar svnkit.jar trilead.jar \
		README.txt

PLIST_FILES=	bin/jsvn bin/jsvnadmin bin/jsvnlook \
		bin/jsvnsync bin/jsvnversion \
		bin/jsvndumpfilter \
		${DATA_FILES:S,^,%%DATADIR%%/,}
PLIST_DIRS=	%%DATADIR%%

SUB_FILES=	javasvn.sh svnsync.sh jsvnadmin.sh jsvnlook.sh jsvnversion.sh jsvndumpfilter.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	${MKDIR} ${DATADIR}
.for file in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/javasvn.sh ${PREFIX}/bin/jsvn
	${INSTALL_SCRIPT} ${WRKDIR}/svnsync.sh ${PREFIX}/bin/jsvnsync
	${INSTALL_SCRIPT} ${WRKDIR}/jsvnadmin.sh ${PREFIX}/bin/jsvnadmin
	${INSTALL_SCRIPT} ${WRKDIR}/jsvnlook.sh ${PREFIX}/bin/jsvnlook
	${INSTALL_SCRIPT} ${WRKDIR}/jsvnversion.sh ${PREFIX}/bin/jsvnversion
	${INSTALL_SCRIPT} ${WRKDIR}/jsvndumpfilter.sh ${PREFIX}/bin/jsvndumpfilter

.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc/javadoc && \
		${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/doc/javadoc && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

.include <bsd.port.mk>
