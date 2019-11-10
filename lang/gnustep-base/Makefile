# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnustep-base
DISTVERSIONPREFIX=	base-
DISTVERSION=	1_26_0
PORTREVISION=	3
CATEGORIES=	lang devel gnustep

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	GNUstep Foundation library

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BROKEN_powerpc64=	fails to link: ld.lld: error: /usr/src/lib/csu/common/crtend.c:55: relocation R_PPC64_ADDR16_DS out of range: -32776 is not in [-32768, 32767]

LIB_DEPENDS+=	libffi.so:devel/libffi
LIB_DEPENDS+=	libxml2.so:textproc/libxml2
LIB_DEPENDS+=	libxslt.so:textproc/libxslt
LIB_DEPENDS+=	libgmp.so:math/gmp
LIB_DEPENDS+=	libgcrypt.so:security/libgcrypt

RUN_DEPENDS+=	${LOCALBASE}/GNUstep/System/Library/Makefiles/GNUstep.sh:devel/gnustep-make

USES=		pkgconfig iconv gnustep
USE_GNUSTEP=	build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

USE_GITHUB=	yes
GH_ACCOUNT=	gnustep
GH_PROJECT=	libs-base

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-procfs --disable-mixedabi --with-installation-domain=SYSTEM
CONFIGURE_ENV=	OBJCFLAGS='-fobjc-runtime=gnustep-2.0 -fblocks'

MAKE_FLAGS=	OPTFLAG="${CFLAGS}"

ETCDIR=		${LOCALBASE}/etc
STAGEHEADER=	${STAGEDIR}${PREFIX}/GNUstep/System/Library/Headers

PLIST_SUB+=	BASEVERSION=${PORTVERSION:R}

OPTIONS_DEFINE=		ICU GNUTLS
OPTIONS_RADIO=		ZEROCONF
OPTIONS_RADIO_ZEROCONF=	AVAHI MDNS
OPTIONS_DEFAULT=	ICU GNUTLS AVAHI
OPTIONS_SUB=		yes

ZEROCONF_DESC=		Zeroconf (Bonjour) support
AVAHI_DESC=		Zeroconf via Avahi (preferred)
MDNS_DESC=		Zeroconf via mDNSResponder

ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_CONFIGURE_OFF=	--disable-icu

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_OFF=	--disable-tls

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--with-zeroconf-api=avahi
LIB_DEPENDS+=		libavahi-client.so:net/avahi-app
.elif ${PORT_OPTIONS:MMDNS}
CONFIGURE_ARGS+=	--with-zeroconf-api=mdns
LIB_DEPENDS+=		libdns_sd.so:net/mDNSResponder
.else
CONFIGURE_ARGS+=	--disable-zeroconf
.endif

post-extract:
	@${REINPLACE_CMD} -e "s|/usr/local/|${LOCALBASE}/| ; \
		s|HAVE_TLS|HAVE_GNUTLS|" ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${FILESDIR}/gdomap_if ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
