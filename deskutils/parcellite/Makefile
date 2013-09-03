# Created by: Joey Mingrone <joey@mingrone.org>
# $FreeBSD$

PORTNAME=	parcellite
PORTVERSION=	1.0.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jrm@ftfl.ca
COMMENT=	A lightweight GTK+ clipboard manager

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	gtk20

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=	parcellite.1

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g'\
		${WRKSRC}/src/keybinder.h

.include <bsd.port.mk>
