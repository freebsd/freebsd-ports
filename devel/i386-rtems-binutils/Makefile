# New ports collection makefile for:	i386-rtems-binutils
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	2.13.2.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
#PATCHFILES=	${BINNAME}-rtems-20010622.diff
#PATCH_SITES=	ftp://ftp.rtems.com/pub/rtems/snapshots/c_tools/source/ \
#		http://rtems.thehousleys.net/

MAINTAINER=	jeh@FreeBSD.org
COMMENT=	FSF binutils-2.13.2.1 base-port for RTEMS development

LCLTARGET?=	i386-rtems

BINNAME=	binutils-2.13.2.1
PLIST=		${PKGDIR}/pkg-plist.${LCLTARGET}

PKGNAMEPREFIX=	${LCLTARGET}-
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all info
USE_REINPLACE=	yes

CONFIGURE_TARGET?=	--target=${LCLTARGET}
CONFIGURE_ARGS?=	--verbose
CONFIGURE_WRKSRC?=	${WRKDIR}/build-${LCLTARGET}
CONFIGURE_SCRIPT?=	../${BINNAME}/configure

PATCH_DIST_STRIP?=	-p1

MAN1=		${LCLTARGET}-ar.1 ${LCLTARGET}-nm.1 ${LCLTARGET}-objdump.1 \
		${LCLTARGET}-ranlib.1 ${LCLTARGET}-size.1 \
		${LCLTARGET}-strings.1 ${LCLTARGET}-strip.1 \
		${LCLTARGET}-objcopy.1 ${LCLTARGET}-addr2line.1 \
		${LCLTARGET}-nlmconv.1 ${LCLTARGET}-as.1 ${LCLTARGET}-ld.1 \
		${LCLTARGET}-dlltool.1 ${LCLTARGET}-readelf.1 \
		${LCLTARGET}-windres.1 ${LCLTARGET}-c++filt.1
INFO=		${LCLTARGET}-as ${LCLTARGET}-bfd ${LCLTARGET}-binutils \
		${LCLTARGET}-ld

post-patch:
	@${REINPLACE_CMD} -e 's|setfilename as.info|setfilename ${LCLTARGET}-as.info|' ${WRKSRC}/gas/doc/as.texinfo
	@${REINPLACE_CMD} -e 's|(as)|(${LCLTARGET}-as)|' ${WRKSRC}/gas/doc/as.texinfo
	@${REINPLACE_CMD} -e 's|@file{as}|@file{${LCLTARGET}-as}|' ${WRKSRC}/gas/doc/as.texinfo
	@${REINPLACE_CMD} -e 's|as.info|${LCLTARGET}-as.info|' ${WRKSRC}/gas/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|as.texinfo|${LCLTARGET}-as.texinfo|' ${WRKSRC}/gas/doc/Makefile.in
	@${MV} ${WRKSRC}/gas/doc/as.texinfo ${WRKSRC}/gas/doc/${LCLTARGET}-as.texinfo
	@${REINPLACE_CMD} -e 's|setfilename bfd.info|setfilename ${LCLTARGET}-bfd.info|' ${WRKSRC}/bfd/doc/bfd.texinfo
	@${REINPLACE_CMD} -e 's|(bfd)|(${LCLTARGET}-bfd)|' ${WRKSRC}/bfd/doc/bfd.texinfo
	@${REINPLACE_CMD} -e 's|@file{bfd}|@file{${LCLTARGET}-bfd}|' ${WRKSRC}/bfd/doc/bfd.texinfo
	@${REINPLACE_CMD} -e 's|bfd.info|${LCLTARGET}-bfd.info|' ${WRKSRC}/bfd/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|bfd.texinfo|${LCLTARGET}-bfd.texinfo|' ${WRKSRC}/bfd/doc/Makefile.in
	@${MV} ${WRKSRC}/bfd/doc/bfd.texinfo ${WRKSRC}/bfd/doc/${LCLTARGET}-bfd.texinfo
	@${REINPLACE_CMD} -e 's|setfilename binutils.info|setfilename ${LCLTARGET}-binutils.info|' ${WRKSRC}/binutils/doc/binutils.texi
	@${REINPLACE_CMD} -e 's|(binutils)|(${LCLTARGET}-binutils)|' ${WRKSRC}/binutils/doc/binutils.texi
	@${REINPLACE_CMD} -e 's|@file{binutils}|@file{${LCLTARGET}-binutils}|' ${WRKSRC}/binutils/doc/binutils.texi
	@${REINPLACE_CMD} -e 's|binutils.info|${LCLTARGET}-binutils.info|' ${WRKSRC}/binutils/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|binutils.texi|${LCLTARGET}-binutils.texi|' ${WRKSRC}/binutils/doc/Makefile.in
	@${MV} ${WRKSRC}/binutils/doc/binutils.texi ${WRKSRC}/binutils/doc/${LCLTARGET}-binutils.texi
	@${REINPLACE_CMD} -e 's|setfilename ld.info|setfilename ${LCLTARGET}-ld.info|' ${WRKSRC}/ld/ld.texinfo
	@${REINPLACE_CMD} -e 's|(ld)|(${LCLTARGET}-ld)|' ${WRKSRC}/ld/ld.texinfo
	@${REINPLACE_CMD} -e 's|@file{ld}|@file{${LCLTARGET}-ld}|' ${WRKSRC}/ld/ld.texinfo
	@${REINPLACE_CMD} -e 's|ld.info|${LCLTARGET}-ld.info|' ${WRKSRC}/ld/Makefile.in
	@${REINPLACE_CMD} -e 's|ld.texinfo|${LCLTARGET}-ld.texinfo|' ${WRKSRC}/ld/Makefile.in
	@${MV} ${WRKSRC}/ld/ld.texinfo ${WRKSRC}/ld/${LCLTARGET}-ld.texinfo

pre-configure:
	@(cd ${WRKDIR} ; ${MKDIR} build-${LCLTARGET})

do-build:
	@(cd ${WRKDIR}/build-${LCLTARGET} ; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKDIR}/build-${LCLTARGET} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>
