# New ports collection makefile for:	puddletag
# Date created:		2010-10-23
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	puddletag
PORTVERSION=	0.10.6
CATEGORIES=	audio python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Audio tag editor

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/configobj.py:${PORTSDIR}/devel/py-configobj \
		${LOCALBASE}/bin/mb-submit-disc:${PORTSDIR}/audio/py-musicbrainz2 \
		${LOCALBASE}/bin/moggsplit:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
INSTALLS_ICONS=	yes
NO_BUILD=	yes

MAN1=		puddletag.1

.include <bsd.port.mk>
