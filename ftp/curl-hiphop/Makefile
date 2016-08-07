# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-hiphop

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Static libcurl with custom patches for HipHop

BROKEN=		fails to build
DEPRECATED=	useful only for removed hiphop-php
EXPIRATION_DATE=	2016-09-07

SSP_UNSAFE=	Refuses -l in LDFLAGS

BUILDING_HIPHOP=	yes

HIPHOP_DIR=	share/hiphop-php
EXTRA_PATCHES=	${.CURDIR}/files/extra-patch-hiphop
GNU_CONFIGURE_PREFIX=	${PREFIX}/${HIPHOP_DIR}/ext
CONFIGURE_ARGS+=	--disable-shared --enable-static
PLIST_SUB+=	HIPHOP_DIR="${HIPHOP_DIR}"
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
