# New ports collection makefile for:	freemind
# Date created:	22 september 2004
# Whom:		cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#

PORTNAME=	freemind
PORTVERSION=	0.7.1
CATEGORIES=	deskutils editors java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freemind
DISTNAME=	${PORTNAME}-bin-${PORTVERSION:S/./_/g}

MAINTAINER=	cartola@openit.com.br
COMMENT=	Free mind-mapping software written in Java

.if defined(ZIPDEPENDS)
BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif
.if !exists(/usr/bin/zip)
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
.endif

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_REINPLACE=	yes

PLIST_SUB=	VER=${PORTVERSION}

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
ZIP_CMD=	zip

do-build:
	(cd ${WRKSRC}; \
	${UNZIP_CMD} lib/freemind.jar freemind.properties; \
	${REINPLACE_CMD} -e '/^properties_folder/ s/freemind/.&/; s|./doc/freemind.mm|${PREFIX}/${PORTNAME}-${PORTVERSION}/doc/freemind.mm|' freemind.properties; \
	${ZIP_CMD} -u lib/freemind.jar freemind.properties)

do-install:
	${MKDIR} ${PREFIX}/${PORTNAME}-${PORTVERSION}/accessories
	${MKDIR} ${PREFIX}/${PORTNAME}-${PORTVERSION}/doc
	${MKDIR} ${PREFIX}/${PORTNAME}-${PORTVERSION}/lib
	${INSTALL_DATA} ${WRKSRC}/user.properties ${PREFIX}/${PORTNAME}-${PORTVERSION}
	${INSTALL_DATA} ${WRKSRC}/license ${PREFIX}/${PORTNAME}-${PORTVERSION}
	${INSTALL_DATA} ${WRKSRC}/patterns.xml ${PREFIX}/${PORTNAME}-${PORTVERSION}
	${INSTALL_DATA} ${WRKSRC}/accessories/* ${PREFIX}/${PORTNAME}-${PORTVERSION}/accessories
	${INSTALL_DATA} ${WRKSRC}/doc/freemind.mm ${PREFIX}/${PORTNAME}-${PORTVERSION}/doc
	${INSTALL_DATA} ${WRKSRC}/lib/freemind.jar ${PREFIX}/${PORTNAME}-${PORTVERSION}/lib
	@(${ECHO} "#\!/bin/sh"; ${ECHO} "${JAVA_HOME}/bin/java -jar ${PREFIX}/${PORTNAME}-${PORTVERSION}/lib/freemind.jar \$*") > ${WRKDIR}/freemind
	${INSTALL_SCRIPT} ${WRKDIR}/freemind ${PREFIX}/bin

.include <bsd.port.mk>
