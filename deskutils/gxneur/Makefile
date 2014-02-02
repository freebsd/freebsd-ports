# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gxneur
PORTVERSION=	0.15.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://dists.xneur.ru/release-${PORTVERSION}/tgz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK frontend for XNeur keyboard layout switcher

BUILD_DEPENDS=	xneur:${PORTSDIR}/deskutils/xneur
RUN_DEPENDS=	xneur:${PORTSDIR}/deskutils/xneur

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	gconf2 gtk20 libglade2
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--without-nls

post-patch:
	@${REINPLACE_CMD} -e '/all_modifiers/d' ${WRKSRC}/src/misc.c
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/configure

.include <bsd.port.mk>
