# $FreeBSD$

PORTNAME=	srain
DISTVERSION=	1.1.0
CATEGORIES=	irc

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modern IRC client written in GTK

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup

USES=		compiler:c11 gettext-tools gmake gnome pkgconfig ssl
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 pango

USE_GITHUB=		yes
GH_ACCOUNT=		SrainApp
GNU_CONFIGURE=		yes
MAKE_FLAGS+=		MAKE_PROGRAM=${MAKE_CMD}
CONFIGURE_ARGS+=	--disable-debug
ALL_TARGET=		default
INSTALLS_ICONS=		yes

post-patch:
	${REINPLACE_CMD} -e '/^MAKE =/s/make/${MAKE_CMD}/' \
		${WRKSRC}/Makefile.in

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME} \
		${STAGEDIR}${DATADIR}/themes \
		${STAGEDIR}${PREFIX}/share/metainfo \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps

.include <bsd.port.mk>
