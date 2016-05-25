# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apache-ant
PORTVERSION=	1.9.4
CATEGORIES=	devel java
MASTER_SITES=	APACHE/ant/binaries/:bin \
		LOCAL/hq:man
DISTFILES=	${ANT_DISTFILE}:bin \
		${MANPAGE_DISTFILE}:man
EXTRACT_ONLY=	${ANT_DISTFILE}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java- and XML-based build tool, conceptually similar to make

LICENSE=	APACHE20

OPTIONS_DEFINE=	DOCS

ANT_DISTFILE=	${PORTNAME}-${PORTVERSION}-bin.tar.bz2
MANPAGE_DISTFILE=	${PORTNAME}-manpage-${MANPAGE_VERSION}.tgz
MANPAGE_VERSION=	20030908
USES=		tar:bzip2
USE_JAVA=	yes

NO_BUILD=	YES
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

READMES=	LICENSE README WHATSNEW

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${PORTNAME}-${PORTVERSION}-manual.tar.bz2:doc
MASTER_SITES+=	APACHE/ant/manual/:doc
PORTDOCS=	*
.endif

MANPAGE_SUBDIR=	apache-ant-manpage
MANPAGE_WRKSRC=	${WRKSRC}/${MANPAGE_SUBDIR}

SUB_FILES=	ant.sh

post-extract:
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${MANPAGE_DISTFILE}

do-install:
	@${ECHO_MSG} -n ">> Installing scripts..."
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/ant.sh ${STAGEDIR}${PREFIX}/bin/ant
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/antRun ${STAGEDIR}${DATADIR}/bin/
	@${ECHO_MSG} " [ DONE ]"

.for d in etc lib
	@${ECHO_MSG} -n ">> Installing data directory '${d}'..."
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR}/
	@${ECHO_MSG} " [ DONE ]"
.endfor

	@${ECHO_MSG} -n ">> Installing manpages..."
	@${INSTALL_MAN} ${MANPAGE_WRKSRC}/ant.1 ${STAGEDIR}${PREFIX}/man/man1
	@${INSTALL_MAN} ${MANPAGE_WRKSRC}/build.xml.5 ${STAGEDIR}${PREFIX}/man/man5
	@${ECHO_MSG} " [ DONE ]"

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

	@${ECHO_MSG} -n ">> Installing readme files..."
	@${INSTALL_DATA} ${READMES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing documentation files..."
	@cd ${WRKSRC} && ${COPYTREE_SHARE} manual ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
