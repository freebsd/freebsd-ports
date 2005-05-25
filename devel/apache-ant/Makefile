# New ports collection makefile for:	apache-ant
# Date created:		21 February 2001
# Whom:			znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	apache-ant
PORTVERSION=	1.6.2
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:bin,} \
		http://www.esil.univ-mrs.fr/~hquiroz/:man
DISTFILES=	${ANT_DISTFILE}:bin \
		${MANPAGE_DISTFILE}:man
EXTRACT_ONLY=	${ANT_DISTFILE}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java- and XML-based build tool, conceptually similar to make

RUN_DEPENDS=	classpath:${PORTSDIR}/java/javavmwrapper

ANT_DISTFILE=	${PORTNAME}-${PORTVERSION}-bin.tar.bz2
MANPAGE_DISTFILE=	${PORTNAME}-manpage-${MANPAGE_VERSION}.tgz
MANPAGE_VERSION=	20030908
USE_BZIP2=	yes
USE_JAVA=	1.2+

NO_BUILD=	YES
PORTDESTDIR=	${PREFIX}/ant

READMES=	LICENSE README WHATSNEW

DATADIRS=	lib etc
.if !defined(NOPORTDOCS)
DATADIRS+=	docs
.endif
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MANPAGE_SUBDIR=	apache-ant-manpage
MANPAGE_WRKSRC=	${WRKSRC}/${MANPAGE_SUBDIR}

MAN1=		ant.1
MAN5=		build.xml.5

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

post-extract:
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${MANPAGE_DISTFILE}

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

	@${ECHO_CMD} -n ">> Installing manpages..."
	@${INSTALL_MAN} ${MANPAGE_WRKSRC}/ant.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${MANPAGE_WRKSRC}/build.xml.5 ${PREFIX}/man/man5
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
