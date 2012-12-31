# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tclmkziplib
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	archivers tcl
MASTER_SITES=	http://mkextensions.sourceforge.net/
DISTNAME=	mkZiplib${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GZIP and ZIP support for TCL; dynamically loadable

LICENSE=	BSD

USE_TCL=	84+

WRKSRC=		${WRKDIR}/mkZiplib${PORTVERSION}
USE_ZIP=	yes

.include <bsd.port.options.mk>

TCLCONFIG?=	${LOCALBASE}/lib/tcl${TCL_VER}/tclConfig.sh

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	VERSION=${PORTVERSION:S/.//} \
		TCL_VER=${TCL_VER} \
		TCLCONFIG=${TCLCONFIG}

PLIST_SUB+=	VERSION=${PORTVERSION:S/.//}

pre-build:
		@${TEST} -f ${TCLCONFIG} || ( echo "tclConfig.sh is required to build mkZiplib"; exit 1 )

do-install:
		@${MKDIR} ${PREFIX}/lib/mkZiplib
		@${INSTALL_PROGRAM} ${WRKSRC}/mkZiplib${PORTVERSION:S/.//}.so ${PREFIX}/lib/mkZiplib
		@${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/mkZiplib

post-install:
.if ${PORT_OPTIONS:MDOCS}
		@ ${MKDIR} ${DOCSDIR}
		@ ${INSTALL_DATA} ${WRKSRC}/mkZiplib${PORTVERSION:S/.//}.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
