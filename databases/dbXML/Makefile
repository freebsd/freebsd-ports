# Ports collection makefile for:    dbXML
# Date created:         2001/18/10
# Whom:                 Richard Stockley <rws@procopia.com>
#
# $FreeBSD$
#

PORTNAME=	dbXML
PORTVERSION=	1.0b2
PORTREVISION=	3
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME:L}-core/OldFiles
DISTNAME=	dbXML-Core-${PORTVERSION}

MAINTAINER=	rws@procopia.com
COMMENT=	Java Native XML Database

RUN_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/jdk13

JAVA_HOME=	${LOCALBASE}/jdk1.3.1
WRKSRC=		${WRKDIR}/dbXML-Core-${PORTVERSION}
DBXML_HOME=	${PREFIX}/share/java/${PORTNAME}
PLIST_SUB+=	T=${DBXML_HOME:S/^${PREFIX}\///}

NO_BUILD=	yes

post-patch:
	@${RM} ${WRKSRC}/config/system.xml.orig

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${DBXML_HOME}
	@cd ${WRKSRC}; \
	${CP} -R config docs idl java xml icons logs ${DBXML_HOME}; \
	${CP} LICENSE ${DBXML_HOME}; \
	${CP} README ${DBXML_HOME}
	@${CAT} ${WRKSRC}/bin/dbxmladmin \
	| ${SED} "s|%%PREFIX%%|${PREFIX}|g" > ${WRKDIR}/dbxmladmin
	${INSTALL_SCRIPT} -m 755 ${WRKDIR}/dbxmladmin ${PREFIX}/bin
	@${CAT} ${WRKSRC}/bin/dbxml \
	| ${SED} "s|%%PREFIX%%|${PREFIX}|g" > ${WRKDIR}/dbxml
	${INSTALL_SCRIPT} -m 755 ${WRKDIR}/dbxml ${PREFIX}/bin
	@${CAT} ${FILESDIR}/00dbxml.sh \
	| ${SED} "s|%%PREFIX%%|${PREFIX}|g" \
	| ${SED} "s|%%JAVA_HOME%%|${JAVA_HOME}|g" > ${WRKDIR}/00dbxml.sh
	${INSTALL_SCRIPT} ${WRKDIR}/00dbxml.sh ${PREFIX}/etc/rc.d
	@${CAT} ${FILESDIR}/dbxmlctl \
	| ${SED} "s|%%JAVA_HOME%%|${JAVA_HOME}|g" \
	| ${SED} "s|%%DBXML_HOME%%|${DBXML_HOME}|g" > ${WRKDIR}/dbxmlctl
	${INSTALL_SCRIPT} ${WRKDIR}/dbxmlctl ${PREFIX}/bin

	${CHOWN} -R dbxml:dbxml ${DBXML_HOME}
post-install:
	@${ECHO} "etc/rc.d/00dbxml.sh" >> ${TMPPLIST}

.include <bsd.port.mk>
