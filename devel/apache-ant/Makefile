# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apache-ant
PORTVERSION=	1.8.4
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:bin,} \
		LOCAL/hq:man
DISTFILES=	${ANT_DISTFILE}:bin \
		${MANPAGE_DISTFILE}:man
EXTRACT_ONLY=	${ANT_DISTFILE}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java- and XML-based build tool, conceptually similar to make

LICENSE=	AL2

RUN_DEPENDS=	classpath:${PORTSDIR}/java/javavmwrapper

ANT_DISTFILE=	${PORTNAME}-${PORTVERSION}-bin.tar.bz2
MANPAGE_DISTFILE=	${PORTNAME}-manpage-${MANPAGE_VERSION}.tgz
MANPAGE_VERSION=	20030908
USE_BZIP2=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	YES
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

READMES=	LICENSE README WHATSNEW

.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-${PORTVERSION}-manual.tar.bz2:doc
MASTER_SITES+=	${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/manual/:doc,}
PORTDOCS=	*
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MANPAGE_SUBDIR=	apache-ant-manpage
MANPAGE_WRKSRC=	${WRKSRC}/${MANPAGE_SUBDIR}

MAN1=		ant.1
MAN5=		build.xml.5

SUB_FILES=	ant.sh

NO_STAGE=	yes
post-extract:
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${MANPAGE_DISTFILE}

do-install:
	@${ECHO_MSG} -n ">> Installing scripts..."
	@${MKDIR} ${DATADIR}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/ant.sh ${PREFIX}/bin/ant
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/antRun ${DATADIR}/bin/
	@${ECHO_MSG} " [ DONE ]"

.for d in etc lib
	@${ECHO_MSG} -n ">> Installing data directory '${d}'..."
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR}/
	@${ECHO_MSG} " [ DONE ]"
.endfor

	@${ECHO_MSG} -n ">> Installing manpages..."
	@${INSTALL_MAN} ${MANPAGE_WRKSRC}/ant.1 ${MAN1PREFIX}/man/man1
	@${INSTALL_MAN} ${MANPAGE_WRKSRC}/build.xml.5 ${MAN5PREFIX}/man/man5
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}

	@${ECHO_MSG} -n ">> Installing readme files..."
	@${INSTALL_DATA} ${READMES:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing documentation files..."
	@cd ${WRKSRC} && ${COPYTREE_SHARE} manual ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
