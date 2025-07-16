PORTNAME=	docear
DISTVERSION=	1.2.0
PORTREVISION=	1
_suffix=	_stable
CATEGORIES=	deskutils education java
MASTER_SITES=	http://docear.org/downloads/${DISTVERSION}${_suffix}/ \
		SF/docear/1.x/${DISTVERSION}${_suffix}
DISTNAME=	docear_linux
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}${_suffix}

MAINTAINER=	seafork@disroot.org
COMMENT=	Academic literature suite
WWW=		https://www.docear.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		desktop-file-utils java shared-mime-info

EXTRACT_AFTER_ARGS=	--exclude *.exe \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes
JDATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	${PORTNAME}.desktop \
		${PORTNAME}.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		JDATADIR=${JDATADIR} \
		PORTNAME=${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}.0${_suffix}_build291
PLIST_SUB=	JDATADIR=${JDATADIR}

do-install:
# We can't install into $DOCSDIR or support disabling a DOCS option
# since the documentation is an integral part of the installation,
# such as online help via the program menus.
	${MKDIR} ${STAGEDIR}${JDATADIR} \
		 ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps \
		 ${STAGEDIR}${PREFIX}/share/mime/packages
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${JDATADIR} \
		"! ( -name ${PORTNAME}.sh -o -name ${PORTNAME}.sh.orig ) ")
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh ${STAGEDIR}${JDATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages

.include <bsd.port.mk>
