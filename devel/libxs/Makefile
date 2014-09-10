# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxs
PORTVERSION=	1.2.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://download.crossroads.io/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Open source lightweight messaging layer

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USES=	pathfix pkgconfig libtool
USE_LDCONFIG=	yes
USE_GCC=	yes

OPTIONS_DEFINE=	DEBUG DOCS PLUGINS ZMQ
EXTERNAL_DESC=	PGM extension from ports
INTERNAL_DESC=	PGM extension
PLUGINS_DESC=	Additional plugins
ZMQ_DESC=	Compatibility with ZMQ
OPTIONS_RADIO=		PGM
OPTIONS_RADIO_PGM=	INTERNAL EXTERNAL
OPTIONS_DEFAULT=PLUGINS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto \
		${LOCALBASE}/share/xml/docbook/4.5:${PORTSDIR}/textproc/docbook-xml

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
LIB_DEPENDS+=		libpgm.so:${PORTSDIR}/net/openpgm
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
		${WRKSRC}/configure
.if ${PORT_OPTIONS:MEXTERNAL}
	${REINPLACE_CMD} "s|openpgm-5.1|openpgm-5.2|g" \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
