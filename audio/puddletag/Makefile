# $FreeBSD$

PORTNAME=	puddletag
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Audio tag editor

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/fpcalc:${PORTSDIR}/audio/chromaprint \
		${LOCALBASE}/bin/mb-submit-disc:${PORTSDIR}/audio/py-musicbrainz2 \
		${LOCALBASE}/bin/moggsplit:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_SITELIBDIR}/configobj.py:${PORTSDIR}/devel/py-configobj \
		${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=yes
INSTALLS_ICONS=	yes
NO_BUILD=	yes

MAN1=		puddletag.1

.include <bsd.port.mk>
