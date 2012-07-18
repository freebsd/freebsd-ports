# New ports collection makefile for:	curl-hiphop
# Date created:		16 July 2012
# Whom:			Martin Matuska <mm@FreeBSd.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-hiphop

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Static libcurl with custom patches for HipHop

BUILDING_HIPHOP=	yes

HIPHOP_DIR=	share/hiphop-php
EXTRA_PATCHES=	${.CURDIR}/files/extra-patch-hiphop
GNU_CONFIGURE_PREFIX=	${PREFIX}/${HIPHOP_DIR}/ext
CONFIGURE_ARGS+=	--disable-shared --enable-static
PLIST_SUB+=	HIPHOP_DIR="${HIPHOP_DIR}"
LATEST_LINK=	curl-hiphop
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../curl

do-install:
.for dir in include lib
	@cd ${WRKSRC}/${dir} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}
.endfor

.include "${MASTERDIR}/Makefile"
