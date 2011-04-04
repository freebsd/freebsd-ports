# New ports collection makefile for:	puddletag
# Date created:		2010-10-23
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=		puddletag
PORTVERSION=		0.10.3
CATEGORIES=		audio python
MASTER_SITES=		SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Audio tag editor

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/configobj.py:${PORTSDIR}/devel/py-configobj \
		${LOCALBASE}/bin/mb-submit-disc:${PORTSDIR}/audio/py-musicbrainz2 \
		${LOCALBASE}/bin/moggsplit:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

LICENSE=	GPLv3

USE_QT_VERSION=		4
USE_PYTHON=		2.5+
USE_PYDISTUTILS=	yes
INSTALLS_ICONS=		yes
NO_BUILD=		yes

.include <bsd.port.mk>
