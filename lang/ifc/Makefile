# New ports collection makefile for:    ifc
# Date created:         Oct 30, 2001
# Whom:                 chat95@mbox.kyoto-inet.or.jp
#
# $FreeBSD$
#

PORTNAME=	ifc
PORTVERSION=	8.0.039
CATEGORIES=	lang linux devel
MASTER_SITES=
DISTNAME=	l_fc_pc_${PORTVERSION:C/\.p.+$//}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Intel's Fortran compiler, set up to produce native FreeBSD binaries

PATCHLEVEL=	${PORTVERSION:C/(.+p)(.+)$/pe\2/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.if ${PORTVERSION} != ${PATCHLEVEL}
DISTFILES+=	${DISTNAME}_${PATCHLEVEL}${EXTRACT_SUFX}
.endif

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

RESTRICTED=	Intel forbids any redistribution
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=		i386
CONFLICTS=		linux_devtools*

USE_LINUX=		yes
USE_REINPLACE=		yes
NO_FILTER_SHLIBS=	yes

COMPILERDIR=	intel_fc_80
PLIST_SUB=	COMPILERDIR=${COMPILERDIR}
PATCH_WRKSRC=	${WRKSRC}/opt/${COMPILERDIR}

MAN1=		ifc.1 ifort.1
MANPREFIX=	${PREFIX}/${COMPILERDIR}/

IFC_SITE=	http://www.intel.com/software/products/compilers/

.include <bsd.port.pre.mk>

EXTRACT_AFTER_ARGS=	| tar -xf - \
			--exclude intel-isubh\*.rpm \
			--exclude \*ia64.rpm \
			--exclude chklic.64 \
			--exclude flexlm64

IFCCFGVAL!=	${UNAME} -r | ${SED} -e 's/\..*//'

BRANDELF?=	/usr/bin/brandelf
OBJCOPY?=	/usr/bin/objcopy

.for file in ${DISTFILES}
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${file})
IGNORE=	"Go to Intel Premier Support, https://premier.intel.com, to obtain ${DISTFILES}. Product updates such as this compiler are posted regularly on Premier Support. You must have a license to obtain access to Premier Support. If you do not already have a license go to ${IFC_SITE} to review licensing options \(evaluation, commercial, and free non-commercial\) and obtain a license. Put ${DISTFILES} into ${DISTDIR} and run make again"
.endif
.endfor

.if exists(${LINUXBASE}/boot/kernel.h)
BROKEN=	Cannot coexist with linux_devtools
.endif

post-extract:
.for i in \
	intel-ifort8-8.0-47.i386.rpm
#	intel-iidb7-7.3.2-98.i386.rpm
	@cd ${WRKSRC} && rpm2cpio.pl 2>/dev/null ${i} | ${CPIO} -idu --quiet
.endfor

pre-patch:
# Apply patches from Intel.
.if ${PORTVERSION} != ${PATCHLEVEL}
	@${BRANDELF} -t Linux ${WRKSRC}_${PATCHLEVEL}/papply
	@${WRKSRC}_${PATCHLEVEL}/papply ${WRKSRC}_${PATCHLEVEL}/ifort.rtp \
		${WRKSRC}/opt/${COMPILERDIR}
.endif
# Remove files we do not need on FreeBSD.
	@for i in `${CAT} ${FILESDIR}/exclude`; do \
		${RM} -rf ${WRKSRC}/opt/${COMPILERDIR}/$$i; \
	done
.if defined(NOPORTDOCS)
# Remove docs.
	@for i in `${CAT} ${FILESDIR}/exclude_noportdocs`; do \
		${RM} -rf ${WRKSRC}/opt/${COMPILERDIR}/$$i; \
	done
.endif
# Allow everyone to use it.
	@${CHMOD} a+rx ${WRKSRC}/opt
# Remove unneeded/unsafe access rights.
.for i in doc include lib
	@${FIND} ${WRKSRC}/opt/${COMPILERDIR}/${i} -type f -print0 | \
		${XARGS} -0 ${CHMOD} a-x,g-w
.endfor
	@${FIND} ${WRKSRC}/opt -type d -print0 | ${XARGS} -0 ${CHMOD} go-w

post-patch:
# Correct some paths and patch some files
.for i in ifc ifort ifortvars.csh ifortvars.sh ifc.cfg ifort.cfg
	@${REINPLACE_CMD} -i "" -e 's:%%ICC_LOCALBASE%%:${LOCALBASE}:g; \
		s:\<INSTALLDIR\>:${PREFIX}/${COMPILERDIR}:g; \
		s:man -w:manpath -q:g' ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
	@${CHMOD} 755 ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
.if ${PORTVERSION} != ${PATCHLEVEL}
	@${REINPLACE_CMD} -i "" -e \
		's:\<installpackageid\>:${DISTNAME}_${PATCHLEVEL}:g' \
		${WRKSRC}/opt/${COMPILERDIR}/doc/fsupport
.else
	@${REINPLACE_CMD} -i "" -e 's:\<installpackageid\>:${DISTNAME}:g' \
		${WRKSRC}/opt/${COMPILERDIR}/doc/fsupport
.endif
.for i in ifc.orig ifort.orig
	@${RM} -f ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
# Provide a more FreeBSD'ish compile environment
.for i in ifc.cfg ifort.cfg
	@${ECHO_CMD} -e "-no-gcc\n-Qlocation,ld,${PREFIX}/${COMPILERDIR}/bin/ldwrapper\n-nothreads\n\n-D__FreeBSD__=${IFCCFGVAL}\n\n" >>${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
	@${CHMOD} a-x,g-w ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
	@cd ${WRKSRC}/opt/${COMPILERDIR}/bin/ && ${LN} -s ifc.cfg ifcbin.cfg \
		&& ${LN} -s ifort.cfg ifortbin.cfg
# Remove macros for linux in ifortbin,
# because fortcom does not accept -U option.
	@${REINPLACE_CMD} -i "" -e 's: -Dlinux:        :'                 \
				-e 's: -D__linux :           :'           \
				-e 's: -D__linux__ :             :'       \
				-e 's: -D__gnu_linux__:                :' \
		${WRKSRC}/opt/${COMPILERDIR}/bin/ifortbin

.if ( ${OSVERSION} >= 470101 && ${OSVERSION} < 500000 ) || \
	( ${OSVERSION} >= 500042 )
OBJCOPY_OPS=	--redefine-sym stdin=__stdinp \
		--redefine-sym stdout=__stdoutp \
		--redefine-sym stderr=__stderrp
.endif

do-build:
# Use the Linux ABI for the binaries 
.for i in codecov fortcom fpp ifcbin ifortbin profmerge proforder tselect xiar xild
	@${BRANDELF} -t Linux ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
# Fix unresolved references
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -c ${FILESDIR}/assert_fail.c \
		${FILESDIR}/linux_file.c ${FILESDIR}/linux_stat.c \
		${FILESDIR}/sysconf.c    \
		${FILESDIR}/errno_location.c ${FILESDIR}/mcount.S
.if ( ${OSVERSION} < 502101 )
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -c ${FILESDIR}/cxa_atexit.c
.endif
.if ( ${OSVERSION} < 470101 ) || \
	( ${OSVERSION} >= 500000 && ${OSVERSION} < 500042 )
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stdin.o ${FILESDIR}/stdin.c
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stdout.o ${FILESDIR}/stdout.c
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stderr.o ${FILESDIR}/stderr.c
.endif
.for i in libcprts.a libcxa.a libifcore.a libifcoremt.a libifport.a libimf.a libirc.a libircmt.a libunwind.a
	@${OBJCOPY} --redefine-sym __sigsetjmp=sigsetjmp \
		${OBJCOPY_OPS} \
		${WRKSRC}/opt/${COMPILERDIR}/lib/${i}
.endfor
.for i in ifcore ifcoremt ifport
	@${OBJCOPY} --strip-symbol=stat \
		--strip-symbol=fstat \
		--strip-symbol=lstat \
		--redefine-sym open=l_open \
		--redefine-sym lseek=l_lseek \
		${WRKSRC}/opt/${COMPILERDIR}/lib/lib${i}.a
.endfor
.for i in ifcore ifcoremt
	@${OBJCOPY} \
		--redefine-sym ftruncate=l_ftruncate \
		--redefine-sym __xpg_basename=basename \
		--redefine-sym __strtod_internal=strtod \
		--redefine-sym __strtof_internal=strtof \
		--redefine-sym __strtol_internal=strtol \
		--redefine-sym __strtold_internal=strtold \
		--redefine-sym __strtoll_internal=strtoll \
		--redefine-sym __strtoul_internal=strtoul \
		--redefine-sym __strtoull_internal=strtoull \
		${WRKSRC}/opt/${COMPILERDIR}/lib/lib${i}.a
.endfor
	@${AR} q ${WRKSRC}/opt/${COMPILERDIR}/lib/libcxa.a ${WRKSRC}/*.o
	@cd ${WRKSRC} && ${AR} x /usr/lib/libcompat.a ftime.o
	@${AR} q ${WRKSRC}/opt/${COMPILERDIR}/lib/libifport.a ${WRKSRC}/ftime.o
# Some magic to be able to link
	@${MKDIR} ${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper
	@${CC} ${CFLAGS} -o \
		${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper/ld \
		${FILESDIR}/ld.c
	@${STRIP_CMD} ${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper/ld
	@${CHMOD} 755 ${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper/ld

do-install:
	@cd ${WRKSRC}/opt && ${FIND} . -print | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${PREFIX}

post-install:
	@${ECHO_CMD} "${PKGNAME} is now installed in ${PREFIX}/${COMPILERDIR}, to use it you have to"
	@${ECHO_CMD} "put your license into your \$${INTEL_FLEXLM_LICENSE} (default:"
	@${ECHO_CMD} "${PREFIX}/${COMPILERDIR}/licenses) directory and add"
	@${ECHO_CMD} "${PREFIX}/${COMPILERDIR}/bin to your PATH."
	@${ECHO_CMD}
	@${ECHO_CMD} "If you use ifc on a Pentium 4 make sure you have 'options CPU_ENABLE_SSE'"
	@${ECHO_CMD} "in your kernel config (have a look at http://www.FreeBSD.org/handbook/"
	@${ECHO_CMD} "if you do not know how to do this), else ifc will hang forever."
	@${ECHO_CMD}
	@${ECHO_CMD} "WARNING: If you use ifc while having linux_devtools installed, ifc will use"
	@${ECHO_CMD} "the wrong includes and therefore will generate bogus (not working) binaries!"
	@${ECHO_CMD}
	@${ECHO_CMD} "If you encounter further problems with ifc please consult the errata at"
	@${ECHO_CMD} "http://support.intel.com/support/performancetools/fortran/Fortran_Compiler_Errata.htm"
	@${ECHO_CMD} "first."

.include <bsd.port.post.mk>
