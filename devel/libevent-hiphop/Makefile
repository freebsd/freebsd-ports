# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-hiphop
PORTREVISION=	3

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Static libevent with custom patches for HipHop

LICENSE=	BSD

HIPHOP_DIR=	share/hiphop-php

_BUILDING_LIBEVENT_HIPHOP=	yes
CONFIGURE_ARGS+=	--disable-shared --enable-static
EXTRA_PATCHES=	${.CURDIR}/files/extra-patch-hiphop
GNU_CONFIGURE_PREFIX=	${PREFIX}/${HIPHOP_DIR}/ext
INSTALL_TARGET=	install-libLTLIBRARIES \
		install-includeHEADERS \
		install-nodist_includeHEADERS
PLIST_SUB+=	HIPHOP_DIR="${HIPHOP_DIR}"
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../libevent

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
