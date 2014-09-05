# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nss_mdns
PORTVERSION=	0.10
PORTREVISION=	3
CATEGORIES=	dns ipv6
MASTER_SITES=	http://0pointer.de/lennart/projects/nss-mdns/
DISTNAME=	nss-mdns-${PORTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	NSS module implementing multicast DNS name resolution

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app

CONFLICTS_INSTALL=	mDNSResponder_nss-[0-9]*

USE_AUTOTOOLS=	autoconf automake
USES=		gmake libtool
USE_LDCONFIG=	yes
AUTOTOOLSFILES=	aclocal.m4

OPTIONS_DEFINE=	SEARCH_DOMAINS DOCS
SEARCH_DOMAINS_DESC=	Honour search domains in resolv.conf

CONFIGURE_ARGS+=		\
	--sysconfdir=/etc	\
	--localstatedir=/var	\
	--disable-static	\
	--enable-shared		\
	--enable-avahi		\
	--disable-legacy	\
	--disable-lynx

INSTALLED_MODULES=nss_mdns nss_mdns_minimal

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSEARCH_DOMAINS}
CONFIGURE_ARGS+=	--enable-search-domains
.endif

#
# libtool is used, therefore we must perform a GNU make based install,
# followed by removal of build rubble; we must create our own .so symlinks;
# we do this from the do-install target so as to avoid causing any
# problems if we are later packaged.
#
do-install:
	@( cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} )
.for INSTALLED_MODULE in ${INSTALLED_MODULES}
	( cd ${STAGEDIR}${PREFIX}/lib ; ${LN} -s ${INSTALLED_MODULE}.so.1 ${INSTALLED_MODULE}.so )
	${RM} ${STAGEDIR}${PREFIX}/lib/${INSTALLED_MODULE}.a ${STAGEDIR}${PREFIX}/lib/${INSTALLED_MODULE}.la
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

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -print | \
		${XARGS} ${REINPLACE_CMD} -e 's|MKDIR_P|mkdir_p|g'

.include <bsd.port.mk>
