# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	mixer
PORTVERSION=	0.1.1
CATEGORIES=	audio
MASTER_SITES=	http://www.defora.org/os/download/download/3705/
DISTNAME=	Mixer-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop audio mixer

LICENSE=	GPLv3

LIB_DEPENDS=	Desktop:${PORTSDIR}/x11/deforaos-libdesktop

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
PLIST_FILES=	bin/mixer \
		share/applications/mixer.desktop \
		share/locale/fr/LC_MESSAGES/Mixer.mo

post-patch:
	${REINPLACE_CMD} -e 's|Exec=mixer|Exec=${LOCALBASE}/bin/mixer|g' \
		${WRKSRC}/data/mixer.desktop

.include <bsd.port.mk>
