# Created by: tux@pinguru.net
# $FreeBSD$

PORTNAME=	svnkit
PORTVERSION=	1.3.0
CATEGORIES=	devel java
MASTER_SITES=	http://svnkit.com/
DISTNAME=	org.tmatesoft.svn_${PORTVERSION}.standalone
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The only pure Java Subversion client library in the world

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
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
PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for file in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/javasvn.sh ${STAGEDIR}${PREFIX}/bin/jsvn
	${INSTALL_SCRIPT} ${WRKDIR}/svnsync.sh ${STAGEDIR}${PREFIX}/bin/jsvnsync
	${INSTALL_SCRIPT} ${WRKDIR}/jsvnadmin.sh ${STAGEDIR}${PREFIX}/bin/jsvnadmin
	${INSTALL_SCRIPT} ${WRKDIR}/jsvnlook.sh ${STAGEDIR}${PREFIX}/bin/jsvnlook
	${INSTALL_SCRIPT} ${WRKDIR}/jsvnversion.sh ${STAGEDIR}${PREFIX}/bin/jsvnversion
	${INSTALL_SCRIPT} ${WRKDIR}/jsvndumpfilter.sh ${STAGEDIR}${PREFIX}/bin/jsvndumpfilter
	cd ${WRKSRC}/doc/javadoc && \
		${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \;
	cd ${WRKSRC}/doc/javadoc && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;

.include <bsd.port.mk>
