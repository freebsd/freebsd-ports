PORTNAME=	sonata
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.3
PORTREVISION=	0
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Elegant music player for MPD
WWW=		https://github.com/multani/sonata

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>=0.48.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-mpd2>=0.4.6:audio/py-python-mpd2@${PY_FLAVOR} \
		xdg-open:devel/xdg-utils

USES=		gettext gnome pkgconfig python

USE_GITHUB=	yes
GH_ACCOUNT=	multani
USE_GNOME=	pygobject3
USE_PYTHON=	autoplist pep517

PLIST_FILES=	${ICONSDIR}/sonata.png

OPTIONS_DEFINE=		DOCS MMKEYS MPD
OPTIONS_DEFAULT=	MPD
MMKEYS_DESC=		Enable instance single support for mmkeys
MPD_DESC=		Install Music Player Daemon
OPTIONS_SUB=		yes

MPD_RUN_DEPENDS+=	musicpd:audio/musicpd
MMKEYS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.4:devel/py-dbus@${FLAVOR}

ICONSDIR=	share/icons/hicolor/128x128/apps

post-patch:
	${REINPLACE_CMD} \
		-e "s,\(name=\)'Sonata',\1'sonata',1" \
		-e "s,/etc/mpd.conf,${PREFIX}/etc/musicpd.conf,1" \
		-e "s,/var/lib/mpd,/var/mpd,g" \
		-e "s,gksu,mdo,1" \
		-e 's,\("service"\, \)"mpd",\1"musicpd",1' \
		-e 's,ps wwu -C mpd,mdo ps -ww -U mpd,1' \
		${WRKSRC}/sonata/plugins/ui/localmpd.glade \
		${WRKSRC}/sonata/plugins/localmpd.py \
		${WRKSRC}/po/*.po \
		${WRKSRC}/setup.py

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ICONSDIR}
	${INSTALL_DATA} ${WRKSRC}/sonata/pixmaps/sonata.png \
		${STAGEDIR}${PREFIX}/${ICONSDIR}

.include <bsd.port.mk>
