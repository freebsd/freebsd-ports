# $FreeBSD$

PORTNAME=	linnya
PORTVERSION=	2.2.1
CATEGORIES=	audio

MAINTAINER=	ghw@7axu.com
COMMENT=	A Linnya Audio Player

LICENSE=	GPLv3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	herenvarno
GH_COMMIT=	5b0f38a

USE_AUTOTOOLS=	libtoolize libtool
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PKGCONFIG=	build
USE_GNOME=	gtk30
USE_SQLITE=	3
USE_GSTREAMER=	good mp3 ogg
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

LIBTOOLIZE_ARGS=--copy --force

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e '/^$${CXXFLAGS/d' ${WRKSRC}/configure

.include <bsd.port.mk>
