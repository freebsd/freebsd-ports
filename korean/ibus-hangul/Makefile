# $FreeBSD$

PORTNAME=	ibus-hangul
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	korean
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul input engine for IBus

LICENSE=	GPLv2

LIB_DEPENDS=	libhangul.so:${PORTSDIR}/korean/libhangul \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus

PROJECTHOST=	ibus

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes
USES=		gmake libtool pkgconfig python
USE_GNOME=	intlhack pygobject3

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS=	--enable-nls
.else
CONFIGURE_ARGS=	--disable-nls
.endif

.include <bsd.port.mk>
