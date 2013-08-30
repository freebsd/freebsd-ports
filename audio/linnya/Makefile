# $FreeBSD$

PORTNAME=	linnya
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ghw@7axu.com
COMMENT=	A Linnya Audio Player

LICENSE=	GPLv3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	herenvarno
GH_COMMIT=	90cf6b8

USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtoolize libtool
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30
USE_SQLITE=	3
USE_GSTREAMER=	good mp3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

LIBTOOLIZE_ARGS=--copy --force

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e '/^$${CXXFLAGS/d' ${WRKSRC}/configure

.include <bsd.port.mk>
