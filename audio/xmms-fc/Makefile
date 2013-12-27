# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	xmms-fc
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME} \
		SF/${PORTNAME}/${LIBFC_PORTNAME}:libfc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${LIBFC_DISTNAME}${EXTRACT_SUFX}:libfc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS future composer input plugin

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
NO_STAGE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_fc14audiodecoder_fc14dec_new=yes
CONFIGURE_ARGS=	--disable-gtktest
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/Input/fcdecoder.so lib/xmms/Input/fcdecoder.la

CPPFLAGS+=	-I${WRKDIR}/${LIBFC_DISTNAME}/src
LDFLAGS+=	-L${WRKDIR}/${LIBFC_DISTNAME}/src/.libs -lstdc++

LIBFC_PORTNAME=	libfc14audiodecoder
LIBFC_PORTVERSION=	1.0.2
LIBFC_DISTNAME=	${LIBFC_PORTNAME}-${LIBFC_PORTVERSION}

CFLAGS_amd64=	-fPIC -DPIC
CFLAGS_ia64=	-fPIC -DPIC

pre-configure:
	@(cd ${WRKDIR}/${LIBFC_DISTNAME} && ./configure --disable-shared \
		CC="${CC}" CFLAGS="${CFLAGS}" CXX="${CXX}" CXXFLAGS="${CXXFLAGS}")

pre-build:
	@(cd ${WRKDIR}/${LIBFC_DISTNAME} && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET} ${MAKE_ARGS})

.include <bsd.port.mk>
