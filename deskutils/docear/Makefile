# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docear
PORTVERSION=	1.2.0
_suffix=	_stable
CATEGORIES=	deskutils java
MASTER_SITES=	http://docear.org/downloads/${PORTVERSION}${_suffix}/ \
		SF/docear/1.x/${PORTVERSION}${_suffix} \
		LOCAL/mandree/${DIST_SUBDIR}/
DISTNAME=	docear_linux
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}${_suffix}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Academic literature suite

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		desktop-file-utils shared-mime-info
USE_JAVA=	yes
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.6+
NO_BUILD=	yes
JDATADIR=	${JAVASHAREDIR}/${PORTNAME}
icon=		${DATADIR}/${PORTNAME}-icon48x48.png

WRKSRC=		${WRKDIR}/docear-1.2.0.0_stable_build291
SUB_FILES=	docear.desktop

do-install:
	@${RM} -f ${WRKSRC}/docear.bat ${WRKSRC}/docear.exe ${WRKSRC}/*.bak
# We can't install into $DOCSDIR or support disabling a DOCS option
# since the documentation is an integral part of the installation,
# such as online help via the program menus.
	@${MKDIR} ${STAGEDIR}${JDATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${JDATADIR}
	${PRINTF} '#!/bin/sh\nset -eu\nexport JAVA_HOME="%s"\ncd "%s"\nexec "%s" "$$@"\n' \
		'${JAVA_HOME}' '${JDATADIR}' '${JDATADIR}/docear.sh' \
		> ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${CHMOD} a=rx ${STAGEDIR}${JDATADIR}/docear.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/docear48.png ${STAGEDIR}${icon}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages

.include <bsd.port.mk>
