# New ports collection makefile for:	sbcl
# Date created:				2002-11-26
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	sbcl
PORTVERSION=	0.8.17
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sbcl
DISTFILES=	${DISTNAME}-source${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}-html${EXTRACT_SUFX}
.endif

MAINTAINER=	des@FreeBSD.org
COMMENT=	A Common Lisp development system derived from the CMU CL system

# If you have a previous version of SBCL installed, you can use it
# instead of CMUCL to build the port, then deinstall it before
# installing the new version.
.if defined(WITH_SBCL)
LISP_CMD=	""
.else
BUILD_DEPENDS=	lisp:${PORTSDIR}/lang/cmucl
LISP_CMD=	"lisp -noinit -batch"
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes

# Can currently only bootstrap using cmucl, which is i386-only
ONLY_FOR_ARCHS=	i386

MAN1=		sbcl.1

post-extract:
	(${FIND} ${WRKSRC} -type d -name CVS -print0 | ${XARGS} -0 ${RM} -rf)

do-build:
	(cd ${WRKSRC} && ${SH} make.sh ${LISP_CMD})

do-install:
	(cd ${WRKSRC} && ${SETENV} INSTALL_ROOT=${PREFIX} \
	    MAN_DIR=${PREFIX}/man DOC_DIR=${DOCSDIR} \
	    INFO_DIR=${DOCSDIR}/info NO_DOCS=${NO_DOCS} \
	    ${SH} install.sh)
.if defined(NOPORTDOCS)
	# sbcl creates these directories even when they're not needed
	${RMDIR} ${DOCSDIR}/html ${DOCSDIR}/info
.endif

.include <bsd.port.mk>
