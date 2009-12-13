# New ports collection makefile for: albumart
# Date created:		27 Aug 2008
# Whom:			Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	albumart
PORTVERSION=	1.6.6
CATEGORIES=	audio python
MASTER_SITES=	http://muksuluuri.ath.cx/~skyostil/projects/albumart/dist/

MAINTAINER=	timbob@bigpond.com
COMMENT=	GUI application for downloading album cover art

USE_GMAKE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

RUN_DEPENDS+=	py*-qt>=3.1:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS+=	py*-imaging>=1.1:${PORTSDIR}/graphics/py-imaging

post-patch:
	${CP} ${WRKSRC}/bin/albumart-qt ${WRKSRC}/bin/albumart-qt.orig
	echo "#!${PYTHON_CMD}" > ${WRKSRC}/bin/albumart-qt
	${TAIL} -n +2 ${WRKSRC}/bin/albumart-qt.orig >> ${WRKSRC}/bin/albumart-qt
	${CP} ${WRKSRC}/setup.py ${WRKSRC}/setup.py.orig
	${SED} -e "s/os.system(\"make\")/os.system(\"${GMAKE}\")/" \
	    ${WRKSRC}/setup.py.orig > ${WRKSRC}/setup.py

.include <bsd.port.mk>
