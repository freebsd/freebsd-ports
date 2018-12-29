# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.22
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU \
		SOURCEWARE/${PORTNAME}/releases
PKGNAMEPREFIX=	psptoolchain-

MAINTAINER=	tphilipp@potion-studios.com
COMMENT=	PlayStation Portable development toolchain ${PORTNAME}

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BROKEN_aarch64=		fails to package: ansidecl.h: No such file or directory
BROKEN_mips64=		fails to package: ansidecl.h: No such file or directory

USES=		gmake tar:bzip2 libtool

HAS_CONFIGURE=	yes
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/:C/armv*/arm/:S/powerpc64/powerpc/}-unknown-${OPSYS:tl}${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--target="psp" \
		--enable-install-libbfd \
		--disable-werror \
		--disable-nls \
		--mandir=${PREFIX}/man
PLIST_SUB=	CONFIGURE_TARGET="${CONFIGURE_TARGET}"

# Disable installation of .info files and libiberty.
post-patch:
	@${REINPLACE_CMD} -E 's/^(install-data-am:)(.*)install-info-am(.*)/\1 \2 \3/' \
		${WRKSRC}/ld/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install-info:)(.*install-info-am.*)/\1#\2/' \
		${WRKSRC}/gas/doc/Makefile.in \
		${WRKSRC}/bfd/doc/Makefile.in \
		${WRKSRC}/binutils/doc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install:)(.*)/\1#\2/' ${WRKSRC}/libiberty/Makefile.in
	@${REINPLACE_CMD} -E 's,^(install.*:)(.*)install-info(.*),\1 \2 \3,' ${WRKSRC}/etc/Makefile.in

.include <bsd.port.mk>
