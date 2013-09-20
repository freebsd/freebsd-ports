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
USES=		desktop-file-utils pkgconfig
USE_GNOME=	gconf2 gtk20 libglade2
INSTALLS_ICONS=	yes

MAN1=		${PORTNAME}.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/all_modifiers/d' ${WRKSRC}/src/misc.c
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/configure

.include <bsd.port.mk>
