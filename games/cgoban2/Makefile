# New ports collection makefile for:   cgoban2
# Date created:		30 October 2003
# Whom:			smazanek@steffen-mazanek.de
#
# $FreeBSD$
#

PORTNAME=	cgoban2
PORTVERSION=	2.6.12
CATEGORIES=	games java
MASTER_SITES=	http://kgs.kiseido.com/
DISTNAME=	cgoban-unix-${PORTVERSION}

MAINTAINER=	philip.reynolds@rfc-networks.ie
COMMENT=	Internet Go Server client and game editor

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/cgoban
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

PLIST_FILES=	bin/cgoban2 %%DATADIR%%/cgoban.jar
PLIST_DIRS=	%%DATADIR%%

post-patch:
	${SED} -e 's|_DIR=.|_DIR=${DATADIR}| ; s|^java|JAVA_VERSION="${JAVA_VERSION}" "${LOCALBASE}/bin/java"|'\
		< ${WRKSRC}/cgoban.sh.in > ${WRKSRC}/cgoban2

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cgoban.jar ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban2 ${PREFIX}/bin/cgoban2

.include <bsd.port.mk>
