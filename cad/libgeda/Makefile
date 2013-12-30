# Created by: bruno schwander <bruno@tinkerbox.org>
# $FreeBSD$

PORTNAME=	libgeda
PORTVERSION=	1.4.3
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.4/${PORTVERSION}/ \
		http://geda.seul.org/release/v1.4/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The gEDA's tools base utility library

LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		gmake pathfix pkgconfig shared-mime-info
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-update-mime-database \
		--disable-update-desktop-database
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(DATADIR[[:space:]]*=[[:space:]]*)gEDA,\1geda," \
		${WRKSRC}/configure

.include <bsd.port.mk>
