# New ports collection makefile for:	tk4.2p2JP
# Version required:	4.2p2jp
# Date created:		
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $Id: Makefile,v 1.4 1998/07/03 23:06:36 steve Exp $
#

DISTNAME=	tk4.2p2
PKGNAME=	ja-tk-4.2
CATEGORIES=	japanese x11-toolkits
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl7_6/

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/
PATCHFILES=	tk4.2jp-patch.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	${LOCALBASE}/lib/libtcl76jp.so\.1\.0:${PORTSDIR}/japanese/tcl76

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} -E ${PATCH_DIST_STRIP}
PATCH_ARGS=		-d ${WRKDIR}/${DISTNAME} -E ${PATCH_STRIP}
.else
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_DIST_STRIP}
PATCH_ARGS=		-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_STRIP}
.endif

VERSION=	4.2jp

post-extract:
	@${MV} ${WRKDIR}/tk4.2 ${WRKDIR}/${DISTNAME}

post-configure:
	@${ECHO} "We will NOT only make shared library, but also static one."
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} VERSION=${VERSION} && rm -f *.o

pre-install:
	${MKDIR} ${PREFIX}/lib/tk${VERSION}

post-install:
	cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} VERSION=${VERSION} install
	${LDCONFIG} -m ${PREFIX}/lib
	@echo "**********"
	@echo "IMPORTANT:"
	@echo "**********"
	@echo "We've installed:"
	@echo "tkConfig.sh in $(PREFIX)/lib/tk$(VERSION)/tkConfig.sh"
	@echo "tk.h        in $(PREFIX)/include/tk$(VERSION)/tk.h"
	@echo "These are NOT the default place, but good place to avoid"
	@echo "conflicting with another version of Tcl/Tks."

test:
	cd ${WRKSRC}; make test

.include <bsd.port.mk>
