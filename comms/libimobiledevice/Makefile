PORTNAME=	libimobiledevice
DISTVERSION=	1.3.0-241
PORTREVISION?=	0
DISTVERSIONSUFFIX=	-g2a0a6d5
CATEGORIES?=	comms
#MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER?=	jhale@FreeBSD.org
COMMENT?=	Library to communicate with Apple iOS devices
WWW=		https://www.libimobiledevice.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES+=		autoreconf cpe libtool localbase:ldflags pkgconfig ssl
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=openssl_CFLAGS="-I${OPENSSLINC}" \
		openssl_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
INSTALL_TARGET=	install-strip

CFLAGS+=	-Wno-error=int-conversion

SLAVE_PORT?=	no

.if ${SLAVE_PORT} == no

LIB_DEPENDS=	libplist-2.0.so:devel/libplist \
		libimobiledevice-glue-1.0.so:comms/libimobiledevice-glue \
		libusbmuxd-2.0.so:comms/libusbmuxd \
		libtatsu.so:security/libtatsu

USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--without-cython

PORTDOCS=	AUTHORS NEWS README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.endif # ${SLAVE_PORT} == no

post-patch:
	@${REINPLACE_CMD} -e 's| *@ssl_requires@||' \
		${WRKSRC}/src/${PORTNAME}*.pc.in
	@echo "${DISTVERSIONFULL}" > ${WRKSRC}/.tarball-version

.include <bsd.port.mk>
