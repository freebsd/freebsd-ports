# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnustep-base
PORTVERSION=	1.24.6
PORTREVISION=	3
CATEGORIES=	lang devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	GNUstep Foundation library

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

OPTIONS_RADIO=		ZEROCONF
OPTIONS_RADIO_ZEROCONF=	AVAHI MDNS
OPTIONS_DEFAULT=	AVAHI

NOZEROCONF_DESC=	Disable Zeroconf (Bonjour) support
AVAHI_DESC?=		Zeroconf via Avahi (preferred)
MDNS_DESC?=		Zeroconf via Apple's mDNSResponder

.include <bsd.port.options.mk>

LIB_DEPENDS+=	libffi.so:${PORTSDIR}/devel/libffi
LIB_DEPENDS+=	libxml2.so:${PORTSDIR}/textproc/libxml2
LIB_DEPENDS+=	libxslt.so:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS+=	libgmp.so:${PORTSDIR}/math/gmp
LIB_DEPENDS+=	libgnutls-openssl.so:${PORTSDIR}/security/gnutls
LIB_DEPENDS+=	libicuuc.so:${PORTSDIR}/devel/icu
LIB_DEPENDS+=	libobjc.so.4.6:${PORTSDIR}/lang/libobjc2
LIB_DEPENDS+=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-procfs --disable-openssl --enable-tls \
		--with-tls-prefix=${LOCALBASE} TLS_CONFIG="pkg-config -gnutls"\
		--disable-mixedabi
CONFIGURE_ENV+=	OBJCFLAGS='-fobjc-runtime=gnustep-1.7 -fblocks'
USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}
USES=		pkgconfig iconv

MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
CFLAGS+=	-I${LOCALBASE}/include/libxml2/libxml -DHAVE_DLADDR=1

BREAKS_IF_PEDANTIC=	yes
PLIST_SUB+=	LOCALBASE=${LOCALBASE}
ETCDIR=		${LOCALBASE}/etc

PLIST_SUB+=	BASEVERSION=${PORTVERSION:C/[.][0-9]*$//1}

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--with-zeroconf-api=avahi
LIB_DEPENDS+=		libavahi-client.so:${PORTSDIR}/net/avahi-app
.elif ${PORT_OPTIONS:MMDNS}
CONFIGURE_ARGS+=	--with-zeroconf-api=mdns
LIB_DEPENDS+=		libdns_sd.so:${PORTSDIR}/net/mDNSResponder
.else
CONFIGURE_ARGS+=	--disable-zeroconf
.endif

PATH:=	${PREFIX}/System/Tools:${PATH}

post-extract:
	@${REINPLACE_CMD} -e "s|/usr/local/|${LOCALBASE}/|" \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${FILESDIR}/gdomap_if ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
