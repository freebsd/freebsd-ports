# New ports collection makefile for:	sbcl
# Date created:				2002-11-26
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	sbcl
PORTVERSION=	1.0.4
CATEGORIES=	lang lisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sbcl
DISTFILES=	${DISTNAME}-source${EXTRACT_SUFX}

MAINTAINER=	sa2c@sa2c.net
COMMENT=	A Common Lisp development system derived from the CMU CL system

USE_BZIP2=	yes
USE_GMAKE=	yes

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/*

# SBCL is a native code compiler: it must be ported per architecture.
ONLY_FOR_ARCHS=	i386 amd64

MAN1=		sbcl.1
INFO=		asdf sbcl
INFODIR=	${PREFIX}/${INFO_PATH}

.include <bsd.port.pre.mk>

# If you have a previous version of SBCL installed, you can use it
# instead of the binary distribution.
.if defined(WITH_SBCL)
LISP_CMD=	""
.else
BOOT_VERSION=	1.0.1
.if make(makesum)
BOOT_ARCH_OS_LIST=	x86-freebsd4 x86-64-freebsd5
.elif ${ARCH} == i386
BOOT_ARCH_OS_LIST=	x86-freebsd4
.elif ${ARCH} == amd64
BOOT_ARCH_OS_LIST=	x86-64-freebsd5
.endif
.for BOOT_ARCH_OS in ${BOOT_ARCH_OS_LIST}
BOOT_DISTNAME=	${PORTNAME}-${BOOT_VERSION}-${BOOT_ARCH_OS}
DISTFILES:=	${DISTFILES} ${BOOT_DISTNAME}-binary${EXTRACT_SUFX}
.endfor
LISP_CMD=	"${WRKDIR}/${BOOT_DISTNAME}/src/runtime/sbcl --core ${WRKDIR}/${BOOT_DISTNAME}/output/sbcl.core --disable-debugger --userinit /dev/null --sysinit /dev/null"
.if ${ARCH} == i386 && ${OSVERSION} >= 500000
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libc.so.4:${PORTSDIR}/misc/compat4x
.elif ${ARCH} == amd64 && ${OSVERSION} >= 600000
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libc.so.5:${PORTSDIR}/misc/compat5x
.endif
.endif

.if defined(WITH_THREADS) && ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x with threading
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386_ONLY=""
.else
PLIST_SUB+=	I386_ONLY="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|CFLAGS = .*|CFLAGS = ${CFLAGS} -g -DSBCL_HOME=\\"${PREFIX}/lib/sbcl/\\"|' \
		${WRKSRC}/src/runtime/GNUmakefile
	@${FIND} ${WRKSRC} -name '*.orig' -o -name '*.bak' | ${XARGS} ${RM}
.if defined(WITH_THREADS)
	@${CP} ${FILESDIR}/customize-target-features.lisp ${WRKSRC}
.endif

do-build:
	@(cd ${WRKSRC} && ${SETENV} INSTALL_ROOT=${PREFIX} \
		${SH} make.sh ${LISP_CMD})
	@(cd ${WRKSRC}/doc/manual && \
		${GMAKE} MAKEINFO='makeinfo --no-split' info)

do-install:
	(cd ${WRKSRC} && ${SETENV} INSTALL_ROOT=${PREFIX} \
		MAN_DIR=${PREFIX}/man DOC_DIR=${DOCSDIR} \
		INFO_DIR=${INFODIR}  ${SH} install.sh)
	@${RMDIR} ${DOCSDIR}/html

test:	build
	(cd ${WRKSRC}/tests && ${SH} run-tests.sh)

pre-everything::
.if !defined(WITH_THREADS) && ${OSVERSION} >= 600000
	@${ECHO_MSG} "====>"
	@${ECHO_MSG} "====> To enable experimental threading support, define WITH_THREADS."
	@${ECHO_MSG} "====>"
.elif defined(WITH_THREADS) && ${OSVERSION} < 600000
	@${ECHO_MSG} "====>"
	@${ECHO_MSG} "====> WARNING: Current threading support is very unstable on FreeBSD 5.x."
	@${ECHO_MSG} "====>"
.endif

.include <bsd.port.post.mk>
