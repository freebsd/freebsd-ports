# ports collection Makefile for: sciplore-mindmapping
# Whom:			Matthias Andree <mandree@FreeBSD.org>
# Date created:		2010-08-30
#
# $FreeBSD$
#

PORTNAME=	sciplore-mindmapping
PORTVERSION=	0.b011
CATEGORIES=	deskutils java
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	splmm/beta11
DISTNAME=	SciPlore_MindMapping_AllOS_v011b
# we use the binary distribution - it's 25% smaller than the source .zip
# and does not depend on devel/apache-ant

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Mind Mapping tool with Reference and PDF Management

LICENSE=	GPLv2

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

WRKSRC=		${WRKDIR}

post-patch:
		${REINPLACE_CMD} -e 's/readlink -mn/readlink -n/' \
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
		${CHMOD} a=rx ${DATADIR}/SciploreMindMapping.sh
		${LN} -s ${DATADIR}/SciploreMindMapping.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
