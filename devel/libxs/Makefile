PORTNAME=	libxs
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	8
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source lightweight messaging layer
WWW=		https://github.com/crossroads-io/libxs

LICENSE=	GPLv3

BROKEN=		Unfetchable
DEPRECATED=	Upstream is gone and repo is deleted
EXPIRATION_DATE=2024-09-30

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		autoreconf pathfix pkgconfig libtool
USE_GITHUB=	yes
GH_ACCOUNT=	crossroads-io
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG DOCS PLUGINS ZMQ
EXTERNAL_DESC=	PGM extension from ports
INTERNAL_DESC=	PGM extension
PLUGINS_DESC=	Additional plugins
ZMQ_DESC=	Compatibility with ZMQ
OPTIONS_RADIO=		PGM
OPTIONS_RADIO_PGM=	INTERNAL EXTERNAL
OPTIONS_DEFAULT=PLUGINS

INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	asciidoc:textproc/asciidoc \
		xmlto:textproc/xmlto \
		docbook-xml>0:textproc/docbook-xml

.else
CONFIGURE_ARGS+=	--without-documentation
.endif

.if ${PORT_OPTIONS:MINTERNAL}
CONFIGURE_ARGS+=	--with-pgm
USES+=			perl5
CFLAGS+=		-fPIC
.endif

.if ${PORT_OPTIONS:MEXTERNAL}
CONFIGURE_ARGS+=	--with-system-pgm
LIB_DEPENDS+=		libpgm.so:net/openpgm
.endif

.if ${PORT_OPTIONS:MPLUGINS}
CONFIGURE_ARGS+=	--enable-plugins=yes
.else
CONFIGURE_ARGS+=	--enable-plugins=no
.endif

.if ${PORT_OPTIONS:MZMQ}
CONFIGURE_ARGS+=	--enable-libzmq
CONFLICTS=	zmq-*
PLIST_SUB+=	ZMQ=""
.else
PLIST_SUB+=	ZMQ="@comment "
.endif

pre-configure:
# fix for clang build
	@${REINPLACE_CMD} "/^libxs_werror=/ s|yes|no|" \
		${WRKSRC}/configure.ac
.if ${PORT_OPTIONS:MEXTERNAL}
	${REINPLACE_CMD} "s|openpgm-5.1|openpgm-5.2|g" \
		${WRKSRC}/configure.ac
.endif

.include <bsd.port.mk>
