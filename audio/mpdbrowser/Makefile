# Created by: Henrik Friedrichsen <hrkfdn@gmail.com>
# $FreeBSD$

PORTNAME=	mpdbrowser
PORTVERSION=	0.9.20
PORTREVISION=	3
CATEGORIES=	audio python
MASTER_SITES=	http://mpdbrowser.tuxfamily.org/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mpdBrowser-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ client for the Music Player Daemon (MPD)

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpd>=0.2.0:audio/py-mpd@${FLAVOR}

USES=		gettext iconv python:2 tar:tgz
USE_GNOME=	intltool pygtk2
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	mpdBrowser

OPTIONS_DEFINE=		MPD
OPTIONS_DEFAULT=	MPD

MPD_DESC=		Install Music Player Daemon
MPD_RUN_DEPENDS=	musicpd:audio/musicpd

.include <bsd.port.mk>
