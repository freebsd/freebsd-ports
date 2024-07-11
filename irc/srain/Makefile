PORTNAME=	srain
DISTVERSION=	1.7.0
CATEGORIES=	irc

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modern IRC client written in GTK
WWW=		https://srain.silverrainz.me/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3

USES=		compiler:c11 desktop-file-utils gettext-tools gnome meson \
		pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	SrainApp
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 pango

OPTIONS_DEFINE=		APP_INDICATOR DOCS
OPTIONS_DEFAULT=	APP_INDICATOR

APP_INDICATOR_DESC=	Enable application indicator support

APP_INDICATOR_LIB_DEPENDS=	libayatana-appindicator3.so:devel/libayatana-appindicator
APP_INDICATOR_MESON_ON=		-Dapp_indicator=true
APP_INDICATOR_MESON_OFF=	-Dapp_indicator=false
DOCS_BUILD_DEPENDS=		sphinx-build:textproc/py-sphinx
DOCS_MESON_ON=			-Ddoc_builders=html,man
DOCS_MESON_OFF=			-Ddoc_builders=

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
LDFLAGS+=	-lcrypto

post-patch:
	${REINPLACE_CMD} -e "/dependency('openssl'),/d" \
		${WRKSRC}/src/meson.build
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME} \
		${STAGEDIR}${DATADIR}/themes \
		${STAGEDIR}${PREFIX}/share/metainfo \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps

.include <bsd.port.post.mk>
