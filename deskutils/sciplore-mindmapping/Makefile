# ports collection Makefile for: sciplore-mindmapping
# Whom:			Matthias Andree <mandree@FreeBSD.org>
# Date created:		2010-08-30
#
# $FreeBSD$
#

PORTNAME=	sciplore-mindmapping
PORTVERSION=	0.b013
PORTREVISION=	1
CATEGORIES=	deskutils java
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	splmm/beta13
DISTNAME=	SciPlore_MindMapping_AllOS_v013b
# we use the binary distribution - it's 25% smaller than the source .zip
# and does not depend on devel/apache-ant

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Mind Mapping tool with Reference and PDF Management

LICENSE=	GPLv2

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VENDOR=	freebsd
JAVA_VERSION=	1.6
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

WRKSRC=		${WRKDIR}

post-patch:
		${REINPLACE_CMD} -e 's/readlink -mn/readlink -n/' \
		    -e 's,/etc/freemind,${DATADIR},' \
		    ${WRKSRC}/SciploreMindMapping.sh

do-install:
		@${RM} -f ${WRKSRC}/SciploreMindMapping.bat \
			${WRKSRC}/SciploreMindMapping.exe \
			${WRKSRC}/macOS_and_linux_users--please_read.txt \
			${WRKSRC}/*.bak
# We can't install into $DOCSDIR or support NOPORTDOCS
# since the documentation is an integral part of the
# installation, as online help via the program menus.
		${MKDIR} ${DATADIR}
		(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR})
		${PRINTF} '#!/bin/sh\nexport JAVA_HOME=%s\nexec %s\n' \
		    '${JAVA_HOME}' '${DATADIR}/SciploreMindMapping.sh' \
		    >${PREFIX}/bin/${PORTNAME}
		${CHMOD} a=rx ${DATADIR}/SciploreMindMapping.sh \
		    ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
