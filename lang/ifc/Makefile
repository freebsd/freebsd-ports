# New ports collection makefile for:    ifc
# Date created:         Oct 30, 2001
# Whom:                 chat95@mbox.kyoto-inet.or.jp
#
# $FreeBSD$
#

PORTNAME=	ifc
PORTVERSION=	6.0.159
PORTREVISION=	2
CATEGORIES=	lang devel emulators linux
MASTER_SITES=#
DISTNAME=	l_fc_pu_6.0.159
EXTRACT_SUFX=	.tar

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio \
		${LINUXBASE}/usr/bin/cc:${PORTSDIR}/devel/linux_devtools-7

RESTRICTED=	Intel forbids any redistribution
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=	i386

USE_LINUX=		yes
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes

IFC_SITE=	http://www.intel.com/software/products/compilers/

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"Please manually download ${DISTFILES} from ${IFC_SITE}, e.g. from ${IFC_SITE}f60l/noncom.htm or from https://premier.intel.com/. Registration is required!! Put it into ${DISTDIR} and run make again."
.endif

post-extract:
.for i in \
	intel-ifc6-6.0-159.i386.rpm \
#	intel-ildb6-6.0-229.i386.rpm \
#	intel-efc6-6.0-159.ia64.rpm \
#	intel-eldb6-6.0-229.ia64.rpm
	@cd ${WRKSRC}; rpm2cpio ${i} | cpio -idu --quiet
.endfor

pre-patch:
# Allow everyone to use it
	@${CHMOD} a+rx ${WRKSRC}/opt
# Remove unneded/unsafe access rights
.for i in docs ia32/include ia32/lib
	@${FIND} ${WRKSRC}/opt/intel/compiler60/${i} -type f -print0 | \
		xargs -0 ${CHMOD} a-x,g-w
.endfor
	@${FIND} ${WRKSRC}/opt -type d -print0 | xargs -0 ${CHMOD} go-w
# Use the Linux ABI for the binaries
.for i in INTEL f90com fpp icid ifcbin ifccem lmgrd.intel lmutil profmerge proforder xiar xild
	@brandelf -t Linux ${WRKSRC}/opt/intel/compiler60/ia32/bin/${i}
.endfor

post-patch:
# Correct some paths and patch some files
	@${RM} ${WRKSRC}/opt/intel/compiler60/ia32/bin/ifc.orig
.for i in ia32/bin/ifcvars.csh ia32/bin/ifcvars.sh \
	ia32/bin/ifc docs/fsupport
	@${SED} 's+\<INSTALLDIR\>+${PREFIX}/intel+g; s+man -w+manpath+g; s+@LINUXBASE@+${LINUXBASE}+g; s+/bin/sh+${LINUXBASE}/bin/bash+g; s+\<INSTALLTIMECOMBOPACKAGEID\>+${DISTNAME}+g' \
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
