PORTNAME=	libsidplayfp
DISTVERSION=	2.3.1
PORTREVISON=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Library to play Commodore 64 music derived from libsidplay2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libgcrypt-config:security/libgcrypt
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		compiler:c++11-lang libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-exsid=no \
		--with-gcrypt

INSTALL_TARGET=	install-strip

PLIST_SUB+=	SIDPLAYFP_SHLIB_VER=${SIDPLAYFP_SHLIB_VERSION:C/\.[[:digit:].]+//} \
		SIDPLAYFP_SHLIB_VERSION=${SIDPLAYFP_SHLIB_VERSION} \
		STILVIEW_SHLIB_VER=${STILVIEW_SHLIB_VERSION:C/\.[[:digit:].]+//} \
		STILVIEW_SHLIB_VERSION=${STILVIEW_SHLIB_VERSION}

PORTDOCS1=	NEWS README TODO
PORTDOCS=	*

OPTIONS_DEFINE=	DEBUG DOCS DOXYGEN
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ON=	--enable-debug=full

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENV_OFF=	ac_cv_prog_HAVE_DOXYGEN=false

.include <bsd.port.options.mk>

.if ${ARCH} == "aarch64"
CONFIGURE_ARGS+=	--with-simd=neon
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--with-simd=sse2
.endif

SIDPLAYFP_SHLIB_VERSION=	6.3.23
STILVIEW_SHLIB_VERSION=		0.0.4

post-build-DOXYGEN-on:
	${MAKE_CMD} doc -C ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS1:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
