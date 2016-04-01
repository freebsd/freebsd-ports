# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kasumi
PORTVERSION=	2.5
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	SFJP/${PORTNAME}/41436

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Dictionary management tool for anthy

USES=		gmake pkgconfig
USE_GNOME=	gtk20
LIB_DEPENDS=	libanthy.so:japanese/anthy

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
