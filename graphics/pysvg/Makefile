# New ports collection makefile for:	pysvg
# Date created:				2009-08-26
# Whom:					Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pysvg
PORTVERSION=	0.2.0
CATEGORIES=	graphics python
MASTER_SITES=	http://www.codeboje.de/downloads/
DISTNAME=	${PORTNAME:S|svg|SVG|}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	pySVG - creating svg with python

NO_WRKSUBDIR=	yes

USE_PYTHON=	yes
USE_ZIP=	yes
PYDISTUTILS_BUILDARGS+=	--prefix=${PREFIX}

do-build:
	@cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build

do-install:
	@cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
			install ${PYDISTUTILS_BUILDARGS}

.include <bsd.port.mk>
