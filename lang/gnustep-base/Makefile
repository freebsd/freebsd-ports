# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnustep-base
PORTVERSION=	1.24.6
PORTREVISION=	1
CATEGORIES=	lang devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	GNUstep Foundation library

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS+=	ffi:${PORTSDIR}/devel/libffi
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
LIB_DEPENDS+=	gnutls-openssl.27:${PORTSDIR}/security/gnutls
LIB_DEPENDS+=	icuuc:${PORTSDIR}/devel/icu
LIB_DEPENDS+=	objc.4:${PORTSDIR}/lang/libobjc2
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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PATH:=	${PREFIX}/System/Tools:${PATH}

post-extract:
	@${REINPLACE_CMD} -e "s|/usr/local/|${LOCALBASE}/|" \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${FILESDIR}/gdomap_if ${ETCDIR}

.include <bsd.port.post.mk>
