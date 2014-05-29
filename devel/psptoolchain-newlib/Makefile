# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=		newlib
PORTVERSION=		1.20.0
CATEGORIES=		devel
MASTER_SITES=		ftp://sources.redhat.com/pub/ \
			${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=		psptoolchain-

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

PSP_GCC_STAGE_PREFIX=	psp/stage1
PSP_SDK_STAGE_PREFIX=	psp/stage1

BUILD_DEPENDS+=		${LOCALBASE}/${PSP_SDK_STAGE_PREFIX}/sdk/include/pspsdk.h:${PORTSDIR}/devel/psptoolchain-pspsdk-stage1 \
			psp-ar:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-as:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-ld:${PORTSDIR}/devel/psptoolchain-binutils \
			${LOCALBASE}/${PSP_GCC_STAGE_PREFIX}/bin/psp-gcc:${PORTSDIR}/devel/psptoolchain-gcc-stage1

USES=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ENV=		PATH=${LOCALBASE}/${PSP_GCC_STAGE_PREFIX}/bin:${PATH}
MAKE_ENV=		PATH=${LOCALBASE}/${PSP_GCC_STAGE_PREFIX}/bin:${PATH}
CONFIGURE_ARGS=		--prefix=${PREFIX} --target="psp"
MAKE_ARGS+=		CC="${CC}" CFLAGS="${CFLAGS} -g" # Apparently, it doesn't work on the PSP without debug information

# Disable installation of .info files and fix includedir reference.
NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -E 's/^(install.*:.*)install-info(.*)/\1\2/' ${WRKSRC}/etc/Makefile.in
	@${REINPLACE_CMD} -E 's#(-I\$${prefix}/)psp(/sdk/include)#-I${LOCALBASE}/${PSP_SDK_STAGE_PREFIX:S,/,\\/,}\2#' ${WRKSRC}/newlib/configure.host

.include <bsd.port.pre.mk>

# Rename installed crt0.o as real crt0.o used by PSP code comes with psptoolchain-pspsdk-stage2
# and would overwrite the one from this port.
post-install:
	@${MV} ${PREFIX}/psp/lib/crt0.o ${PREFIX}/psp/lib/crt0.newlib.o

.include <bsd.port.post.mk>
