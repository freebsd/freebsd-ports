# New ports collection makefile for: cut
# Date created:			December 5 2004
# Whom:       		Sergei Gnezdov <sergeiga@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	cut
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	http://www.falvotech.com/downloads/

MAINTAINER=	sgnezdov@sergei.homeunix.org
COMMENT=	Unit Testing Framework for C, C++ and Objective-C

DISTVERSIONSUFFIX=	rc1

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

# related to build target
ALL_TARGET=	bin/cutgen

# cut interface is compatible at major version number
major=		2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cutgen ${PREFIX}/bin/cutgen-${major}
	${CP} -R ${WRKSRC}/include/* ${PREFIX}/include/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/tutorial
	${CP} ${WRKSRC}/LICENSE ${WRKSRC}/docs/README ${WRKSRC}/CHANGELOG ${DOCSDIR}/
	${CP} -R ${WRKSRC}/docs/tutorials/sergei_gnezdov/*.c\
			${WRKSRC}/docs/tutorials/sergei_gnezdov/*.h\
			${WRKSRC}/docs/tutorials/sergei_gnezdov/*.dvi\
			${WRKSRC}/docs/tutorials/sergei_gnezdov/*.pdf\
			${WRKSRC}/docs/tutorials/sergei_gnezdov/*.ps\
			${DOCSDIR}/tutorial/
	${MKDIR} ${EXAMPLESDIR}/
	${CP} -R ${WRKSRC}/test/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
