PORTNAME=	gcli
DISTVERSION=	2.9.0
CATEGORIES=	devel net
MASTER_SITES=	https://herrhotzenplotz.de/gcli/releases/gcli-${DISTVERSION}/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	CLI utility to interact with various Git forges
WWW=		https://herrhotzenplotz.de/gcli/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpdjson.so:textproc/pdjson
TEST_DEPENDS=	kyua:devel/kyua

USES=		libtool pathfix pkgconfig ssl tar:xz

HAS_CONFIGURE=	yes
.if defined(WITH_DEBUG)
CONFIGURE_ARGS=	--debug
.else
CONFIGURE_ARGS=	--release
.endif
TEST_TARGET=	check

OPTIONS_DEFINE=	LOWDOWN TEST
OPTIONS_DEFAULT=	LIBEDIT LOWDOWN
OPTIONS_RADIO=	LINEEDIT
OPTIONS_RADIO_LINEEDIT=	LIBEDIT READLINE
LIBEDIT_USES=		libedit
LIBEDIT_CONFIGURE_ENABLE=	libedit
LOWDOWN_LIB_DEPENDS=	liblowdown.so:textproc/lowdown
LOWDOWN_CONFIGURE_ENABLE=	liblowdown
LOWDOWN_DESC=		pretty-print Markdown using textproc/lowdown
READLINE_USES=		readline
READLINE_CONFIGURE_ENABLE=	libreadline
TEST_LIB_DEPENDS=	libatf-c.so:devel/atf

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gcli

.include <bsd.port.mk>
