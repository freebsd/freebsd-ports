# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mixer
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.defora.org/os/download/download/3705/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Mixer-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop audio mixer

LICENSE=	GPLv3

LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop

MAKE_ARGS=	PREFIX=${PREFIX}
USES=		desktop-file-utils gettext pkgconfig
USE_GNOME=	gtk20
PLIST_FILES=	bin/mixer \
		share/applications/mixer.desktop \
		share/locale/fr/LC_MESSAGES/Mixer.mo
post-patch:
	${REINPLACE_CMD} -e 's|Exec=mixer|Exec=${LOCALBASE}/bin/mixer|g' \
		${WRKSRC}/data/mixer.desktop

.include <bsd.port.mk>
