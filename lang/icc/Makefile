# New ports collection makefile for:	icc
# Date created:         24.Jan.2002
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	icc
PORTVERSION=	7.0.078
PORTREVISION=	1
CATEGORIES=	lang linux devel
MASTER_SITES=
DISTNAME=	l_cc_pu_${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	netchild@FreeBSD.org

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

MAN1=		icc.1
MANPREFIX=	${PREFIX}/intel/${COMPILERDIR}/

ICC_SITE=	http://www.intel.com/software/products/compilers/

.include <bsd.port.pre.mk>

ICCCFGVAL!=	${UNAME} -r | ${SED} -e 's/\..*//'

OBJCOPY?=	/usr/bin/objcopy

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"Please manually download ${DISTFILES} from ${ICC_SITE}, ${ICC_SITE}clin/noncom.htm or https://premier.intel.com/ \(whichever has the file, to access premier.intel.com you have to register at http://www.intel.com/software/products/registrationcenter/index.htm\). With a little bit of luck it may also be available from ftp://download.intel.com/software/products/compilers/downloads/. Put it into ${DISTDIR} and run make again"
.endif

.if exists(${LINUXBASE}/boot/kernel.h) || \
	exists(${PREFIX}/intel/compiler60/bin/ifc) || \
	exists(${PREFIX}/intel/compiler70/bin/ifc)
BROKEN=	Cannot coexist with linux_devtools or ifc
.endif

post-extract:
	@${SED} 's:%%COMPILERDIR%%:${COMPILERDIR}:' ${FILESDIR}/cpio-exclude \
		>${WRKDIR}/cpio-exclude
.if defined(NOPORTDOCS)
	@${SED} 's:%%COMPILERDIR%%:${COMPILERDIR}:' \
		${FILESDIR}/cpio-exclude_noportdocs >>${WRKDIR}/cpio-exclude
.endif
.for i in \
	intel-icc7-7.0-78.i386.rpm
#	intel-ildb7-7.0-156.i386.rpm \
#	intel-isubh7-7.0-78.i386.rpm \
#	intel-ecc7-7.0-78.ia64.rpm \
#	intel-eldb7-7.0-156.ia64.rpm \
#	intel-esubh7-7.0-78.ia64.rpm
	@cd ${WRKSRC} && rpm2cpio 2>/dev/null ${i} | \
		cpio -idfuE ${WRKDIR}/cpio-exclude --quiet
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
	@${CHMOD} a-x ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/Errormatch.txt
# Use the Linux ABI for the binaries
.for i in iccbin iccfilt icid icpcbin icpi mcpcom profmerge proforder xiar xild
	@brandelf -t Linux ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endfor

post-patch:
# Correct some paths and patch some files
.for i in ia32/bin/icc ia32/bin/iccvars.csh ia32/bin/iccvars.sh ia32/bin/icpc
	@${REINPLACE_CMD} -i "" -e 's:@@PREFIX@@:${PREFIX}:g; s@\<INSTALLDIR\>@${PREFIX}/intel@g; s@man -w@manpath -q@g' \
		${WRKSRC}/opt/intel/${COMPILERDIR}/${i}
	@${CHMOD} 755 ${WRKSRC}/opt/intel/${COMPILERDIR}/${i}
.endfor
	@${REINPLACE_CMD} -i "" -e 's:\<INSTALLTIMECOMBOPACKAGEID\>:${DISTNAME}:g' \
		${WRKSRC}/opt/intel/${COMPILERDIR}/docs/csupport
	@${RM} ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/include/*.orig
.for i in icc.orig icpc.orig
	@${RM} ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endfor
# Provide a more FreeBSD'ish compile environment
.for i in icc.cfg icpc.cfg
	@${REINPLACE_CMD} -i "" -e 's:-Xlinker -rpath -Xlinker <INSTALLDIR>/${COMPILERDIR}/ia32/lib::g' \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
	@${ECHO} -e "-Qlocation,ld,${PREFIX}/intel/${COMPILERDIR}/ia32/bin/ldwrapper\n\n-Ulinux\n-U__linux__\n-U__linux\n\n-D__FreeBSD__=${ICCCFGVAL}\n-D__ELF__=1\n" >>${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.if ${OSVERSION} >= 500039
	@${ECHO} -e "-D__wchar_t=__ct_rune_t\n" >>${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endif
	@${CHMOD} a-x,g-w ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endfor
# C++ hack for icpc
	@${ECHO} -e "\n-I${PREFIX}/include/stlport\n-Qoption,ld,-CPLUSPLUS\n" >>${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/icpc.cfg
	@cd ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ && ${LN} -s icc.cfg iccbin.cfg && ${LN} -s icpc.cfg icpcbin.cfg
# Hack while there's no support for icc in the stdarg.h of FreeBSD.
	@${CP} ${FILESDIR}/stdarg.h ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/include

do-build:
# Fix unresolved references
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -c ${FILESDIR}/assert_fail.c \
		${FILESDIR}/cxa_atexit.c ${FILESDIR}/cxa_finalize.c \
		${FILESDIR}/errno_location.c ${FILESDIR}/mcount.S
.if ( ${OSVERSION} < 470101 ) || \
	( ${OSVERSION} >= 500000 && ${OSVERSION} < 500042 )
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stdin.o ${FILESDIR}/stdin.c
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stdout.o ${FILESDIR}/stdout.c
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stderr.o ${FILESDIR}/stderr.c
.else
.for i in libcxa.a libimf.a libirc.a libircmt.a libompstub.a libunwind.a
	@${OBJCOPY} --redefine-sym stdin=__stdinp \
		--redefine-sym stdout=__stdoutp \
		--redefine-sym stderr=__stderrp \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/lib/${i}
.endfor
.endif
	@${AR} q ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/lib/libcxa.a ${WRKSRC}/*.o
# Some magic to be able to link
	@${MKDIR} ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper
	@${CC} ${CFLAGS} -o \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper/ld \
		${FILESDIR}/ld.c
	@${STRIP_CMD} ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper/ld
	@${CHMOD} 755 ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper/ld

do-install:
	@cd ${WRKSRC}/opt && find . | cpio -pdu -R ${BINOWN}:${BINGRP} ${PREFIX}

post-install:
	@${ECHO_CMD} "${PKGNAME} is now installed in ${PREFIX}/intel, to use it you have to"
	@${ECHO_CMD} "put your license into your \$${INTEL_FLEXLM_LICENSE} (default:"
	@${ECHO_CMD} "${PREFIX}/intel/licenses) directory and add"
	@${ECHO_CMD} "${PREFIX}/intel/${COMPILERDIR}/ia32/bin to your PATH."
	@${ECHO_CMD}
	@${ECHO_CMD} "In order to be able to compile C++ source with icpc you have to install"
	@${ECHO_CMD} "devel/stlport-icc. (It is a good idea to run 'rehash' before or stlport-icc"
	@${ECHO_CMD} "probably won't find the compiler.)"
	@${ECHO_CMD}
	@${ECHO_CMD} "If you use icc on a Pentium 4 make sure you have 'options CPU_ENABLE_SSE'"
	@${ECHO_CMD} "in your kernel config (have a look at http://www.FreeBSD.org/handbook/"
	@${ECHO_CMD} "if you do not know how to do this), else icc will hang forever."
	@${ECHO_CMD}
	@${ECHO_CMD} "WARNING: If you use icc while having linux_devtools installed, icc will use"
	@${ECHO_CMD} "the wrong includes and therefore will generate bogus (not working) binaries!"

.include <bsd.port.post.mk>
