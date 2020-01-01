# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	exmpp
PORTVERSION=	0.9.9
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel net-im
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Fast and scalable library for XMPP written in Erlang/OTP

BROKEN_SSL=	openssl

LICENSE=	EPL

BUILD_DEPENDS=	erlc:lang/erlang \
		gsed:textproc/gsed
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
CONFIGURE_ENV=	ac_cv_path_SED=${LOCALBASE}/bin/gsed
GNU_CONFIGURE_PREFIX=	"${PREFIX}/lib/erlang/lib"
PLIST_SUB=	VERSION=${PORTVERSION}
USES=		autoreconf cpe libtool pkgconfig ssl
CPE_VENDOR=	process-one

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_ENABLE=	documentation

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085 && ${SSL_DEFAULT} == base
BROKEN=	Does not support OpenSSL 1.1
.endif

post-configure:
	${REINPLACE_CMD}  's|\(-spec.*\)\/[0-9] ::\(.*\)|\1\2|g' ${WRKSRC}/src/network/*.erl
	${REINPLACE_CMD}  's|\(-spec.*\)\/[0-9] ::\(.*\)|\1\2|g' ${WRKSRC}/src/core/*.erl
	${MAKE_CMD} clean -C ${WRKSRC}

post-install:
.for _file in exmpp_xml_expat_legacy.so exmpp_compress_zlib.so		\
	exmpp_xml_expat.so exmpp_stringprep.so exmpp_xml_libxml2.so	\
	exmpp_tls_openssl.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv/lib/${_file}
.endfor

.include <bsd.port.mk>
