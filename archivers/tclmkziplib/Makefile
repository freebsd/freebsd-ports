# New ports collection makefile for:	tclmkziplib
# Date created:				4 Jan 2007
# Whom:					Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tclmkziplib
PORTVERSION=	1.0
CATEGORIES=	archivers tcl
MASTER_SITES=	http://mkextensions.sourceforge.net/
DISTNAME=	mkZiplib${PORTVERSION:S/.//}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	GZIP and ZIP support for TCL; dynamicly loadable

TCL_VER?=	8.4
TCLVND=		${TCL_VER:S/.//}

LIB_DEPENDS+=	tcl84:${PORTSDIR}/lang/tcl${TCLVND}

WRKSRC=		${WRKDIR}/mkZiplib${PORTVERSION}
USE_ZIP=	yes

TCLCONFIG?=	${LOCALBASE}/lib/tcl${TCL_VER}/tclConfig.sh

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	VERSION=${PORTVERSION:S/.//} \
		TCLCONFIG=${TCLCONFIG}

PLIST_SUB+=	VERSION=${PORTVERSION:S/.//}

pre-build:
		@${TEST} -f ${TCLCONFIG} || ( echo "tclConfig.sh is required to build mkZiplib"; exit 1 )

do-install:
		@${MKDIR} ${PREFIX}/lib/mkZiplib
		@${INSTALL_PROGRAM} ${WRKSRC}/mkZiplib${PORTVERSION:S/.//}.so ${PREFIX}/lib/mkZiplib
		@${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/mkZiplib

post-install:
.if !defined(NOPORTDOCS)
		@ ${MKDIR} ${DOCSDIR}
		@ ${INSTALL_DATA} ${WRKSRC}/mkZiplib${PORTVERSION:S/.//}.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
