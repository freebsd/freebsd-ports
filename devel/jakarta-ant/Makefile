# New ports collection makefile for:	jakarta-ant
# Date created:		21 February 2001
# Whom:			znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jakarta-ant
PORTVERSION=	1.5.1
CATEGORIES=	devel java
MASTER_SITES=	http://jakarta.apache.org/builds/${PORTNAME}/release/v${ANT_VERSION}/bin/ \
		http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DISTNAME=	${PORTNAME}-${ANT_VERSION}-bin
DIST_SUBDIR=	jakarta

MAINTAINER=	znerd@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/java/classes/crimson.jar:${PORTSDIR}/textproc/crimson

USE_JAVA=	1.2+

NO_BUILD=	YES
PORTDESTDIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}
PLIST_SUB+=	T=${PORTDESTDIR:S/^${PREFIX}\///}

READMES=	LICENSE README WHATSNEW
SCRIPTS=	bin/ant bin/antRun bin/runant.pl
ANT_VERSION=	${PORTVERSION}

DATADIRS=	lib
.if !defined(NOPORTDOCS)
DATADIRS+=	docs
.endif
WRKSRC=		${WRKDIR}/${PORTNAME}-${ANT_VERSION}

post-patch:
	@${ECHO_CMD} -n ">> Customizing ant shell script..."
	@${SED} \
	-e "/%%JAVA%%/s//${JAVA:S/\//\\\//g}/g" \
	-e "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/g" \
	${WRKSRC}/bin/ant > ${WRKDIR}/ant
	@${MV} ${WRKDIR}/ant ${WRKSRC}/bin/ant
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Removing unneeded files..."
	@${RM} -f ${WRKSRC}/lib/parser.jar
	@${ECHO_CMD} " [ DONE ]"

do-install:
	@${ECHO_CMD} -n ">> Creating destination directory..."
	@${MKDIR} ${PORTDESTDIR}/bin ${PORTDESTDIR}/lib
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Installing scripts..."
	@cd ${INSTALL_WRKSRC}; \
		${INSTALL_SCRIPT} ${SCRIPTS} ${PORTDESTDIR}/bin;
	@${LN} -sf ${PORTDESTDIR}/bin/ant ${PREFIX}/bin
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

	@${ECHO_CMD} -n ">> Installing additional JAR files..."
	@${LN} -sf ../../classes/jaxp.jar ${PORTDESTDIR}/lib
	@${LN} -sf ../../classes/crimson.jar ${PORTDESTDIR}/lib
	@${ECHO_CMD} " [ DONE ]"

.include <bsd.port.mk>
