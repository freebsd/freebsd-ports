# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=		binutils
PORTVERSION=		2.22
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gnu.org/pub/gnu/${PORTNAME}/ \
			${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases
PKGNAMEPREFIX=		psptoolchain-

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

USES=		gmake tar:bzip2
USE_GCC=		any

HAS_CONFIGURE=		yes
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-unknown-freebsd${OSREL}
CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--target="psp" \
			--enable-install-libbfd \
			--disable-nls \
			--mandir=${PREFIX}/man

MAN1=			psp-addr2line.1 \
			psp-ar.1 \
			psp-as.1 \
			psp-c++filt.1 \
			psp-dlltool.1 \
			psp-elfedit.1 \
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
			psp-windmc.1 \
			psp-windres.1

# Disable installation of .info files and libiberty.
NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -E 's/^(install-data-am:)(.*)install-info-am(.*)/\1 \2 \3/' \
		${WRKSRC}/ld/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install-info:)(.*install-info-am.*)/\1#\2/' \
		${WRKSRC}/gas/doc/Makefile.in \
		${WRKSRC}/bfd/doc/Makefile.in \
		${WRKSRC}/binutils/doc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install:)(.*)/\1#\2/' ${WRKSRC}/libiberty/Makefile.in
	@${REINPLACE_CMD} -E 's,^(install.*:)(.*)install-info(.*),\1 \2 \3,' ${WRKSRC}/etc/Makefile.in

post-install:
	@${FIND} -ds ${PREFIX}/${CONFIGURE_TARGET} ! -type d | ${SED} -e 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/${CONFIGURE_TARGET} -type d | ${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
