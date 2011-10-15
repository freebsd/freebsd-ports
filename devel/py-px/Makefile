# New ports collection makefile for:	py-px
# Date created:		19 July 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	px
PORTVERSION=	0.9.5
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perforce p4 wrapper and Python Perforce interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PROJECTHOST=	python-p4lib
USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	BUGS.txt README.txt TODO.txt
PLIST_FILES=	bin/px \
		%%PYTHON_SITELIBDIR%%/p4lib.py \
		%%PYTHON_SITELIBDIR%%/p4lib.pyc \
		%%PYTHON_SITELIBDIR%%/p4lib.pyo

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
