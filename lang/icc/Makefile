# Created by: netchild@FreeBSD.org
# $FreeBSD$

PORTNAME=	icc
PORTVERSION=	8.1.038
PORTREVISION=	2
CATEGORIES=	lang linux devel
MASTER_SITES=	#empty
DISTNAME=	l_cc_pc_${PORTVERSION:C/p.+$//}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

# netchild@FreeBSD.org is willing to review patches and to provide background
# infos regarding this port
MAINTAINER=	cpm@fbsd.es
COMMENT=	Intels C/C++ compiler, set up to produce native FreeBSD binaries

LICENSE=	EPL LGPL21
LICENSE_COMB=	multi

EXTRACT_DEPENDS=	rpm2cpio.pl:archivers/rpm2cpio

RESTRICTED=	Intel forbids any redistribution.

USES=		linux
USE_LINUX=	base

PATCHLEVEL=	${PORTVERSION:C/(.+p)(.+)$/pe\2/}
.if ${PORTVERSION} != ${PATCHLEVEL}
DISTFILES+=	${DISTNAME} ${PATCHLEVEL}${EXTRACT_SUFX}
USE_LINUX+=	base:patch
.endif

ONLY_FOR_ARCHS=	i386

USE_LDCONFIG=	yes

COMPILERDIR=	intel_cc_80
PLIST_SUB=	COMPILERDIR=${COMPILERDIR}
PATCH_WRKSRC=	${WRKSRC}/opt/${COMPILERDIR}

OPTIONS_DEFINE=	DOCS

DOCS=	BEA_License_Agreement.txt Disclaimer.txt flex_ug.pdf
ICC_SITE=	https://software.intel.com/en-us/intel-compilers/

SUB_FILES=	pkg-message
SUB_LIST+=	PKGNAME=${PKGNAME} \
		COMPILERDIR=${COMPILERDIR} \
		MAINTAINER=${MAINTAINER}

.include <bsd.port.pre.mk>

EXTRACT_AFTER_ARGS=	--exclude cdt-\*.zip \
			--exclude eclipse-platform\*.zip \
			--exclude intel-icc_ide\*.rpm \
			--exclude intel-iidb\*.rpm \
			--exclude intel-isubh\*.rpm \
			--exclude sdp-core-\*.zip \
			--exclude \*ia64.rpm \
			--exclude flexlm64

ICCCFGVAL_CMD=	${UNAME} -r | ${SED} -e 's/\..*//'

GCCCOMPATVER=	340
GXXINCLUDE=	/usr/include/c++/${GCCCOMPATVER:C/([0-9])([0-9]).+/\1.\2/}

.for f in ${DISTFILES}
.if !exists(${DISTDIR}/${f})
IGNORE=	go to Intel Premier Support \(https://premier.intel.com/\) to obtain ${DISTFILES}. Product updates such as this compiler are posted regularly on Premier Support. You must have a license to obtain access to Premier Support. If you do not already have a license go to ${ICC_SITE} to review licensing options \(evaluation, commercial, and free non-commercial\) and obtain a license. Put ${DISTFILES} into ${DISTDIR} and run make again
.endif
.endfor

.if exists(${LINUXBASE}/boot/kernel.h)
BROKEN=	cannot coexist with linux_devtools
.endif

post-extract:
	cd ${WRKSRC} && rpm2cpio.pl 2>/dev/null *.rpm | ${CPIO} -idu --quiet

intel-patch: extract
# Apply patches from Intel.
.if ${PORTVERSION} != ${PATCHLEVEL}
	${BRANDELF} -t Linux ${WRKSRC}_${PATCHLEVEL}/papply
	${WRKSRC}_${PATCHLEVEL}/papply ${WRKSRC}_${PATCHLEVEL}/icc.rtp \
		${WRKSRC}/opt/${COMPILERDIR}
.endif

pre-patch: intel-patch
# Remove files we do not need on FreeBSD.
	for i in `${CAT} ${FILESDIR}/exclude`; do \
		${RM} -r ${WRKSRC}/opt/${COMPILERDIR}/$$i; done
.if ! ${PORT_OPTIONS:MDOCS}
# Remove docs.
	for i in `${CAT} ${FILESDIR}/exclude_noportdocs`; do \
		${RM} -r ${WRKSRC}/opt/${COMPILERDIR}/$$i; done
.endif
# Remove unneeded/unsafe access rights.
.for i in doc include lib
	${FIND} ${WRKSRC}/opt/${COMPILERDIR}/${i} -type f -print0 | \
		${XARGS} -0 ${CHMOD} a-x,og-w
.endfor
	${FIND} ${WRKSRC}/opt -type d -print0 | ${XARGS} -0 ${CHMOD} go-w
	${CHMOD} a-x ${WRKSRC}/opt/${COMPILERDIR}/bin/Errormatch.txt

post-patch:
# Correct some paths and patch some files
.for i in icc iccvars.csh iccvars.sh icpc
	${REINPLACE_CMD} -i "" -e 's:%%ICC_LOCALBASE%%:${LOCALBASE}:g; \
		s:\<INSTALLDIR\>:${PREFIX}/${COMPILERDIR}:g; \
		s:%%GXX_INCLUDE%%:${GXXINCLUDE}:g; \
		s:man -w:manpath -q:g' ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
	${CHMOD} 755 ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
.if ${PORTVERSION} != ${PATCHLEVEL}
	${REINPLACE_CMD} -i "" -e \
		's:\<installpackageid\>:${DISTNAME}_${PATCHLEVEL}:g' \
		${WRKSRC}/opt/${COMPILERDIR}/doc/csupport
.else
	${REINPLACE_CMD} -i "" -e 's:\<installpackageid\>:${DISTNAME}:g' \
		${WRKSRC}/opt/${COMPILERDIR}/doc/csupport
.endif
	${RM} ${WRKSRC}/opt/${COMPILERDIR}/include/*.orig
	${RM} ${WRKSRC}/opt/${COMPILERDIR}/include/c++/*.orig
.for i in icc.orig icpc.orig
	${RM} ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
# Provide a more FreeBSD'ish compile environment
.for i in icc.cfg icpc.cfg
	${ECHO_CMD} -e "-Qlocation,ld,${PREFIX}/${COMPILERDIR}/bin/ldwrapper\n\n-wr1125\n-we140\n\n-Ulinux\n-U__linux__\n-U__linux\n-U__gnu_linux__\n\n-D__FreeBSD__=$$(${ICCCFGVAL_CMD})\n\n" >>${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
	${ECHO_CMD} -e "-D__wchar_t=__ct_rune_t\n" >>${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
	${ECHO_CMD} -e "-restrict\n" >>${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
	${CHMOD} a-x,g-w ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
# C++ hack for icpc
	${ECHO_CMD} -e "-gcc-version=${GCCCOMPATVER}\n-cxxlib-gcc\n" \
		>>${WRKSRC}/opt/${COMPILERDIR}/bin/icpc.cfg
	cd ${WRKSRC}/opt/${COMPILERDIR}/bin/ && ${LN} -s icc.cfg iccbin.cfg \
		&& ${LN} -s icpc.cfg icpcbin.cfg

OBJCOPY_OPS=	--redefine-sym stdin=__stdinp \
		--redefine-sym stdout=__stdoutp \
		--redefine-sym stderr=__stderrp

do-build:
# Use the Linux ABI for the binaries
.for i in codecov iccbin iccfilt icpcbin icpi mcpcom prelink profmerge \
	proforder profrun pronto_tool tselect xiar xild
	${BRANDELF} -t Linux ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
# Fix unresolved references
	cd ${WRKSRC} && ${CC} ${CFLAGS} -c ${FILESDIR}/assert_fail.c \
		${FILESDIR}/errno_location.c ${FILESDIR}/mcount.S
.for i in libcxa.a libcxaguard.a libimf.a libirc.a libirc_s.a libsvml.a \
	libunwind.a
	${OBJCOPY} --redefine-sym __sigsetjmp=sigsetjmp \
		${OBJCOPY_OPS} \
		${WRKSRC}/opt/${COMPILERDIR}/lib/${i}
.endfor
	${AR} cr ${WRKSRC}/opt/${COMPILERDIR}/lib/libiccfbsd.a ${WRKSRC}/*.o
# Some magic to be able to link
	${MKDIR} ${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper
	${CC} ${CFLAGS} -o \
		${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper/ld \
		${FILESDIR}/ld.c
	${STRIP_CMD} ${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper/ld
	${CHMOD} 755 ${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper/ld
# Make ICC happy with regards to crtbegin.o, crtend.o and libgcc.a which it
# expects to find in GXX_ROOT.
.for f in crtbegin.o crtend.o libgcc.a
	cd ${WRKSRC}/opt/${COMPILERDIR}/lib && ${LN} -s /usr/lib/${f} ${f}
.endfor
# The static linking case expects a crtbeginT.o. Based upon inspection of
# /usr/src/contrib/gnu/crtstuff.c it seems it's the same as crtbegin.o.
	cd ${WRKSRC}/opt/${COMPILERDIR}/lib && ${LN} -s crtbegin.o crtbeginT.o

do-install:
	cd ${WRKSRC}/opt && ${FIND} . -print | \
		${CPIO} -pdu --quiet ${STAGEDIR}${PREFIX}

	${MV} ${STAGEDIR}${PREFIX}/${COMPILERDIR}/man/man1/icc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${RM} -r ${STAGEDIR}${PREFIX}/${COMPILERDIR}/man

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/${COMPILERDIR}/doc/* ${STAGEDIR}${DOCSDIR}
	${RM} -r ${STAGEDIR}${PREFIX}/${COMPILERDIR}/doc
.else
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/${COMPILERDIR}/doc/* ${STAGEDIR}${DOCSDIR}
	${RM} -r ${STAGEDIR}${PREFIX}/${COMPILERDIR}/doc
.endif

.include <bsd.port.post.mk>
