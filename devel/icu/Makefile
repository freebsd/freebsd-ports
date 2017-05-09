# Created by: dwm
# $FreeBSD$

PORTNAME=	icu
DISTVERSION=	58_2
PORTREVISION?=	2 # keep for icu-lx
PORTEPOCH?=	1
CATEGORIES?=	devel
MASTER_SITES=	http://download.icu-project.org/files/icu4c/${PORTVERSION}/
DISTNAME=	icu4c-${DISTVERSION}-src

MAINTAINER=	office@FreeBSD.org
COMMENT?=	International Components for Unicode (from IBM)

LICENSE=	ICU
LICENSE_NAME=	ICU license
LICENSE_FILE=	${WRKSRC}/../LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--disable-layoutex
CONFIGURE_ARGS+=--with-data-packaging=archive \
		--disable-renaming \
		--disable-samples \
		--enable-static
CPPFLAGS+=	-DICU_NO_USER_DATA_OVERRIDE
MAKE_ARGS=	VERBOSE=1
TEST_TARGET=	check
USES+=		compiler:c++0x gmake pathfix tar:tgz
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/icu/source

ICUMAJOR=	${PORTVERSION:C/\..*//}
PLIST_SUB+=	ICUMAJOR=${ICUMAJOR} ICUVER=${PORTVERSION}

.ifndef PKGNAMESUFFIX
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/g* \
		${STAGEDIR}${PREFIX}/bin/*conv \
		${STAGEDIR}${PREFIX}/bin/icuinfo \
		${STAGEDIR}${PREFIX}/bin/derb \
		${STAGEDIR}${PREFIX}/bin/pkgdata
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/*
# Filename varies by endianness: icudt<major>b.dat vs. icudt<major>l.dat
	@(cd ${STAGEDIR}${PREFIX} && ${ECHO_CMD} \
		${DATADIR_REL}/${PORTVERSION}/icudt*.dat >>${TMPPLIST})
.endif # PKGNAMESUFFIX

.include <bsd.port.mk>
