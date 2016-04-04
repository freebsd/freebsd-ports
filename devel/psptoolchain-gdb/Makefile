# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=		gdb
PORTVERSION=		7.3.1
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		GNU
PKGNAMEPREFIX=		psptoolchain-

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

BUILD_DEPENDS=		${LOCALBASE}/psp/sdk/lib/libpspsdk.a:devel/psptoolchain-pspsdk-stage2

USES=			gmake tar:bzip2
USE_CSTD=		gnu89

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--target="psp" \
			--disable-werror \
			--disable-nls \
			--disable-install-libiberty \
			--mandir=${PREFIX}/man

# Disable installation of .info files and libiberty.
post-patch:
	@${REINPLACE_CMD} -E 's/^(INFO_DEPS.*=)(.*)/\1#\2/' ${WRKSRC}/bfd/doc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(INFO_DEPS.*=)(.*)/\1#\2/' ${WRKSRC}/gdb/doc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install.*:.*)install-info(.*)/\1\2/' ${WRKSRC}/etc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install:)(.*)/\1#\2/' ${WRKSRC}/libiberty/Makefile.in

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/info

.include <bsd.port.mk>
