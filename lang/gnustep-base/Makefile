# New ports collection makefile for:    gnustep-base
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-base
.if defined(WITH_GNUSTEP_DEVEL)
PORTVERSION=	1.21.0
.else
PORTVERSION=	1.19.3
PORTREVISION=	2
.endif
CATEGORIES=	lang devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep Foundation library

LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
LIB_DEPENDS+=	gnutls-openssl.40:${PORTSDIR}/security/gnutls
BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config

LICENSE=        GPLv3

USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-procfs --disable-openssl --enable-tls \
		--with-tls-prefix=${LOCALBASE} TLS_CONFIG="pkg-config -gnutls"
USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}
USE_ICONV=	yes

MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
CFLAGS+=	-I${LOCALBASE}/include/libxml2/libxml
BREAKS_IF_PEDANTIC=	yes
PLIST_SUB+=	LOCALBASE=${LOCALBASE}
ETCDIR=		${LOCALBASE}/etc

.if !defined(WITHOUT_GNUSTEP_FAKEMAIN)
CONFIGURE_ARGS+=	--enable-fake-main
.endif

PLIST_SUB+=	BASEVERSION=${PORTVERSION:C/[.][0-9]*$//1}
EXTRA_PATCHES+=	${FILESDIR}/NSFileManager.m.patch

.include <bsd.port.pre.mk>

PATH:=	${PREFIX}/System/Tools:${PATH}

post-build:
.for i in ${MAKE_APPS}
	(cd ${WRKSRC}/${i}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
.endfor

post-extract:
	@${SED} -e "s=%%PREFIX%%=${LOCALBASE}=" \
		-e "s=%%LDCONFIG_GCC%%=${LDCONFIG_GCC}=" \
		${FILESDIR}/GNUstep.sh \
		> ${WRKSRC}/GNUstep.sh
	@${REINPLACE_CMD} -e "s|/usr/local/|${LOCALBASE}/|" \
		${WRKSRC}/configure

post-install:
	-@${MKDIR} ${ETCDIR}/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/GNUstep.sh ${ETCDIR}/rc.d/GNUstep.sh
	${INSTALL_DATA} ${FILESDIR}/gdomap_if ${ETCDIR}
.for i in ${INSTALL_APPS}
	(cd ${WRKSRC}/${i}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} -d ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
.endfor

test:
	@(cd ${WRKSRC}/Testing && . ${GNUSTEP_MAKEFILES}/GNUstep.sh; ${GMAKE})

regression-test:	test

.include <bsd.port.post.mk>
