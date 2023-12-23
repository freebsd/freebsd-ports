PORTNAME=	srain
DISTVERSION=	1.3.1
PORTREVISION=	3
CATEGORIES=	irc

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modern IRC client written in GTK
WWW=		https://srain.im/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup

USES=		compiler:c11 gettext-tools desktop-file-utils gnome meson pkgconfig ssl
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 pango

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	DOCS

USE_GITHUB=		yes
GH_ACCOUNT=		SrainApp

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_MESON_ON=		-Ddoc_builders=html,man
DOCS_MESON_OFF=		-Ddoc_builders=

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
