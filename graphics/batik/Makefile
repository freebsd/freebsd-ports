# ex:ts=8
# Ports collection makefile for:	batik
# Date created:			Feb 25, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	batik
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	graphics java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	xmlgraphics/${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SVG Toolkit

USE_ZIP=	yes
USE_JAVA=	1.5+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_ANT=	yes
USE_JIKES=	no
ALL_TARGET=	jars all-jar
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
TARGET_DIR=	${WRKSRC}/${PORTNAME}-${PORTVERSION}

# Prevent out of memory error during build
MAKE_ENV+=	"ANT_OPTS=-Xmx512m"

.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif

do-install:
	cd ${TARGET_DIR} \
	  && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

post-install:
	@${FIND} -s ${TARGET_DIR} -type f | \
	  ${SED} -e 's,^${TARGET_DIR},${DATADIR:S,${PREFIX}/,,},' >> ${TMPPLIST}
	@${FIND} -s -d ${TARGET_DIR} -type d | \
	  ${SED} -e 's,^${TARGET_DIR},@dirrm ${DATADIR:S,${PREFIX}/,,},' >> ${TMPPLIST}

.include <bsd.port.mk>
