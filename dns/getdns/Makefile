# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	getdns
PORTVERSION=	0.1.5
CATEGORIES=	dns ipv6
MASTER_SITES=	http://getdnsapi.net/dist/ \
    		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Modern asynchronous DNS API

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
    		libidn.so:${PORTSDIR}/dns/libidn \
		libldns.so:${PORTSDIR}/dns/ldns \
		libunbound.so:${PORTSDIR}/dns/unbound

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

LIBEV_LIB_DEPENDS=	libev.so:${PORTSDIR}/devel/libev
LIBEV_CONFIGURE_WITH=	libev
LIBUV_LIB_DEPENDS=	libuv.so:${PORTSDIR}/devel/libuv
LIBUV_CONFIGURE_WITH=	libuv
LIBEVENT_LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent
LIBEVENT_CONFIGURE_WITH=libevent

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -Ee 's,^(sharedoc = ).*,\1${WRKDIR}/doc,' \
	    	-e '/echo .\*\*\*/d' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${WRKDIR}/examples
	@${MV} ${WRKSRC}/spec/${PORTNAME}*gz ${WRKDIR}/examples/${PORTNAME}.tgz
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKDIR}/examples && ${TAR} --strip-components=1 -xf ${PORTNAME}.tgz)
	@(cd ${WRKDIR}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/)
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgetdns.so.1.0.0

.include <bsd.port.mk>
