# New ports collection makefile for:	sbcl
# Date created:				2002-11-26
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	sbcl
PORTVERSION=	1.0.7
CATEGORIES=	lang lisp
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}-source${EXTRACT_SUFX}

MAINTAINER=	sa2c@sa2c.net
COMMENT=	A Common Lisp development system derived from the CMU CL system

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/*

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
BOOT_VERSION=	1.0.6
.if make(makesum)
BOOT_ARCH_OS_LIST=	x86-freebsd x86-64-freebsd
.elif ${ARCH} == "i386"
BOOT_ARCH_OS_LIST=	x86-freebsd
LISP_EXTRA_ARG=	--dynamic-space-size 512
.elif ${ARCH} == "amd64"
BOOT_ARCH_OS_LIST=	x86-64-freebsd
LISP_EXTRA_ARG=
.endif
.for BOOT_ARCH_OS in ${BOOT_ARCH_OS_LIST}
BOOT_DISTNAME=	${PORTNAME}-${BOOT_VERSION}-${BOOT_ARCH_OS}
DISTFILES:=	${DISTFILES} ${BOOT_DISTNAME}-binary${EXTRACT_SUFX}
.endfor
LISP_CMD=	"${WRKDIR}/${BOOT_DISTNAME}/src/runtime/sbcl --core ${WRKDIR}/${BOOT_DISTNAME}/output/sbcl.core ${LISP_EXTRA_ARG} --disable-debugger --userinit /dev/null --sysinit /dev/null"
.if ${OSVERSION} >= 600000
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libc.so.5:${PORTSDIR}/misc/compat5x
.endif
.endif

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

test:	build
	(cd ${WRKSRC}/tests && ${SH} run-tests.sh)

.if defined(WITH_THREADS) && ${OSVERSION} < 600000
pre-everything::
	@${ECHO_MSG} "====>"
	@${ECHO_MSG} "====> WARNING: Current threading support is very unstable on FreeBSD 5.x."
	@${ECHO_MSG} "====>"
.endif

.include <bsd.port.post.mk>
