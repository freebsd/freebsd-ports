# $FreeBSD$

PORTNAME=	ibus-hangul
PORTVERSION=	1.4.2
CATEGORIES=	korean
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul input engine for IBus

LICENSE=	GPLv2

LIB_DEPENDS=	libhangul.so:${PORTSDIR}/korean/libhangul \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus

PROJECTHOST=	ibus

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	intltool pygobject3
USE_PYTHON=	yes
USES=		gmake pathfix pkgconfig

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
