# New ports collection makefile for:	py-gdchart
# Date created:		18 June 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$

PORTNAME=	gdchart
PORTVERSION=	0.6.1
PORTREVISION=	6
CATEGORIES=	graphics python
MASTER_SITES=	http://www.nullcube.com/software/pygdchart/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygdchart-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to GDChart

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	gdc.1:${PORTSDIR}/graphics/gdchart

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}gdchart-2.*

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
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLE_DIR}
.for file in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLE_DIR}
.endfor
.endif

.include <bsd.port.mk>
