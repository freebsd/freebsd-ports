PORTNAME=	gnustep-base
DISTVERSION=	1.31.1
PORTREVISION=	1
CATEGORIES=	lang devel gnustep
MASTER_SITES=	https://github.com/gnustep/libs-base/releases/download/base-${DISTVERSION:S,.,_,g}/

MAINTAINER=	joe.maloney@icloud.com
COMMENT=	GNUstep Foundation library
WWW=		http://www.gnustep.org/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libffi.so:devel/libffi \
		libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp

RUN_DEPENDS=	${LOCALBASE}/GNUstep/System/Library/Makefiles/GNUstep.sh:devel/gnustep-make

USES=		pkgconfig iconv gnome gnustep
USE_GNOME=	libxml2 libxslt
USE_GNUSTEP=	build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

GNU_CONFIGURE=	yes

ETCDIR=		${LOCALBASE}/etc

STAGEHEADER=	${STAGEDIR}${PREFIX}/GNUstep/System/Library/Headers

CONFIGURE_ARGS=	--disable-procfs \
		--with-installation-domain=SYSTEM
CONFIGURE_ENV=	OBJCFLAGS='-fobjc-runtime=gnustep-2.0 -fblocks' \
		ac_cv_header_bfd_h=no ac_cv_lib_bfd_bfd_openr=no

PLIST_SUB=	BASEVERSION=${DISTVERSION:R}

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
LIB_DEPENDS+=		libavahi-client.so:net/avahi-app
CONFIGURE_ARGS+=	--with-zeroconf-api=avahi
.elif ${PORT_OPTIONS:MMDNS}
LIB_DEPENDS+=		libdns_sd.so:net/mDNSResponder
CONFIGURE_ARGS+=	--with-zeroconf-api=mdns
.else
CONFIGURE_ARGS+=	--disable-zeroconf
.endif

post-extract:
	@${REINPLACE_CMD} -e "s|/usr/local/|${LOCALBASE}/| ; \
		s|HAVE_TLS|HAVE_GNUTLS|" ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${FILESDIR}/gdomap_if ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
