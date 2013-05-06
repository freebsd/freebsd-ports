# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nabi
PORTVERSION=	0.99.11
PORTREVISION=	1
CATEGORIES=	korean gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul X Input Method for Everywhere

LICENSE=	GPLv2

LIB_DEPENDS=	hangul.1:${PORTSDIR}/korean/libhangul

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_LAYOUT_390)
CONFIGURE_ARGS=	--with-default-keyboard=39
.elif defined(WITH_LAYOUT_3FINAL)
CONFIGURE_ARGS=	--with-default-keyboard=3f
.endif

.include <bsd.port.mk>
