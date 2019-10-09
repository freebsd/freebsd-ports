# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nss_mdns
PORTVERSION=	0.10
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	http://0pointer.de/lennart/projects/nss-mdns/
DISTNAME=	nss-mdns-${PORTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	NSS module implementing multicast DNS name resolution

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavahi-client.so:net/avahi-app

CONFLICTS_INSTALL=	mDNSResponder_nss-[0-9]*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	SEARCH_DOMAINS DOCS
SEARCH_DOMAINS_DESC=	Honour search domains in resolv.conf

CONFIGURE_ARGS+=		\
	--sysconfdir=/etc	\
	--localstatedir=/var	\
	--enable-avahi		\
	--disable-legacy	\
	--disable-lynx

INSTALLED_MODULES=nss_mdns nss_mdns_minimal

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSEARCH_DOMAINS}
CONFIGURE_ARGS+=	--enable-search-domains
.endif

post-install:
.for INSTALLED_MODULE in ${INSTALLED_MODULES}
	${LN} -s ${INSTALLED_MODULE}.so.1 ${STAGEDIR}${PREFIX}/lib/${INSTALLED_MODULE}.so
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/README.html ${STAGEDIR}${DOCSDIR}
.endif

# TODO: Print a message about the etc directory used for mdns.allow
# being relative to ${PREFIX}.
PLIST_FILES=	${INSTALLED_MODULES:C/^/lib\//:C/$/.so/} ${INSTALLED_MODULES:C/^/lib\//:C/$/.so.1/}
PORTDOCS=	README README.html

.include <bsd.port.mk>
