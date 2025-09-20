PORTNAME=	upnp
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.14.25
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Universal Plug and Play Software Development Kit
WWW=		http://pupnp.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe libtool pathfix pkgconfig
CPE_VENDOR=	libupnp_project
CPE_PRODUCT=	libupnp
USE_GITHUB=	yes
GH_ACCOUNT=	pupnp
GH_PROJECT=	pupnp
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-device \
		--enable-gena \
		--enable-soap \
		--enable-ssdp \
		--enable-webserver
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=		CLIENT DEBUG DOCS EXAMPLES IPV6 LARGEFILE OPENSSL \
			OPTSSDP POSTWRITE REUSEADDR SCRIPTSUPPORT TCP_BLOCK \
			TEST TOOLS UNSPECIFIED_SERVER
OPTIONS_DEFAULT=	CLIENT LARGEFILE OPTSSDP REUSEADDR SCRIPTSUPPORT \
			TCP_BLOCK TOOLS
OPTIONS_SUB=		yes

CLIENT_DESC=			Enable control point code
LARGEFILE_DESC=			Large files support
OPTSSDP_DESC=			Enable optional SSDP headers support
POSTWRITE_DESC=			Write to filesystem on unhandled POST requests
REUSEADDR_DESC=			Bind miniserver socket with reuseaddr
SCRIPTSUPPORT_DESC=		Enable script support for IXML document tree
TCP_BLOCK_DESC=			Enable blocking TCP connections
TEST_DESC=			Perfom a few tests (implies TOOLS)
TOOLS_DESC=			Enable helpers API in upnptools.h
UNSPECIFIED_SERVER_DESC=	Enable unspecified SERVER header

CLIENT_CONFIGURE_ENABLE=		client
DEBUG_CONFIGURE_ENABLE=			debug
EXAMPLES_CONFIGURE_ENABLE=		samples
IPV6_CONFIGURE_ENABLE=			ipv6
LARGEFILE_CONFIGURE_ENABLE=		largefile
OPENSSL_USES=				ssl
OPENSSL_CONFIGURE_ENABLE=		open_ssl
OPENSSL_CONFIGURE_ENV=			OPENSSL_CFLAGS="-I${OPENSSLINC}" \
					OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
OPTSSDP_CONFIGURE_ENABLE=		optssdp
POSTWRITE_CONFIGURE_ENABLE=		postwrite
REUSEADDR_CONFIGURE_ENABLE=		reuseaddr
SCRIPTSUPPORT_CONFIGURE_ENABLE=		scriptsupport
TCP_BLOCK_CONFIGURE_ENABLE=		blocking_tcp_connections
TEST_IMPLIES=				TOOLS
TOOLS_CONFIGURE_ENABLE=			tools
UNSPECIFIED_SERVER_CONFIGURE_ENABLE=	unspecified_server

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/UPnP_Programming_Guide.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
