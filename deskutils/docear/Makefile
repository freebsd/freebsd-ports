# ports collection Makefile for: docear
# Whom:			Matthias Andree <mandree@FreeBSD.org>
# Date created:		2012-02-17
#
# $FreeBSD$
#

PORTNAME=	docear
PORTVERSION=	1.0.0.b04
CATEGORIES=	deskutils java
MASTER_SITES=	SF/docear/1.x/${PORTVERSION:S/.b/_beta/}
DISTNAME=	docear_linux

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Mind Mapping tool with Reference, Library, and PDF Management

LICENSE=	GPLv2

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_JAVA=	yes
USE_GNOME=	desktopfileutils
JAVA_VENDOR=	freebsd openjdk bsdjava
JAVA_VERSION=	1.6
NO_BUILD=	yes
JDATADIR=	${JAVASHAREDIR}/${PORTNAME}
icon=		${DATADIR}/${PORTNAME}-icon48x48.png

WRKSRC=		${WRKDIR}/docear-1.0.0.4_beta_build90
SUB_FILES=	docear.desktop

post-patch:
		${REINPLACE_CMD} -e 's/readlink -mn/readlink -n/g' \
		    -e 's,#!/bin/bash,#!/bin/sh,' \
		    ${WRKSRC}/docear.sh

do-install:
		@${RM} -f ${WRKSRC}/docear.bat \
			${WRKSRC}/docear.exe \
			${WRKSRC}/*.bak
# We can't install into $DOCSDIR or support NOPORTDOCS
# since the documentation is an integral part of the
# installation, as online help via the program menus.
		${MKDIR} ${JDATADIR}
		(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${JDATADIR})
		${PRINTF} '#!/bin/sh\nset -eu\nexport JAVA_HOME="%s"\ncd "%s"\nexec "%s" "$$@"\n' \
		    '${JAVA_HOME}' '${JDATADIR}' '${JDATADIR}/docear.sh' \
		    >${PREFIX}/bin/${PORTNAME}
		${CHMOD} a=rx ${JDATADIR}/docear.sh \
		    ${PREFIX}/bin/${PORTNAME}
		${MKDIR} ${DATADIR}
		${INSTALL_DATA} ${FILESDIR}/docear48.png "${icon}"
		${MKDIR} ${DESKTOPDIR}
		${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${DESKTOPDIR}
		${MKDIR} ${PREFIX}/share/mime/packages
		${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xml ${PREFIX}/share/mime/packages/

post-install:
	        -update-desktop-database > /dev/null
	        -update-mime-database ${PREFIX}/share/mime > /dev/null

.include <bsd.port.mk>
