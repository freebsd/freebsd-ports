# Ports collection makefile for:	tnt
# Date created:				Mar 15, 2003
# Whom:					Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	tnt
PORTVERSION=	1.2.1
CATEGORIES=	devel math
MASTER_SITES=	http://math.nist.gov/tnt/
DISTNAME=	${PORTNAME}_121
.ifndef NOPORTDOCS
DISTFILES=${DISTNAME}${EXTRACT_SUFX} tnt120doc.zip
.endif
DIST_SUBDIR=	tnt
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Template Numerical Toolkit

USE_ZIP=	yes
NO_BUILD=	yes
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

do-install:
	${MKDIR} ${PREFIX}/include/tnt
	${INSTALL_DATA} ${WRKDIR}/*.h	\
		${PREFIX}/include/tnt
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${EXTRACT_CMD} ${DISTDIR}/${DIST_SUBDIR}/tnt120doc \
		-d ${DOCSDIR}
.endif

.include <bsd.port.mk>
