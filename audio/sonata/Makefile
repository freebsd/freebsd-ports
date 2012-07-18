# New ports collection makefile for:	sonata
# Date created:		2007-01-22
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sonata
PORTVERSION=	1.6.2.1
PORTREVISION=	7
CATEGORIES=	audio python
MASTER_SITES=	http://codingteam.net/project/sonata/upload/releases/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	An elegant music player for MPD

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpd>=0.2.0:${PORTSDIR}/audio/py-mpd

USE_GETTEXT=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_PKGNAME=	Sonata

OPTIONS_DEFINE=	DOCS MANPAGES MMKEYS MPD PYGNOMEEXTRAS TAGLIB ZSI
OPTIONS_DEFAULT=	MPD
MMKEYS_DESC=	Enable instance single support for mmkeys
MPD_DESC=	Install Music Player Daemon
PYGNOMEEXTRAS_DESC=	Use py-gnome-extras for enhanced system tray
TAGLIB_DESC=	Install support for editing metadata
ZSI_DESC=	Install support for automatic lyrics fetching

.include <bsd.port.options.mk>

REINPLACE_ARGS=	-i.bak -e 's,%%DOCSDIR%%,${DOCSDIR},' \
		-e 's,%%PREFIX%%,${PREFIX},'

post-patch:
	@${REINPLACE_CMD} ${WRKSRC}/${PYSETUP} ${WRKSRC}/sonata.py

.if ${PORT_OPTIONS:MMANPAGES}
MAN1=	${PORTNAME}.1
.else
MAKE_ENV=	NO_INSTALL_MANPAGES=${NO_INSTALL_MANPAGES}
.endif

.if !${PORT_OPTIONS:MDOCS}
MAKE_ENV+=	NOPORTDOCS=${NOPORTDOCS}
.endif

.if ${PORT_OPTIONS:MMPD}
RUN_DEPENDS+=	musicpd:${PORTSDIR}/audio/musicpd
.endif

.if ${PORT_OPTIONS:MMMKEYS}
RUN_DEPENDS+=${PYTHON_PKGNAMEPREFIX}dbus>=0.82.4:${PORTSDIR}/devel/py-dbus
.endif

.if ${PORT_OPTIONS:MPYGNOMEEXTRAS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gnome-extras>=2.25.3_4:${PORTSDIR}/x11-toolkits/py-gnome-extras
.endif

.if ${PORT_OPTIONS:MTAGLIB}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tagpy>=0.94.5:${PORTSDIR}/audio/py-tagpy
.endif

.if ${PORT_OPTIONS:MZSI}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}zsi>=2.0,1:${PORTSDIR}/net/py-zsi
.endif

.include <bsd.port.mk>
