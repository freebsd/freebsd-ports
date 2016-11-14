# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tclmkziplib
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	archivers tcl
MASTER_SITES=	http://mkextensions.sourceforge.net/
DISTNAME=	mkZiplib${PORTVERSION:S/.//}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	GZIP and ZIP support for TCL; dynamically loadable

BROKEN_aarch64=	Fails to build: error: operand of type va_list where arithmetic or pointer type is required
DEPRECATED=	Abandonware, please use bundled zlib package [http://tcl.tk/man/tcl8.6/TclCmd/zlib.htm]
EXPIRATION_DATE=2017-01-15

USES+=		tcl zip

WRKSRC=		${WRKDIR}/mkZiplib${PORTVERSION}

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	VERSION=${PORTVERSION:S/.//} \
		TCL_VER=${TCL_VER} \
		TCLCONFIG=${TCL_LIBDIR}/tclConfig.sh

PLIST_SUB+=	VERSION=${PORTVERSION:S/.//}

OPTIONS_DEFINE=	DOCS

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mkZiplib
		${INSTALL_LIB} ${WRKSRC}/mkZiplib${PORTVERSION:S/.//}.so ${STAGEDIR}${PREFIX}/lib/mkZiplib
		${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/mkZiplib
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/mkZiplib${PORTVERSION:S/.//}.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
