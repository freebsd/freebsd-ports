# Ports collection makefile for:	tnt
# Date created:				Mar 15, 2003
# Whom:					Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	tnt
PORTVERSION=	1.1.1
CATEGORIES=	devel math
MASTER_SITES=	http://math.nist.gov/tnt/
DISTNAME=	${PORTNAME}111
.ifndef NOPORTDOCS
DISTFILES=${DISTNAME}${EXTRACT_SUFX} tnt110doc.zip
.endif
DIST_SUBDIR=	tnt
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Template Numerical Toolkit

USE_ZIP=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/include/tnt
	${EXTRACT_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		-d ${PREFIX}/include/tnt
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${EXTRACT_CMD} ${DISTDIR}/${DIST_SUBDIR}/tnt110doc \
		-d ${DOCSDIR}
.endif

.include <bsd.port.mk>
