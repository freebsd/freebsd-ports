# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	OpenJUMP
PORTVERSION=	1.6.3
CATEGORIES=	graphics java geography
MASTER_SITES=	SF/jump-pilot/OpenJUMP/${PORTVERSION}
DISTNAME=	${PORTNAME}-Portable-${PORTVERSION}-r${PLUS_REV}-PLUS

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Open source GIS software written in Java

LICENSE=	BSD CLEARTHOUGHT CPL ECW GPLv2 GPLv3 JAIDL JDOM JYTHON LGPL21 LGPL3
LICENSE_COMB=	multi

LICENSE_NAME_CLEARTHOUGHT=	Clearthought Software License
LICENSE_FILE_CLEARTHOUGHT=	${WRKSRC}/licenses/clearthought-2.0.txt
LICENSE_PERMS_CLEARTHOUGHT=	auto-accept

LICENSE_NAME_CPL=	Common Public License v1.0
LICENSE_FILE_CPL=	${WRKSRC}/licenses/cpl-1.0.txt
LICENSE_PERMS_CPL=	auto-accept

LICENSE_NAME_ECW=	EARTH RESOURCE MAPPING
LICENSE_FILE_ECW=	${WRKSRC}/licenses/ecw\ license.txt
LICENSE_PERMS_ECW=	auto-accept

LICENSE_NAME_JAIDL=	Java Advanced Imaging Distribution License
LICENSE_FILE_JAIDL=	${WRKSRC}/licenses/jdl-jai.pdf
LICENSE_PERMS_JAIDL=	auto-accept

LICENSE_NAME_JDOM=	JDOM Project License
LICENSE_FILE_JDOM=	${WRKSRC}/licenses/jdom_license.txt
LICENSE_PERMS_JDOM=	auto-accept

LICENSE_NAME_JYTHON=	The Jython License
LICENSE_FILE_JYTHON=	${WRKSRC}/licenses/jython_license.txt
LICENSE_PERMS_JYTHON=	auto-accept

TARGET_DIR=	${STAGEDIR}${PREFIX}/${PORTNAME}
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-r${PLUS_REV}-PLUS
PLUS_REV=	3576

do-install:
	@${ECHO_CMD} "--->  Installing JAR files"
	${MKDIR} ${TARGET_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${TARGET_DIR}/lib
	${MKDIR} ${TARGET_DIR}/lib/ext
	@cd ${WRKSRC}/lib/ext && ${COPYTREE_SHARE} . ${TARGET_DIR}/lib/ext
	@${ECHO_MSG} "--->  Installing startup script"
	${MKDIR} ${TARGET_DIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/oj_linux.sh ${TARGET_DIR}/bin/openjump
	${LN} -sf ../${PORTNAME}/bin/openjump ${STAGEDIR}${PREFIX}/bin/openjump
	${INSTALL_DATA} ${WRKSRC}/bin/default-plugins.xml ${TARGET_DIR}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/log4j.xml ${TARGET_DIR}/bin/

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "--->  Installing documentation"
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
.else
	@${ECHO_MSG} "--->  Skipping documentation"
.endif

.include <bsd.port.mk>
