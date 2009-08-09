# New ports collection makefile for:	sbcl
# Date created:				2002-11-26
# Whom:					des
#
# $FreeBSD$
#
# Note: If you update this port make sure you create the distfinfo for all
# versions: sbcl-1.v.v-x86-64-freebsd and sbcl-1.v.v-x86-freebsd
#

PORTNAME=	sbcl
PORTVERSION=	1.0.30.0
PORTREVISION=	0
CATEGORIES=	lang lisp
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
#		ftp://ftp.SpringDaemons.com/soft/sbcl-binary/:binaries
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/ \
		ftp://ftp.SpringDaemons.com/soft/sbcl-binary/:binaries
#MASTER_SITE_SUBDIR=	sbcl/${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-source${SBCLPATCHLEVEL}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A Common Lisp development system derived from the CMU CL system

# More platforms are supported, but on Linux.
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	is a native code compiler, and has not been ported to this architecture yet

USE_BZIP2=	yes
USE_GMAKE=	yes
CFLAGS+=	-DSBCL_HOME=\\"${PREFIX}/lib/sbcl/\\"

OPTIONS=	SBCL "Use installed SBCL binary if available" off \
		THREADS "Enable experimental threading support" off

MAN1=		sbcl.1
INFO=		asdf sbcl
INFODIR=	${PREFIX}/${INFO_PATH}

OSVER_MAJOR=	${OSVERSION:C/([0-9]).*/\1/}

.if ${PORTVERSION:E} == 0
SBCLPATCHLEVEL=	#empty
.else
SBCLPATCHLEVEL=	-r${PORTVERSION:E}
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

# Empty dirs in distribution to keep
EMPTY_DIRS=	sb-bsd-sockets/alien sb-posix/alien sb-posix/test-lab \
		site-systems

DYNAMIC_SPACE_SIZE?=	512

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	I386_ONLY=""
.else
PLIST_SUB+=	I386_ONLY="@comment "
.endif

# If WITH_SBCL is defined, try to use existing "sbcl" first.
.if defined(WITH_SBCL) && exists(${LOCALBASE}/bin/sbcl)
LISP_CMD=	""
.else
BOOT_VERSION=	1.0.17

. if make(makesum)
BOOT_ARCH_OS_LIST=	amd64-freebsd8 amd64-freebsd7 amd64-freebsd6 \
			i386-freebsd8 i386-freebsd7 i386-freebsd6
. else
BOOT_ARCH_OS_LIST=	${ARCH}-freebsd${OSVER_MAJOR}
. endif

. if ${ARCH} == "i386"
LISP_EXTRA_ARG=	--dynamic-space-size ${DYNAMIC_SPACE_SIZE}
. endif

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
. for BOOT_ARCH_OS in ${BOOT_ARCH_OS_LIST}
BOOT_DISTNAME=	${PORTNAME}-${BOOT_VERSION}-${BOOT_ARCH_OS}
DISTFILES:=	${DISTFILES} ${BOOT_DISTNAME}-binary${EXTRACT_SUFX}:binaries
. endfor
LISP_CMD=	"${WRKDIR}/${BOOT_DISTNAME}/src/runtime/sbcl --core ${WRKDIR}/${BOOT_DISTNAME}/output/sbcl.core ${LISP_EXTRA_ARG} --disable-debugger --userinit /dev/null --sysinit /dev/null"

.endif # defined(WITH_SBCL)

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG} "You might need to increase memory limits in order to"
	@${ECHO_MSG} "build SBCL."
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the DYNAMIC_SPACE_SIZE knob to tweak the size"
	@${ECHO_MSG} "of SBCL dynamically allocated memory."
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -E -e 's|(CFLAGS =) .*|\1 ${CFLAGS}|' \
		${WRKSRC}/src/runtime/GNUmakefile
	@${FIND} ${WRKSRC} -name '*.orig' -o -name '*.bak' -delete
.if defined(WITH_THREADS)
	@${CP} ${FILESDIR}/customize-target-features.lisp ${WRKSRC}
.endif

do-build:
	@(cd ${WRKSRC} && ${SETENV} INSTALL_ROOT=${PREFIX} \
		${SH} make.sh ${LISP_CMD})
	@${RM} -rf ${WRKSRC}/contrib/sb-cover/test-output
	@(cd ${WRKSRC}/doc/manual && \
		${GMAKE} MAKEINFO='makeinfo --no-split' info)

do-install:
	(cd ${WRKSRC} && ${SETENV} INSTALL_ROOT=${PREFIX} \
		MAN_DIR=${PREFIX}/man DOC_DIR=${DOCSDIR} \
		INFO_DIR=${INFODIR} ${SH} install.sh)
	@${RMDIR} ${DOCSDIR}/html

post-install:
.for DIR in ${EMPTY_DIRS}
	${MKDIR} ${PREFIX}/lib/sbcl/${DIR}/
	@${TOUCH} ${PREFIX}/lib/sbcl/${DIR}/.keep_me
.endfor

test:	build
	(cd ${WRKSRC}/tests && ${SH} run-tests.sh)

.include <bsd.port.post.mk>
