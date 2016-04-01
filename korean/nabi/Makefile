# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nabi
PORTVERSION=	1.0.0
CATEGORIES=	korean gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul X Input Method for Everywhere

LICENSE=	GPLv2

LIB_DEPENDS=	libhangul.so:korean/libhangul

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig

OPTIONS_DEFINE=	NLS
OPTIONS_RADIO=	LAYOUT
OPTIONS_RADIO_LAYOUT=	LAYOUT_390 LAYOUT_FINAL
LAYOUT_DESC=	Select 3-beolsik layout (default: 2-beolsik)
LAYOUT_390_DESC=	3-beolsik 390 keyboard
LAYOUT_FINAL_DESC=	3-beolsik final keyboard
OPTIONS_SUB=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MLAYOUT_390}
CONFIGURE_ARGS=	--with-default-keyboard=39
.elif ${PORT_OPTIONS:MLAYOUT_FINAL}
CONFIGURE_ARGS=	--with-default-keyboard=3f
.else
CONFIGURE_ARGS=	--with-default-keyboard=2
.endif

.include <bsd.port.mk>
