PORTNAME=	libimobiledevice
PORTVERSION=	1.3.0
PORTREVISION?=	0
CATEGORIES?=	comms
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER?=	jhale@FreeBSD.org
COMMENT?=	Library to communicate with Apple iOS devices

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

SLAVE_PORT?=	no

USES+=		cpe libtool localbase pathfix pkgconfig ssl tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=openssl_CFLAGS="-I${OPENSSLINC}" \
		openssl_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.if ${SLAVE_PORT} == no

LIB_DEPENDS=	libplist-2.0.so:devel/libplist \
		libusbmuxd-2.0.so:comms/libusbmuxd

USES+=		gnome
USE_GNOME=	glib20
CONFIGURE_ARGS+=--without-cython
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's, *@ssl_requires@,,' \
		${WRKSRC}/src/${PORTNAME}*.pc.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.endif # ${SLAVE_PORT} == no

.include <bsd.port.mk>
