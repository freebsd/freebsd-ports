# New ports collection makefile for:	apache-ant
# Date created:		21 February 2001
# Whom:			znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	apache-ant
PORTVERSION=	1.5.4
CATEGORIES=	devel java
MASTER_SITES=	http://apache.mirror.trueserver.nl/dist/ant/binaries/ \
		http://apache.proserve.nl/dist/ant/binaries/ \
		http://apache.cs.uu.nl/dist/ant/binaries/ \
		http://dist.apache.easynet.nl/ant/binaries/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java- and XML-based build tool, conceptually similar to make

USE_BZIP2=	yes
USE_JAVA=	1.2+

NO_BUILD=	YES
PORTDESTDIR=	${PREFIX}/ant
PLIST_SUB+=	T=${PORTDESTDIR:S/^${PREFIX}\///}

READMES=	LICENSE README WHATSNEW

DATADIRS=	lib
.if !defined(NOPORTDOCS)
DATADIRS+=	docs
.endif
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-patch:
	@${CP} ${FILESDIR}/ant ${WRKSRC}/bin/ant

post-patch:
	@${ECHO_CMD} -n ">> Customizing ant shell script..."
	@${SED} \
	-e "/%%ANT_HOME%%/s//${PORTDESTDIR:S/\//\\\//g}/g" \
	-e "/%%JAVA%%/s//${JAVA:S/\//\\\//g}/g" \
	-e "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/g" \
	-e "/%%PREFIX%%/s//${PREFIX:S/\//\\\//g}/g" \
	${WRKSRC}/bin/ant > ${WRKDIR}/ant
	@${MV} ${WRKDIR}/ant ${WRKSRC}/bin/ant
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Removing unneeded files..."
	@${RM} -f ${WRKSRC}/lib/parser.jar
	@${ECHO_CMD} " [ DONE ]"

do-install:
	@${ECHO_CMD} -n ">> Creating destination directory..."
	@${MKDIR} ${PORTDESTDIR}/bin
	@${MKDIR} ${PORTDESTDIR}/lib
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Installing scripts..."
	@cd ${INSTALL_WRKSRC}; \
		${INSTALL_SCRIPT} ${WRKSRC}/bin/ant ${PREFIX}/bin; \
		${INSTALL_SCRIPT} ${WRKSRC}/bin/antRun ${PORTDESTDIR}/bin;
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Installing readme files..."
	@cd ${INSTALL_WRKSRC}; \
		${INSTALL_DATA} ${READMES} ${PORTDESTDIR};
	@${ECHO_CMD} " [ DONE ]"

.if defined(DATADIRS)
.for DIR in ${DATADIRS}
	@${ECHO_CMD} -n ">> Installing data directory '${DIR}'..."
	@cd ${INSTALL_WRKSRC}; \
		${FIND} ${DIR} -type d -exec ${MKDIR} ${PORTDESTDIR}/\{} \; ;\
		${FIND} ${DIR} -type f -exec ${INSTALL_DATA} \{} ${PORTDESTDIR}/\{} \;
	@${ECHO_CMD} " [ DONE ]"
.endfor
.endif

.include <bsd.port.mk>
