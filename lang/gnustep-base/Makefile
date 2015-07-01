# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnustep-base
PORTVERSION=	1.24.8
CATEGORIES=	lang devel gnustep
MASTER_SITES=	GNUSTEP/core

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	GNUstep Foundation library

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

OPTIONS_RADIO=		ZEROCONF
OPTIONS_RADIO_ZEROCONF=	AVAHI MDNS
OPTIONS_DEFAULT=	AVAHI

NOZEROCONF_DESC=	Disable Zeroconf (Bonjour) support
AVAHI_DESC?=		Zeroconf via Avahi (preferred)
MDNS_DESC?=		Zeroconf via mDNSResponder

LIB_DEPENDS+=	libffi.so:${PORTSDIR}/devel/libffi
LIB_DEPENDS+=	libxml2.so:${PORTSDIR}/textproc/libxml2
LIB_DEPENDS+=	libxslt.so:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS+=	libgmp.so:${PORTSDIR}/math/gmp
LIB_DEPENDS+=	libgnutls-openssl.so:${PORTSDIR}/security/gnutls
LIB_DEPENDS+=	libicuuc.so:${PORTSDIR}/devel/icu
LIB_DEPENDS+=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-procfs --disable-openssl --enable-tls \
		--with-tls-prefix=${LOCALBASE} TLS_CONFIG="pkg-config -gnutls"\
		--disable-mixedabi
CONFIGURE_ENV+=	OBJCFLAGS='-fobjc-runtime=gnustep-1.7 -fblocks'
USES=		pkgconfig iconv gnustep
USE_GNUSTEP=	build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

ETCDIR=		${LOCALBASE}/etc
STAGEHEADER=	${STAGEDIR}${PREFIX}/GNUstep/System/Library/Headers

PLIST_SUB+=	BASEVERSION=${PORTVERSION:C/[.][0-9]*$//1}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--with-zeroconf-api=avahi
LIB_DEPENDS+=		libavahi-client.so:${PORTSDIR}/net/avahi-app
.elif ${PORT_OPTIONS:MMDNS}
CONFIGURE_ARGS+=	--with-zeroconf-api=mdns
LIB_DEPENDS+=		libdns_sd.so:${PORTSDIR}/net/mDNSResponder
.else
CONFIGURE_ARGS+=	--disable-zeroconf
.endif

post-extract:
	@${REINPLACE_CMD} -e "s|/usr/local/|${LOCALBASE}/|" \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${FILESDIR}/gdomap_if ${STAGEDIR}${ETCDIR}
	${RMDIR} ${STAGEHEADER}/gnustep/base
	${RMDIR} ${STAGEHEADER}/GNUstepBase/unicode

.include <bsd.port.mk>
