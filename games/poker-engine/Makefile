# Created by: ijliao
# $FreeBSD$

PORTNAME=	poker-engine
PORTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/pokersource/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python library that implements poker rules

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/rsync:net/rsync \
		${PYTHON_SITELIBDIR}/pokereval.py:games/py-poker-eval@${FLAVOR} \
		${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2@${FLAVOR} \
		${PYTHON_SITELIBDIR}/libxslt.py:textproc/py-libxslt@${FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/bin/rsync:net/rsync \
		${PYTHON_SITELIBDIR}/pokereval.py:games/py-poker-eval@${FLAVOR} \
		${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2@${FLAVOR} \
		${PYTHON_SITELIBDIR}/libxslt.py:textproc/py-libxslt@${FLAVOR}

USES=		gettext gmake pathfix pkgconfig python:2
USE_PYTHON=	flavors
GNU_CONFIGURE=	yes

test:
	@cd ${WRKSRC} && ${MAKE_CMD} check

.include <bsd.port.mk>
