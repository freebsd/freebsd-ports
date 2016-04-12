# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	exmpp
PORTVERSION=	0.9.9
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel net-im
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Fast and scalable library for XMPP written in Erlang/OTP

LICENSE=	EPL

BUILD_DEPENDS=	erlc:lang/erlang
RUN_DEPENDS=	erl:lang/erlang
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libxml2.so:textproc/libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	processone

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-static=yes \
		--enable-shared=yes \
		--with-erlang=${LOCALBASE} \
		--with-expat=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE} \
		--disable-debug \
		--disable-warnings \
		--disable-examples \
		--enable-escaping-using-cdata
GNU_CONFIGURE_PREFIX=	"${PREFIX}/lib/erlang/lib"
PLIST_SUB=	VERSION=${PORTVERSION}
USES=		autoreconf cpe libtool pkgconfig
CPE_VENDOR=	process-one
USE_OPENSSL=	yes

DOCS_CONFIGURE_ENABLE=	documentation

MAKE_JOBS_UNSAFE=	yes

post-configure:
	${MAKE_CMD} clean -C ${WRKSRC}

post-install:
.for _file in exmpp_xml_expat_legacy.so exmpp_compress_zlib.so		\
	exmpp_xml_expat.so exmpp_stringprep.so exmpp_xml_libxml2.so	\
	exmpp_tls_openssl.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv/lib/${_file}
.endfor

.include <bsd.port.mk>
