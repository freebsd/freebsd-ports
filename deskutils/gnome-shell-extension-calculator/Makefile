# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell-extension-calculator
PORTVERSION=	0.0.0.20140520
PORTEVISION=	1
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple calculator in the gnome-shell search overview

BUILD_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell
RUN_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell

USES=		gettext gmake pkgconfig tar:xz
USE_GITHUB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GH_ACCOUNT=	eonpatapon
GH_TAGNAME=	e4f4ac5
GH_PROJECT=	gnome-shell-extension-calc

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

post-patch:
		@${REINPLACE_CMD} -e 's|3.12"|3.12","3.14"|g' \
			${WRKSRC}/calc\@patapon.info/metadata.json

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/
		@(cd ${WRKSRC} && ${CP} -pPR calc\@patapon.info ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/)

.include <bsd.port.mk>
