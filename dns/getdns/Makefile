# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	getdns
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	dns ipv6
MASTER_SITES=	https://getdnsapi.net/dist/ \
		https://mirrors.rit.edu/zi/ \
		http://getdnsapi.net/dist/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Modern asynchronous DNS API

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libidn.so:dns/libidn \
		libldns.so:dns/ldns \
		libunbound.so:dns/unbound

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libidn=${LOCALBASE} --docdir=${DOCSDIR} \
		--with-trust-anchor=${LOCALBASE}/etc/unbound/root.key

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
SUB_FILES+=	pkg-message

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	EXAMPLES DOCS LIBEV LIBUV LIBEVENT

LIBEV_DESC=	Build with libev extension
LIBUV_DESC=	Build with libuv extension
LIBEVENT_DESC=	Build with libevent extension

LIBEV_LIB_DEPENDS=	libev.so:devel/libev
LIBEV_CONFIGURE_WITH=	libev
LIBUV_LIB_DEPENDS=	libuv.so:devel/libuv
LIBUV_CONFIGURE_WITH=	libuv
LIBEVENT_LIB_DEPENDS=	libevent.so:devel/libevent2
LIBEVENT_CONFIGURE_WITH=libevent

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 1000000
CONFIGURE_ARGS+=	--disable-gost
.endif

post-patch:
	${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -Ee 's,^(sharedoc = ).*,\1${WRKDIR}/doc,' \
		-e '/echo .\*\*\*/d' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	(cd ${WRKSRC}/spec/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/)
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgetdns.so.*

.include <bsd.port.post.mk>
