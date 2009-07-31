# New ports collection makefile for:	py-mpdbrowser
# Date created:	2008-12-26
# Whom:		Henrik Friedrichsen <hrkfdn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mpdbrowser
PORTVERSION=	0.9.15
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://mpdbrowser.tuxfamily.org/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mpdBrowser-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hrkfdn@gmail.com
COMMENT=	GTK+ client for the Music Player Daemon (MPD)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpd>=0.2.0:${PORTSDIR}/audio/py-mpd

PYDISTUTILS_PKGNAME=	mpdBrowser
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GNOME=	intltool pygtk2

OPTIONS=		MPD	"Install Music Player Daemon" on

.include <bsd.port.pre.mk>

.if defined (WITH_MPD)
RUN_DEPENDS+=	mpd:${PORTSDIR}/audio/musicpd
.endif

.include <bsd.port.post.mk>
