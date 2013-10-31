# $FreeBSD$

PORTNAME=	libimobiledevice
PORTVERSION=	1.1.5
PORTREVISION?=	0
CATEGORIES?=	comms
MASTER_SITES=	http://www.${PORTNAME}.org/downloads/

MAINTAINER?=	avilla@FreeBSD.org
COMMENT?=	Library to communicate with Apple iOS devices

LICENSE?=	LGPL21

SLAVE_PORT?=	no

USES=		pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	openssl_LIBS=-lssl
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${SLAVE_PORT} == "no"

LIB_DEPENDS=	libplist.so:${PORTSDIR}/devel/libplist \
		libusbmuxd.so:${PORTSDIR}/comms/usbmuxd

USE_GNOME=	glib20
CONFIGURE_ARGS+=--without-cython
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's, *@ssl_requires@,,' \
		${WRKSRC}/${PORTNAME}*.pc.in
	@${REINPLACE_CMD} -e 's,$$(libdir)/pkgconfig,${PREFIX}/libdata/pkgconfig,g' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.endif # ${SLAVE_PORT} == "no"

.include <bsd.port.mk>
