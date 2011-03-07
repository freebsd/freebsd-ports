# ports collection Makefile for: sciplore-mindmapping
# Whom:			Matthias Andree <mandree@FreeBSD.org>
# Date created:		2010-08-30
#
# $FreeBSD$
#

PORTNAME=	sciplore-mindmapping
PORTVERSION=	0.b014
CATEGORIES=	deskutils java
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	splmm/beta14
DISTNAME=	SciPlore_MindMapping_AllOS_v014b
# we use the binary distribution - it's 25% smaller than the source .zip
# and does not depend on devel/apache-ant

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Mind Mapping tool with Reference and PDF Management

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

LICENSE=	GPLv2

USE_ZIP=	yes
USE_JAVA=	yes
USE_GNOME=	desktopfileutils
JAVA_VENDOR=	freebsd openjdk
# JAVA_VENDOR comments:
# - blackdown UNSUITABLE (no 1.6 version)
# - bsdjava UNSUITABLE
#   (java.lang.NoClassDefFoundError: javax/xml/bind/JAXB)
# - sun OK BUT SLOW
JAVA_VERSION=	1.6
NO_BUILD=	yes
JDATADIR=	${JAVASHAREDIR}/${PORTNAME}
icon=		${DATADIR}/${PORTNAME}-icon48x48.png

WRKSRC=		${WRKDIR}
SUB_FILES=	sciplore-mindmapping.desktop

post-patch:
		${REINPLACE_CMD} -e 's/readlink -mn/readlink -n/g' \
		    -e 's,/etc/freemind,${JDATADIR},g' \
		    -e 's,/\.freemind,/.SciPloreMindMapping,g' \
		    ${WRKSRC}/SciploreMindMapping.sh

do-install:
		@${RM} -f ${WRKSRC}/SciploreMindMapping.bat \
			${WRKSRC}/SciploreMindMapping.exe \
			${WRKSRC}/macOS_and_linux_users--please_read.txt \
			${WRKSRC}/*.bak
# We can't install into $DOCSDIR or support NOPORTDOCS
# since the documentation is an integral part of the
# installation, as online help via the program menus.
		${MKDIR} ${JDATADIR}
		(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${JDATADIR})
		${PRINTF} '#!/bin/sh\nexport JAVA_HOME="%s"\nexec "%s" "$$@"\n' \
		    '${JAVA_HOME}' '${JDATADIR}/SciploreMindMapping.sh' \
		    >${PREFIX}/bin/${PORTNAME}
		${CHMOD} a=rx ${JDATADIR}/SciploreMindMapping.sh \
		    ${PREFIX}/bin/${PORTNAME}
		${MKDIR} ${DATADIR}
		${INSTALL_DATA} ${FILESDIR}/splmm48.png "${icon}"
		${MKDIR} ${DESKTOPDIR}
		${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${DESKTOPDIR}
		${MKDIR} ${PREFIX}/share/mime/packages
		${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xml ${PREFIX}/share/mime/packages/

post-install:
	        @-update-desktop-database > /dev/null
	        @-update-mime-database ${PREFIX}/share/mime > /dev/null

.include <bsd.port.mk>
