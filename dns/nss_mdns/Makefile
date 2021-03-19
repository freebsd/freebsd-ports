# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nss_mdns
PORTVERSION=	0.14.1.20200624
CATEGORIES=	dns

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	NSS module implementing multicast DNS name resolution

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavahi-client.so:net/avahi-app

USES=		autoreconf gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	lathiat
GH_PROJECT=	nss-mdns
GH_TAGNAME=	99c2f1c
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--sysconfdir=/etc

INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	mDNSResponder_nss-[0-9]*

# TODO: Print a message about the etc directory used for mdns.allow
# being relative to ${PREFIX}.
PLIST_FILES=	${INSTALLED_MODULES:C/^/lib\//:C/$/.so.1/} \
		${INSTALLED_MODULES:C/^/lib\//:C/$/.so/}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

INSTALLED_MODULES=	nss_mdns nss_mdns_minimal \
			nss_mdns4 nss_mdns4_minimal \
			nss_mdns6 nss_mdns6_minimal

post-install:
.for INSTALLED_MODULE in ${INSTALLED_MODULES}
	${LN} -s ${INSTALLED_MODULE}.so.1 ${STAGEDIR}${PREFIX}/lib/${INSTALLED_MODULE}.so
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${INSTALL_WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
