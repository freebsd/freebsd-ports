# New ports collection makefile for: psptoolchain-binutils
# Date created:        13 February 2009
# Whom:                Tassilo Philipp <tphilipp@potion-studios.com>
#
# $FreeBSD$
#

PORTNAME=		binutils
PORTVERSION=		2.16.1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gnu.org/pub/gnu/${PORTNAME}/ \
			${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases
PKGNAMEPREFIX=		psptoolchain-

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

USE_BZIP2=		yes
USE_GMAKE=		yes

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX} --target="psp" --enable-install-libbfd --disable-nls

MAN1=			psp-addr2line.1 \
			psp-ar.1 \
			psp-as.1 \
			psp-c++filt.1 \
			psp-dlltool.1 \
			psp-gprof.1 \
			psp-ld.1 \
			psp-nlmconv.1 \
			psp-nm.1 \
			psp-objcopy.1 \
			psp-objdump.1 \
			psp-ranlib.1 \
			psp-readelf.1 \
			psp-size.1 \
			psp-strings.1 \
			psp-strip.1 \
			psp-windres.1

# Disable installation of .info files and libiberty.
post-patch:
	@${REINPLACE_CMD} -E 's/^(INFO_DEPS.*=)(.*)/\1#\2/' ${WRKSRC}/bfd/doc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(INFO_DEPS.*=)(.*)/\1#\2/' ${WRKSRC}/binutils/doc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(INFO_DEPS.*=)(.*)/\1#\2/' ${WRKSRC}/gas/doc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(INFO_DEPS.*=)(.*)/\1#\2/' ${WRKSRC}/gprof/Makefile.in
	@${REINPLACE_CMD} -E 's/^(INFO_DEPS.*=)(.*)/\1#\2/' ${WRKSRC}/ld/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install:.*)(install-info.*)/\1#\2/' ${WRKSRC}/etc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install:)(.*)/\1#\2/' ${WRKSRC}/libiberty/Makefile.in

.include <bsd.port.mk>
