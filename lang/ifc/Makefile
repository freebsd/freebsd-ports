# New ports collection makefile for:    ifc
# Date created:         Oct 30, 2001
# Whom:                 chat95@mbox.kyoto-inet.or.jp
#
# $FreeBSD$
#

PORTNAME=	ifc
PORTVERSION=	7.1.033
CATEGORIES=	lang linux devel
MASTER_SITES=
DISTNAME=	l_fc_pc_${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Intel's Fortran compiler, set up to produce native FreeBSD objects

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio

RESTRICTED=	Intel forbids any redistribution
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=		i386

USE_LINUX=		yes
USE_REINPLACE=		yes
NO_WRKSUBDIR=		yes
NO_FILTER_SHLIBS=	yes

COMPILERDIR=	compiler70
PLIST_SUB=	COMPILERDIR=${COMPILERDIR}
PATCH_WRKSRC=	${WRKSRC}/opt/intel/${COMPILERDIR}

MAN1=		ifc.1
MANPREFIX=	${PREFIX}/intel/${COMPILERDIR}/

IFC_SITE=	http://www.intel.com/software/products/compilers/

.include <bsd.port.pre.mk>

IFCCFGVAL!=	${UNAME} -r | ${SED} -e 's/\..*//'

CPIO?=		/usr/bin/cpio
OBJCOPY?=	/usr/bin/objcopy

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"Please manually download ${DISTFILES} from ${IFC_SITE}, ${IFC_SITE}flin/noncom.htm or https://premier.intel.com/ \(whichever has the file, to access premier.intel.com you have to register at http://www.intel.com/software/products/registrationcenter/index.htm\). With a little bit of luck it may also be available from ftp://download.intel.com/software/products/compilers/downloads/. Put it into ${DISTDIR} and run make again"
.endif

.if exists(${LINUXBASE}/boot/kernel.h) #|| \
#	exists(${PREFIX}/intel/compiler60/bin/icc) || \
#	exists(${PREFIX}/intel/compiler70/bin/icc)
BROKEN=	Cannot coexist with linux_devtools or icc
.endif

post-extract:
	@${SED} 's:%%COMPILERDIR%%:${COMPILERDIR}:' ${FILESDIR}/cpio-exclude \
		>${WRKDIR}/cpio-exclude
.if defined(NOPORTDOCS)
	@${SED} 's:%%COMPILERDIR%%:${COMPILERDIR}:' \
		${FILESDIR}/cpio-exclude_noportdocs >>${WRKDIR}/cpio-exclude
.endif
.for i in \
	intel-ifc7-7.1-34.i386.rpm
#	intel-iidb7-7.2.2-64.i386.rpm \
#	intel-efc7-7.1-34.ia64.rpm \
#	intel-eidb7-7.2.2-64.ia64.rpm
	@cd ${WRKSRC} ; rpm2cpio 2>/dev/null ${i} | \
		${CPIO} -idfuE ${WRKDIR}/cpio-exclude --quiet
.endfor

pre-patch:
# Allow everyone to use it
	@${CHMOD} a+rx ${WRKSRC}/opt
# Remove unneeded/unsafe access rights
.for i in docs ia32/include ia32/lib
	@${FIND} ${WRKSRC}/opt/intel/${COMPILERDIR}/${i} -type f -print0 | \
		xargs -0 ${CHMOD} a-x,g-w
.endfor
	@${FIND} ${WRKSRC}/opt -type d -print0 | xargs -0 ${CHMOD} go-w
# Use the Linux ABI for the binaries
.for i in ifcbin fpp icid f90com profmerge proforder xiar xild
	@brandelf -t Linux ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endfor

post-patch:
# Correct some paths and patch some files
.for i in ia32/bin/ifc ia32/bin/ifcvars.csh ia32/bin/ifcvars.sh
	@${REINPLACE_CMD} -i "" -e 's:@@PREFIX@@:${PREFIX}:g; s@\<INSTALLDIR\>@${PREFIX}/intel@g; s@man -w@manpath -q@g' \
		${WRKSRC}/opt/intel/${COMPILERDIR}/${i}
	@${CHMOD} 755 ${WRKSRC}/opt/intel/${COMPILERDIR}/${i}
.endfor
	@${REINPLACE_CMD} -i "" -e 's:\<INSTALLTIMECOMBOPACKAGEID\>:${DISTNAME}:g' \
		${WRKSRC}/opt/intel/${COMPILERDIR}/docs/fsupport
.for i in ifc.orig
	@${RM} ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endfor
# Provide a more FreeBSD'ish compile environment
.for i in ifc.cfg
	@${REINPLACE_CMD} -i "" -e 's:-Xlinker -rpath -Xlinker <INSTALLDIR>/${COMPILERDIR}/ia32/lib::g' \
		-e 's@\<INSTALLDIR\>@${PREFIX}/intel@g;' \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
	@${ECHO} -e "-Qlocation,ld,${PREFIX}/intel/${COMPILERDIR}/ia32/bin/ldwrapper\n\n-Ulinux\n-U__linux__\n-U__linux\n-U__gnu_linux__\n\n-D__FreeBSD__=${IFCCFGVAL}\n-D__ELF__=1\n" >>${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
	@${CHMOD} a-x,g-w ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endfor
	@cd ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ && ${LN} -s ifc.cfg ifcbin.cfg

do-build:
# Fix unresolved references
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -c ${FILESDIR}/assert_fail.c \
		${FILESDIR}/cxa_atexit.c ${FILESDIR}/cxa_finalize.c \
		${FILESDIR}/linux_file.c ${FILESDIR}/sysconf.c \
		${FILESDIR}/mmap.c       ${FILESDIR}/pthread.c \
		${FILESDIR}/errno_location.c ${FILESDIR}/mcount.S
.if ( ${OSVERSION} < 470101 ) || \
	( ${OSVERSION} >= 500000 && ${OSVERSION} < 500042 )
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stdin.o ${FILESDIR}/stdin.c
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stdout.o ${FILESDIR}/stdout.c
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stderr.o ${FILESDIR}/stderr.c
.else
.for i in libcxa.a libimf.a libirc.a libircmt.a libunwind.a \
	libBINDF90.a libCEPCF90.a libF90.a libIEPCF90.a libPEPCF90.a \
	libcprts.a libintrins.a libompstub.a
	@${OBJCOPY} --redefine-sym __sigsetjmp=sigsetjmp \
		--redefine-sym stdin=__stdinp \
		--redefine-sym stdout=__stdoutp \
		--redefine-sym stderr=__stderrp \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/lib/${i}
.endfor
.endif
	@(cd ${WRKSRC}; ${AR} x /usr/lib/libcompat.a ftime.o)
	@${AR} q ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/lib/libcxa.a ${WRKSRC}/*.o
.for i in BINDF90 PEPCF90 CEPCF90 POSF90 IEPCF90
	@${OBJCOPY} --strip-symbol=stat \
		--strip-symbol=fstat \
		--strip-symbol=lstat \
		--redefine-sym lseek=Lseek \
		--redefine-sym lseek64=lseek \
		--redefine-sym open64=open \
		--redefine-sym creat64=creat \
		--redefine-sym ftruncate64=ftruncate \
		--redefine-sym mmap=Mmap \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/lib/lib${i}.a
.endfor
# Some magic to be able to link
	@${MKDIR} ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper
	@${CC} ${CFLAGS} -o \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper/ld \
		${FILESDIR}/ld.c
	@${STRIP_CMD} ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper/ld
	@${CHMOD} 755 ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper/ld

do-install:
	@cd ${WRKSRC}/opt && ${FIND} . -print | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${PREFIX}

post-install:
	@${ECHO_CMD} "${PKGNAME} is now installed in ${PREFIX}/intel, to use it you have to"
	@${ECHO_CMD} "put your license into your \$${INTEL_FLEXLM_LICENSE} (default:"
	@${ECHO_CMD} "${PREFIX}/intel/licenses) directory and add"
	@${ECHO_CMD} "${PREFIX}/intel/${COMPILERDIR}/ia32/bin to your PATH."
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
