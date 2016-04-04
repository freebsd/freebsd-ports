# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sonata
PORTVERSION=	1.6.2.1
PORTREVISION=	10
CATEGORIES=	audio python
MASTER_SITES=	http://codingteam.net/project/sonata/upload/releases/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Elegant music player for MPD

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpd>=0.2.0:audio/py-mpd

USES=		gettext pkgconfig python
USE_GNOME=	pygtk2
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS MANPAGES MMKEYS MPD PYGNOMEEXTRAS TAGLIB ZSI
OPTIONS_DEFAULT=	MPD
MMKEYS_DESC=	Enable instance single support for mmkeys
MPD_DESC=	Install Music Player Daemon
PYGNOMEEXTRAS_DESC=	Use py-gnome-extras for enhanced system tray
TAGLIB_DESC=	Install support for editing metadata
ZSI_DESC=	Install support for automatic lyrics fetching
OPTIONS_SUB=	yes

MANPAGES_MAKE_ENV_OFF=	NO_INSTALL_MANPAGES=yes
DOCS_MAKE_ENV=	NOPORTDOCS=${NOPORTDOCS}
MPD_RUN_DEPENDS+=	musicpd:audio/musicpd
MMKEYS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}dbus>=0.82.4:devel/py-dbus
PYGNOMEEXTRAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gnome-extras>=2.25.3_4:x11-toolkits/py-gnome-extras
TAGLIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tagpy>=0.94.5:audio/py-tagpy
ZSI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zsi>=2.0,1:net/py-zsi

post-patch:
	@${REINPLACE_CMD} -e 's,%%DOCSDIR%%,${DOCSDIR},' \
		-e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/${PYSETUP} ${WRKSRC}/sonata.py

.include <bsd.port.mk>
