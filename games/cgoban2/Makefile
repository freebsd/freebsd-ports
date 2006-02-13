# New ports collection makefile for:   cgoban2
# Date created:		30 October 2003
# Whom:			smazanek@steffen-mazanek.de
#
# $FreeBSD$
#

PORTNAME=	cgoban2
PORTVERSION=	2.6.12
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	http://kgs.kiseido.com/
DISTNAME=	cgoban-unix-${PORTVERSION}

MAINTAINER=	phil@brassy.net
COMMENT=	Internet Go Server client and game editor

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/cgoban

USE_X_PREFIX=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

PLIST_FILES=	bin/cgoban2 %%DATADIR%%/cgoban.jar share/pixmaps/cgoban2.png
PLIST_DIRS=	%%DATADIR%%

ICON=		org/igoweb/go/swing/images/tool1.png

DESKTOP_ENTRIES="CGoban 2" \
		"Play Go" \
		"cgoban2.png" \
		"cgoban2" \
		"Application;Game;" \
		false

post-extract:
	@${UNZIP_CMD} -qo ${WRKSRC}/cgoban.jar ${ICON} -d ${WRKSRC}

post-patch:
	${SED} -e 's|_DIR=.|_DIR=${DATADIR}| ; s|^java|JAVA_VERSION="${JAVA_VERSION}" exec "${LOCALBASE}/bin/java"|'\
		< ${WRKSRC}/cgoban.sh.in > ${WRKSRC}/cgoban2

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cgoban.jar ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban2 ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/${ICON} ${PREFIX}/share/pixmaps/cgoban2.png

.include <bsd.port.mk>
