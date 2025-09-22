PORTNAME=	apache-ant
DISTVERSION=	1.10.15
CATEGORIES=	devel java
MASTER_SITES=	APACHE/ant/binaries:bin \
		https://deb.debian.org/debian/pool/main/a/ant/:man
DISTFILES=	${ANT_DISTFILE}:bin \
		${MANPAGE_DISTFILE}:man
EXTRACT_ONLY=	${ANT_DISTFILE}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java- and XML-based build tool, conceptually similar to make
WWW=		https://ant.apache.org/

LICENSE=	APACHE20

USES=		cpe java tar:bzip2
CPE_VENDOR=	apache
CPE_PRODUCT=	ant

ANT_DISTFILE=	${PORTNAME}-${DISTVERSION}-bin.tar.bz2
MANPAGE_DISTFILE=	ant_${DISTVERSION}-${MANPAGE_VERSION}.debian.tar.xz
MANPAGE_VERSION=	1

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes

READMES=	LICENSE README WHATSNEW

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${PORTNAME}-${DISTVERSION}-manual.tar.bz2:doc
MASTER_SITES+=	APACHE/ant/manual:doc
PORTDOCS=	*
.endif

SUB_FILES=	ant.sh

post-extract:
	@${TAR} -C ${WRKSRC} -xJf ${DISTDIR}/${MANPAGE_DISTFILE} debian/ant.1 debian/build.xml.5

do-install:
	@${ECHO_MSG} -n ">> Installing scripts..."
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/ant.sh ${STAGEDIR}${PREFIX}/bin/ant
	${INSTALL_SCRIPT} ${WRKSRC}/bin/antRun ${STAGEDIR}${DATADIR}/bin/
	@${ECHO_MSG} " [ DONE ]"

.for d in etc lib
	@${ECHO_MSG} -n ">> Installing data directory '${d}'..."
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR}/
	@${ECHO_MSG} " [ DONE ]"
.endfor

	@${ECHO_MSG} -n ">> Installing manpages..."
	${INSTALL_MAN} ${WRKSRC}/debian/ant.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/debian/build.xml.5 ${STAGEDIR}${PREFIX}/share/man/man5
	@${ECHO_MSG} " [ DONE ]"

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}

	@${ECHO_MSG} -n ">> Installing readme files..."
	${INSTALL_DATA} ${READMES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing documentation files..."
	cd ${WRKSRC} && ${COPYTREE_SHARE} manual ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
