# New ports collection makefile for:	py-gdchart
# Date created:		18 June 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$

PORTNAME=	gdchart
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://www.nullcube.com/software/pygdchart/source/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygdchart-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libgdc.a:${PORTSDIR}/graphics/gdchart

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
EXAMPLE_FILES=	test.html test.py
EXAMPLE_DIR=	${PREFIX}/share/examples/py-gdchart

post-extract:
	${SED} -e 's,%%PORTVERSION%%,${PORTVERSION},g' \
		-e 's,%%GD_INCLUDE%%,${LOCALBASE}/include/gd,g' \
		-e 's,%%GDCHART_INCLUDE%%,${LOCALBASE}/include,g' \
		-e 's,%%LOCALLIB%%,${LOCALBASE}/lib,g' \
		${FILESDIR}/setup.py > ${WRKSRC}/setup.py

post-install:
.if !defined(NO_PORTDOCS)
	${MKDIR} ${EXAMPLE_DIR}
.for file in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLE_DIR}
.endfor
.endif

.include <bsd.port.mk>
