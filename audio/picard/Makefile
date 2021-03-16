# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	picard
PORTVERSION=	2.5.6
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		http://ftp.osuosl.org/pub/musicbrainz/picard/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Next generation MusicBrainz Tagger

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}discid>=0.5.2:audio/py-discid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.37:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.7.3:devel/py-dateutil@${PY_FLAVOR}

USES=		gettext pyqt:5 python:3.5+ desktop-file-utils
USE_LOCALE=	en_US.UTF-8
USE_PYQT=	core_run dbus_run gui_run network_run widgets_run sip
USE_PYTHON=	autoplist distutils noflavors

WRKSRC=		${WRKDIR}/${PORTNAME}-release-${DISTVERSION}

OPTIONS_DEFINE=		ACOUSTID PLAYER PLUGINS
OPTIONS_DEFAULT=	PLAYER PLUGINS

ACOUSTID_RUN_DEPENDS=	fpcalc:audio/chromaprint

PLAYER_DESC=		Built-in audio player
PLAYER_USE=		PYQT=multimedia_run

PLUGINS_DESC=		Install various plugins to extend functionality
PLUGINS_RUN_DEPENDS=	picard-plugins>=2.0:audio/picard-plugins

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/picard/util/_astrcmp*.so

.include <bsd.port.mk>
