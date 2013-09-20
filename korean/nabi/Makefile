# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nabi
PORTVERSION=	1.0.0
CATEGORIES=	korean gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul X Input Method for Everywhere

LICENSE=	GPLv2

LIB_DEPENDS=	hangul:${PORTSDIR}/korean/libhangul

USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	NLS=""
.else
PLIST_SUB=	NLS="@comment "
.endif

.if defined(WITH_LAYOUT_390)
CONFIGURE_ARGS=	--with-default-keyboard=39
.elif defined(WITH_LAYOUT_3FINAL)
CONFIGURE_ARGS=	--with-default-keyboard=3f
.endif

.include <bsd.port.mk>
