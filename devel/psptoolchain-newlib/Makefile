# New ports collection makefile for: psptoolchain-newlib
# Date created:        13 February 2009
# Whom:                Tassilo Philipp <tphilipp@potion-studios.com>
#
# $FreeBSD$
#

PORTNAME=		newlib
PORTVERSION=		1.15.0
CATEGORIES=		devel
MASTER_SITES=		ftp://sources.redhat.com/pub/ \
			${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=		psptoolchain-

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

PSP_GCC_STAGE_PREFIX=	psp/stage1
PSP_SDK_STAGE_PREFIX=	psp/stage1

BUILD_DEPENDS+=		${PREFIX}/${PSP_SDK_STAGE_PREFIX}/sdk/include/pspsdk.h:${PORTSDIR}/devel/psptoolchain-pspsdk-stage1 \
			psp-ar:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-as:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-ld:${PORTSDIR}/devel/psptoolchain-binutils \
			${PREFIX}/${PSP_GCC_STAGE_PREFIX}/bin/psp-gcc:${PORTSDIR}/devel/psptoolchain-gcc-stage1

USE_GMAKE=		yes

HAS_CONFIGURE=		yes
CONFIGURE_ENV=		PATH=${PREFIX}/${PSP_GCC_STAGE_PREFIX}/bin:${PATH}
MAKE_ENV=		PATH=${PREFIX}/${PSP_GCC_STAGE_PREFIX}/bin:${PATH}
CONFIGURE_ARGS=		--prefix=${PREFIX} --target=psp
MAKE_ARGS+=		CC="${CC}" CFLAGS="${CFLAGS} -g" # Apparently, it doesn't work on the PSP without debug information

# Disable installation of .info files and fix includedir reference.
post-patch:
	@${REINPLACE_CMD} -E 's/^(install:.*)(install-info.*)/\1#\2/' ${WRKSRC}/etc/Makefile.in
	@${REINPLACE_CMD} -E 's#(-I\$${prefix}/)psp(/sdk/include)#\1${PSP_SDK_STAGE_PREFIX:S,/,\\/,}\2#' ${WRKSRC}/newlib/configure.host

.include <bsd.port.mk>
