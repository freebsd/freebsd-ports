# New ports collection makefile for:	tcl7.6jp
# Version required:	7.6p2jp
# Date created:		
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $Id: Makefile,v 1.1.1.1 1997/03/02 13:01:24 asami Exp $
#

DISTNAME=	tcl7.6p2
PKGNAME=	jp-tcl-7.6
CATEGORIES=	japanese lang
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/ 

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/
PATCHFILES=	tcl7.6jp-patch.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

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
	cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} && rm *.o

pre-install:
	${MKDIR} ${PREFIX}/lib/tcl7.6jp
	cd ${WRKSRC} && ${MAKE} -f Makefile.lib install PREFIX=${PREFIX}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
