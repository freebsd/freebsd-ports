# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	getdns
PORTVERSION=	1.5.1
CATEGORIES=	dns ipv6
MASTER_SITES=	https://getdnsapi.net/dist/ \
		ZI \
		http://getdnsapi.net/dist/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Modern asynchronous DNS API

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libidn.so:dns/libidn \
		libldns.so:dns/ldns \
		libunbound.so:dns/unbound

USES=		libtool pathfix ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libidn=${LOCALBASE} --docdir=${DOCSDIR} \
		--with-trust-anchor=${LOCALBASE}/etc/unbound/root.key
SOMAJVER=	10
SOVERSION=	${SOMAJVER}.1.${PORTVERSION:C/[0-9].[0-9].([0-9])/\1/1}
MAKE_JOBS_UNSAFE=yes

PLIST_SUB+=	SOVERSION="${SOVERSION}" SOMAJVER="${SOMAJVER}"
SUB_FILES+=	pkg-message

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS LIBEV LIBEVENT LIBUV STUBBY

LIBEV_DESC=	Build with libev extension
LIBEVENT_DESC=	Build with libevent extension
LIBUV_DESC=	Build with libuv extension
STUBBY_DESC=	Build with Stubby DNS/TLS resolver

LIBEV_LIB_DEPENDS=	libev.so:devel/libev
LIBEV_CONFIGURE_WITH=	libev
LIBEVENT_LIB_DEPENDS=	libevent_core.so:devel/libevent
LIBEVENT_CONFIGURE_WITH=libevent
LIBUV_LIB_DEPENDS=	libuv.so:devel/libuv
LIBUV_CONFIGURE_WITH=	libuv
STUBBY_LIB_DEPENDS=	libyaml.so:textproc/libyaml
STUBBY_CONFIGURE_WITH=	stubby
STUBBY_VARS=		USE_RC_SUBR="stubby"

post-patch:
	${REINPLACE_CMD} -Ee 's,^(sharedoc = ).*,\1${WRKDIR}/doc,' \
		-e '/echo .\*\*\*/d' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgetdns*.so.*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/getdns_*

post-stage-STUBBY-on:
	${MV} ${STAGEDIR}${PREFIX}/etc/stubby/stubby.yml \
		${STAGEDIR}${PREFIX}/etc/stubby/stubby.yml.sample

post-install-STUBBY-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/stubby

.include <bsd.port.mk>
