# New ports collection makefile for:	nss_mdns
# Date Created:		Jan 19 2007
# Whom:			Bruce M. Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nss_mdns
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	dns ipv6
MASTER_SITES=	http://0pointer.de/lennart/projects/nss-mdns/
DISTNAME=	nss-mdns-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	NSS module implementing multicast DNS name resolution

USE_AUTOTOOLS=	autoconf:259 automake:19 libtool:15
USE_GMAKE=	yes
USE_LDCONFIG=	yes

LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi

OPTIONS=			\
	SEARCH_DOMAINS "Honour search domains in resolv.conf" Off

CONFIGURE_ARGS+=		\
	--sysconfdir=/etc	\
	--localstatedir=/var	\
	--disable-static	\
	--enable-shared		\
	--enable-avahi		\
	--disable-legacy	\
	--disable-lynx

#
# libtool is used, therefore we must perform a GNU make based install,
# followed by removal of build rubble; we must create our own .so symlinks;
# we do this from the do-install target so as to avoid causing any
# problems if we are later packaged.
#
do-install:
	@( cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} )
	( cd ${PREFIX}/lib ; ${LN} -s nss_mdns.so.1 nss_mdns.so )
	${RM} ${PREFIX}/lib/nss_mdns.a ${PREFIX}/lib/nss_mdns.la
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/README ${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/README.html ${DOCSDIR}
.endif

# TODO: Print a message about the etc directory used for mdns.allow
# being relative to ${PREFIX}.
PLIST_FILES=	lib/nss_mdns.so	lib/nss_mdns.so.1
PORTDOCS=	README README.html

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		name-service switch support in libc.so.6 or later is required
.endif

.if defined(WITH_SEARCH_DOMAINS)
CONFIGURE_ARGS+=	--enable-search-domains
.endif

.include <bsd.port.post.mk>
