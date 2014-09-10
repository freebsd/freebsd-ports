# Created by: Henrik Friedrichsen <hrkfdn@gmail.com>
# $FreeBSD$

PORTNAME=	mpdbrowser
PORTVERSION=	0.9.20
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://mpdbrowser.tuxfamily.org/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mpdBrowser-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org	
COMMENT=	GTK+ client for the Music Player Daemon (MPD)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpd>=0.2.0:${PORTSDIR}/audio/py-mpd

PYDISTUTILS_PKGNAME=	mpdBrowser
USES=		gettext iconv tar:tgz
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GNOME=	intltool pygtk2

OPTIONS_DEFINE=		MPD
OPTIONS_DEFAULT=	MPD
MPD_DESC=	Install Music Player Daemon

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPD}
RUN_DEPENDS+=	musicpd:${PORTSDIR}/audio/musicpd
.endif

.include <bsd.port.mk>
