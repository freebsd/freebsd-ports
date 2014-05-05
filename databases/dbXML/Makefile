# Created by: Richard Stockley <rws@procopia.com>
# $FreeBSD$

PORTNAME=	dbXML
PORTVERSION=	2.0
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME:tl}-core/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/
DISTNAME=	dbXML-${PORTVERSION}

MAINTAINER=	rws@procopia.com
COMMENT=	Java Native XML Database

USE_JAVA=	1.5+
DBXML_HOME=	${JAVASHAREDIR}/${PORTNAME}
PLIST_SUB+=	T=${DBXML_HOME:S/^${PREFIX}\///}

NO_BUILD=	yes

SUB_FILES+=	pkg-message \
		dbxmlctl
SUB_LIST+=	DBXML_HOME=${DBXML_HOME} \
		USER=${USERS} \
		PORTNAME=${PORTNAME:tl}
USE_RC_SUBR=	${PORTNAME:tl}

USERS=		${PORTNAME:tl}
GROUPS=		${PORTNAME:tl}
SHAREMODE=	0644

NO_STAGE=	yes
post-patch:
.for f in bin/dbxml bin/dbxml-gui install/create-db startup
	@${REINPLACE_CMD} -e "s:%%DBXML_HOME%%:${DBXML_HOME}:" \
		-e "s:%%LOCALBASE%%:${LOCALBASE}:" "${WRKSRC}/${f}"
.endfor

do-install:
	@${MKDIR} ${DBXML_HOME}
.for d in cocoa config db docs install java jsp logs schemas stylesheets
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DBXML_HOME})
.endfor
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DBXML_HOME}
	@${INSTALL_DATA} ${WRKSRC}/README ${DBXML_HOME}
	@${INSTALL_SCRIPT} ${WRKSRC}/startup ${DBXML_HOME}
	@${CHOWN} -R ${USERS}:${GROUPS} ${DBXML_HOME}
.for f in dbxml dbxml-gui
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin/
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/dbxmlctl ${PREFIX}/bin/
.for f in install/create-db startup
	@${CHMOD} 0755 ${DBXML_HOME}/${f}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
