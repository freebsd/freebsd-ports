# New ports collection makefile for:	sbcl
# Date created:				2002-11-26
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	sbcl
PORTVERSION=	0.7.11
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sbcl
DISTFILES=	${DISTNAME}-source${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}-html${EXTRACT_SUFX}
.endif

MAINTAINER=	des@FreeBSD.org

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

do-build:
	(cd ${WRKSRC} && ${SH} make.sh ${LISP_CMD})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/runtime/sbcl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/output/sbcl.core ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/doc/sbcl.1 ${PREFIX}/man/man1/
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} BUGS COPYING CREDITS ${DOCSDIR})
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc && ${TAR} cf - html | ${TAR} xf - -C ${DOCSDIR})
.endif

.include <bsd.port.mk>
