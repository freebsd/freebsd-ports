# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kasumi
PORTVERSION=	2.5
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	OSDN/${PORTNAME}/41436

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Dictionary management tool for anthy

LIB_DEPENDS=	libanthy.so:japanese/anthy

USES=		compiler:c++11-lang gmake localbase:ldflags pkgconfig
USE_GNOME=	gtk20

GNU_CONFIGURE=	yes

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
