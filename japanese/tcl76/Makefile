# New ports collection makefile for:	tcl7.6jp
# Version required:	7.6p2jp
# Date created:		11 March 1997
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $Id: Makefile,v 1.4 1997/09/14 21:36:06 max Exp $
#

DISTNAME=	tcl7.6p2
PKGNAME=	ja-tcl-7.6
CATEGORIES=	japanese lang
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl7_6/

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/
PATCHFILES=	tcl7.6jp-patch.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

VERSION=	7.6jp

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

post-extract:
	@${MV} ${WRKDIR}/tcl7.6 ${WRKDIR}/${DISTNAME}

post-configure:
	@${ECHO} "We will NOT only make shared library, but also static one."
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} VERSION=${VERSION} && rm *.o

pre-install:
	${MKDIR} ${PREFIX}/lib/tcl${VERSION}
	cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} VERSION=${VERSION} install

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
