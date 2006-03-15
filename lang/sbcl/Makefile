# New ports collection makefile for:	sbcl
# Date created:				2002-11-26
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	sbcl
PORTVERSION=	0.9.10
CATEGORIES=	lang lisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sbcl
DISTFILES=	${DISTNAME}-source${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}-html${EXTRACT_SUFX}
.endif

MAINTAINER=	sa2c@sa2c.net
COMMENT=	A Common Lisp development system derived from the CMU CL system

.undef BOOT_VERSION
# If you have a previous version of SBCL installed, you can use it
# instead of CMUCL to build the port, then deinstall it before
# installing the new version.
.if defined(WITH_SBCL)
LISP_CMD=	""
.elif defined(WITH_CMUCL)
BUILD_DEPENDS=	lisp:${PORTSDIR}/lang/cmucl
LISP_CMD=	"lisp -noinit -batch"
.else
BOOT_VERSION=	0.9.9
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/*

# Can currently only bootstrap using cmucl, which is i386-only
ONLY_FOR_ARCHS=	i386

MAN1=		sbcl.1
INFO=		asdf sbcl
INFODIR=	${PREFIX}/${INFO_PATH}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502124
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-contrib_asdf-install_installer.lisp
.endif

.if ${OSVERSION} >= 600022
RUN_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
.endif

.if defined(BOOT_VERSION)
BOOT_ARCH=	${ARCH:S/i386/x86/}
BOOT_OS=	${OPSYS:L}
BOOT_DISTNAME=	${PORTNAME}-${BOOT_VERSION}-${BOOT_ARCH}-${BOOT_OS}
DISTFILES+=	${BOOT_DISTNAME}-binary${EXTRACT_SUFX}
LISP_CMD=	"${WRKDIR}/${BOOT_DISTNAME}/src/runtime/sbcl --core ${WRKDIR}/${BOOT_DISTNAME}/output/sbcl.core --disable-debugger --userinit /dev/null --sysinit /dev/null"
.if ${OSVERSION} >= 500000
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libc.so.4:${PORTSDIR}/misc/compat4x
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|CFLAGS = .*|CFLAGS = ${CFLAGS} -DSBCL_HOME=\\"${PREFIX}/lib/sbcl/\\"|' \
		${WRKSRC}/src/runtime/GNUmakefile
	@${FIND} ${WRKSRC} -name '*.orig' -o -name '*.bak' | ${XARGS} ${RM}

do-build:
	(cd ${WRKSRC} && ${SETENV} INSTALL_ROOT=${PREFIX} \
		${SH} make.sh ${LISP_CMD})
	(cd ${WRKSRC}/doc/manual && \
		${GMAKE} MAKEINFO='makeinfo --no-split' info)

do-install:
	(cd ${WRKSRC} && ${SETENV} INSTALL_ROOT=${PREFIX} \
		MAN_DIR=${PREFIX}/man DOC_DIR=${DOCSDIR} \
		INFO_DIR=${INFODIR}  ${SH} install.sh)
.if defined(NOPORTDOCS)
	@${RMDIR} ${DOCSDIR}/html
.endif

test:	build
	(cd ${WRKSRC}/tests && ${SH} run-tests.sh)

.include <bsd.port.post.mk>
