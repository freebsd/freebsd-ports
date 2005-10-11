# New ports collection makefile for:	apache-ant
# Date created:		21 February 2001
# Whom:			znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	apache-ant
PORTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:bin,} \
		${MASTER_SITE_LOCAL:S,%SUBDIR%/,hq/:man,} \
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

SUB_FILES=	ant.sh
SUB_LIST=	ANT_HOME=${PORTDESTDIR}

post-extract:
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${MANPAGE_DISTFILE}

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${PORTDESTDIR}/bin
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing scripts..."
	@${INSTALL_SCRIPT} ${WRKDIR}/ant.sh ${PREFIX}/bin/ant
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/antRun ${PORTDESTDIR}/bin/
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing readme files..."
	@${INSTALL_DATA} ${READMES:S|^|${WRKSRC}/|} ${PORTDESTDIR}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing manpages..."
	@${INSTALL_MAN} ${MANPAGE_WRKSRC}/ant.1 ${MAN1PREFIX}/man/man1
	@${INSTALL_MAN} ${MANPAGE_WRKSRC}/build.xml.5 ${MAN5PREFIX}/man/man5
	@${ECHO_MSG} " [ DONE ]"

.if defined(DATADIRS)
.for DIR in ${DATADIRS}
	@${ECHO_MSG} -n ">> Installing data directory '${DIR}'..."
	@cd ${INSTALL_WRKSRC}; \
		${FIND} ${DIR} -type d -exec ${MKDIR} ${PORTDESTDIR}/\{} \; ;\
		${FIND} ${DIR} -type f -exec ${INSTALL_DATA} \{} ${PORTDESTDIR}/\{} \;
	@${ECHO_MSG} " [ DONE ]"
.endfor
.endif

.include <bsd.port.mk>
