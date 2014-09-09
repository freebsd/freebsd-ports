# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.23.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	${TGTARCH}-${TGTABI}-

PATCH_SITES=	ftp://ftp.rtems.com/pub/rtems/SOURCES/4.11/
PATCH_DIST_STRIP=	-p1

MAINTAINER= 	brooks@FreeBSD.org
COMMENT=	GNU binutils port for cross-target development

USES=		gmake makeinfo tar:bzip2
GNU_CONFIGURE=	yes
ALL_TARGET=	all info
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--disable-nls \
			--with-system-zlib \
			--with-sysroot=/ \
			--target=${OURTARGET} \
			--disable-werror

OURTARGET=	${TGTARCH}-${TGTABI}

INFO=		${OURTARGET}-as \
		${OURTARGET}-bfd \
		${OURTARGET}-binutils \
		${OURTARGET}-ld

PLIST_FILES=	bin/${OURTARGET}-addr2line \
		bin/${OURTARGET}-ar \
		bin/${OURTARGET}-as \
		bin/${OURTARGET}-c++filt \
		bin/${OURTARGET}-elfedit \
		bin/${OURTARGET}-ld \
		bin/${OURTARGET}-ld.bfd \
		bin/${OURTARGET}-nm \
		bin/${OURTARGET}-objcopy \
		bin/${OURTARGET}-objdump \
		bin/${OURTARGET}-ranlib \
		bin/${OURTARGET}-readelf \
		bin/${OURTARGET}-size \
		bin/${OURTARGET}-strings \
		bin/${OURTARGET}-strip \
		man/man1/${OURTARGET}-addr2line.1.gz \
		man/man1/${OURTARGET}-ar.1.gz \
		man/man1/${OURTARGET}-as.1.gz \
		man/man1/${OURTARGET}-c++filt.1.gz \
		man/man1/${OURTARGET}-elfedit.1.gz \
		man/man1/${OURTARGET}-dlltool.1.gz \
		man/man1/${OURTARGET}-ld.1.gz \
		man/man1/${OURTARGET}-nlmconv.1.gz \
		man/man1/${OURTARGET}-nm.1.gz \
		man/man1/${OURTARGET}-objcopy.1.gz \
		man/man1/${OURTARGET}-objdump.1.gz \
		man/man1/${OURTARGET}-ranlib.1.gz \
		man/man1/${OURTARGET}-readelf.1.gz \
		man/man1/${OURTARGET}-size.1.gz \
		man/man1/${OURTARGET}-strings.1.gz \
		man/man1/${OURTARGET}-strip.1.gz \
		man/man1/${OURTARGET}-windmc.1.gz \
		man/man1/${OURTARGET}-windres.1.gz

.if defined(TGTARCH) && ${TGTARCH} != mips
INFO+=		${OURTARGET}-gprof
PLIST_FILES+=	bin/${OURTARGET}-gprof \
		man/man1/${OURTARGET}-gprof.1.gz
.endif

.if defined(TGTABI) && (${TGTABI} == pc-mingw32 || ${TGTABI} == mingw32)
PLIST_FILES+=	bin/${OURTARGET}-dlltool \
		bin/${OURTARGET}-dllwrap \
		bin/${OURTARGET}-windmc \
		bin/${OURTARGET}-windres
.endif

.if ${PORT_OPTIONS:MRTEMS_PATCHES}
PATCHFILES+=	${PORTNAME}-${PORTVERSION}-rtems4.11-20130326.diff
.endif

.if !defined(TGTARCH) || !defined(TGTABI)
PKGNAMEPREFIX=	cross-
IGNORE=		you should define TGTARCH and TGTABI to build port
.endif

#
# Macro to fix up info referencies
#
FIXREFS=	${SH} -c '${REINPLACE_CMD} -E \
		-e "s,$$0\.(texi|info),${OURTARGET}-$$0.\1,g" \
		-e "s,(@file)\{$$0\},\1\{${OURTARGET}-$$0\},g" \
		-e "s,\($$0\),\(${OURTARGET}-$$0\),g" $$*' --

post-patch:
#
# Patch and rename info files
#
	@${FIXREFS} as ${WRKSRC}/gas/doc/as.texinfo \
		${WRKSRC}/gas/doc/Makefile.in
	@${FIXREFS} bfd ${WRKSRC}/bfd/doc/bfd.texinfo \
		${WRKSRC}/bfd/doc/Makefile.in
	@${FIXREFS} binutils ${WRKSRC}/binutils/doc/binutils.texi \
		${WRKSRC}/binutils/doc/Makefile.in
	@${FIXREFS} ld ${WRKSRC}/ld/ld.texinfo \
		${WRKSRC}/ld/Makefile.in
	@${FIXREFS} gprof ${WRKSRC}/gprof/gprof.texi \
		${WRKSRC}/gprof/Makefile.in

	@${MV} ${WRKSRC}/gas/doc/as.texinfo \
		${WRKSRC}/gas/doc/${OURTARGET}-as.texinfo
	@${MV} ${WRKSRC}/bfd/doc/bfd.texinfo \
		${WRKSRC}/bfd/doc/${OURTARGET}-bfd.texinfo
	@${MV} ${WRKSRC}/binutils/doc/binutils.texi \
		${WRKSRC}/binutils/doc/${OURTARGET}-binutils.texi
	@${MV} ${WRKSRC}/ld/ld.texinfo \
		${WRKSRC}/ld/${OURTARGET}-ld.texinfo
	@${MV} ${WRKSRC}/gprof/gprof.texi \
		${WRKSRC}/gprof/${OURTARGET}-gprof.texi

	@${RM} ${WRKSRC}/etc/*.info ${WRKSRC}/etc/*.texi

#
# Disable install target in some directories
#
	@${REINPLACE_CMD} -E -e 's,^(install:).*,\1,' \
		${WRKSRC}/etc/Makefile.in \
		${WRKSRC}/libiberty/Makefile.in \
		${WRKSRC}/opcodes/Makefile.in

post-install:
#
# Add some plist items (we don't list them directly, since the set varies
# across different targets)
#
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${OURTARGET} ! -type d | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${OURTARGET} -type d | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
