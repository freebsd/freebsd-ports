# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxs
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	devel

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Open source lightweight messaging layer

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:features pathfix pkgconfig libtool
USE_GITHUB=	yes
GH_ACCOUNT=	crossroads-io
USE_LDCONFIG=	yes

PATHFIX_MAKEFILEIN=	Makefile.am

OPTIONS_DEFINE=	DEBUG DOCS PLUGINS ZMQ
EXTERNAL_DESC=	PGM extension from ports
INTERNAL_DESC=	PGM extension
PLUGINS_DESC=	Additional plugins
ZMQ_DESC=	Compatibility with ZMQ
OPTIONS_RADIO=		PGM
OPTIONS_RADIO_PGM=	INTERNAL EXTERNAL
OPTIONS_DEFAULT=PLUGINS

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 36 && \
	!${COMPILER_FEATURES:Mlibstdc++}
# Allow declaration of map and multimap iterator with incomplete mapped type
# by applying upstream change r231119 to a copy of our local c++ headers.
# This fix is not needed for clang 3.4 on 9.3 which uses libstdc++.
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-map
CPPFLAGS+=	-I${WRKSRC}/map-fix

post-extract:
	${MKDIR} ${WRKSRC}/map-fix
	${CP} /usr/include/c++/v1/__tree /usr/include/c++/v1/map \
		${WRKSRC}/map-fix/.
.endif

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

.include <bsd.port.post.mk>
