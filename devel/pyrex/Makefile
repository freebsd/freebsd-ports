# New ports collection makefile for:	pyrex
# Date created:		11 April 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	pyrex
PORTVERSION=	0.5
CATEGORIES=	devel lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python/Pyrex/
PKGNAMEPREFIX=	${PYTHONPKGNAMEPREFIX}
DISTNAME=	Pyrex-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Plex/__init__.py:${PORTSDIR}/devel/py-plex
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Plex/__init__.py:${PORTSDIR}/devel/py-plex

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^PYINCLUDE =.*|PYINCLUDE=${PYTHON_INCLUDEDIR}|g' \
		-e 's|\.\./py|${PREFIX}/bin/py|g' ${WRKSRC}/Demos/Makefile
	@${REINPLACE_CMD} -e "s|'Plex'||g" ${WRKSRC}/setup.py
	@${RM} -f ${WRKSRC}/Demos/Makefile.bak

post-install:
	@# precompile lexicon pickle
	@cd ${WRKSRC}/Demos && ${PYTHON_CMD} ${PREFIX}/bin/pyrexc primes.pyx

.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/Demos && ${MAKE} clean

	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/Doc && ${INSTALL_DATA} ./* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/Demos && ${INSTALL_DATA} ./* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
