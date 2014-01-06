# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tclmkziplib
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	archivers tcl
MASTER_SITES=	http://mkextensions.sourceforge.net/
DISTNAME=	mkZiplib${PORTVERSION:S/.//}
EXTRACT_SUFX=	.zip

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	GZIP and ZIP support for TCL; dynamically loadable

USES+=		tcl

WRKSRC=		${WRKDIR}/mkZiplib${PORTVERSION}

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	VERSION=${PORTVERSION:S/.//} \
		TCL_VER=${TCL_VER} \
		TCLCONFIG=${TCL_LIBDIR}/tclConfig.sh

PLIST_SUB+=	VERSION=${PORTVERSION:S/.//}

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mkZiplib
		${INSTALL_LIB} ${WRKSRC}/mkZiplib${PORTVERSION:S/.//}.so ${STAGEDIR}${PREFIX}/lib/mkZiplib
		${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/mkZiplib
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/mkZiplib${PORTVERSION:S/.//}.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
