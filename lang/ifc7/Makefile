# New ports collection makefile for:	ifc
# Date created:				Oct 30, 2001
# Whom:					chat95@mbox.kyoto-inet.or.jp
#
# $FreeBSD$
#

PORTNAME=	ifc
PORTVERSION=	6.0.140
CATEGORIES=	lang linux
MASTER_SITES=	http://developer.intel.com/software/products/compilers/downloads/l_fc_p_6.0.140.htm
DISTNAME=	l_fc_p_6.0.140
EXTRACT_SUFX=	.tar

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

RUN_DEPENDS=	${LINUXBASE}/lib/libc-2.2.2.so:${PORTSDIR}/emulators/linux_base
BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio \
		${LINUXBASE}/usr/bin/cc:${PORTSDIR}/devel/linux_devtools-7

RESTRICTED=	"Redistribution not allowed"
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=	i386

#USE_LINUX=		yes
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE= "Please manually download the version for RedHat 7.1 from ${MASTER_SITES}, e.g. from http://developer.intel.com/software/products/compilers/f60l/noncom.htm. Put it into ${DISTDIR} and run make again."
.endif

post-extract:
.for i in \
	intel-ifc6-6.0-140.i386.rpm  \
#	intel-ildb6-6.0-191.i386.rpm \
#	intel-efc6-6.0-140.ia64.rpm \
#	intel-eldb6-6.0-191.ia64.rpm
	@cd ${WRKSRC}; rpm2cpio ${i} | cpio -idu --quiet
.endfor

pre-patch:
	@${CHMOD} a+rx ${WRKSRC}/opt
.for i in docs ia32/include ia32/lib
	@${FIND} ${WRKSRC}/opt/intel/compiler60/${i} -type f -print0 | \
		xargs -0 ${CHMOD} a-x,g-w
.endfor
	@${FIND} ${WRKSRC}/opt -type d -print0 | xargs -0 ${CHMOD} go-w
.for i in INTEL f90com fpp icid ifcbin ifccem lmgrd.intel lmutil profmerge proforder xiar xild
	@brandelf -t Linux ${WRKSRC}/opt/intel/compiler60/ia32/bin/${i}
.endfor

post-patch:
.for i in ia32/bin/ifcvars.csh ia32/bin/ifcvars.sh \
	ia32/bin/ifc ia32/bin/ifc.pcl
	@${SED} 's@\<INSTALLDIR\>@${PREFIX}/intel@g; s@-tp p6@@; s@man -w@manpath@ ; s@/bin/sh@${LINUXBASE}/bin/sh@' \
		${WRKSRC}/opt/intel/compiler60/${i} \
		>${WRKSRC}/opt/intel/compiler60/${i}.seded
	@${MV} -f ${WRKSRC}/opt/intel/compiler60/${i}.seded \
		${WRKSRC}/opt/intel/compiler60/${i}
	@${CHMOD} 755 ${WRKSRC}/opt/intel/compiler60/${i}
.endfor
.if defined(NOPORTDOCS)
	@${RM} -rf ${WRKSRC}/opt/intel/compiler60/docs
.endif

do-install:
	@cd ${WRKSRC}/opt && ${TAR} -chf - . | \
		${TAR} -xf - -C ${PREFIX}

post-install:
	@${ECHO_CMD} "${PKGNAME} is now installed in ${PREFIX}/intel, to use it you have to"
	@${ECHO_CMD} "source the appropriate ${PREFIX}/intel/compiler60/ia32/bin/ifcvars.{,c}sh"
	@${ECHO_CMD} "script and put your license into your \$${INTEL_FLEXLM_LICENSE} (default:"
	@${ECHO_CMD} "${PREFIX}/intel/licenses) directory."

.include <bsd.port.post.mk>
