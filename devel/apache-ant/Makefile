# New ports collection makefile for:	jakarta-ant
# Date created:		21 February 2001
# Whom:			znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jakarta-ant
PORTVERSION=	1.5.1
PORTREVISION=	3
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
ANT_VERSION=	${PORTVERSION}

DATADIRS=	lib
.if !defined(NOPORTDOCS)
DATADIRS+=	docs
.endif
WRKSRC=		${WRKDIR}/${PORTNAME}-${ANT_VERSION}

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
	@${MKDIR} ${PORTDESTDIR}/lib
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Installing script..."
	@cd ${INSTALL_WRKSRC}; \
		${INSTALL_SCRIPT} ${WRKSRC}/bin/ant ${PREFIX}/bin;
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
