# New ports collection makefile for:	nkf
# Version required:	1.4 + patches
# Date created:		5 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.4 1994/11/25 18:20:48 asami Exp $
#

DISTNAME=	nkf-1.4
MASTER_SITES=	ftp://utsun.s.u-tokyo.ac.jp/fj/nkf/
DISTFILES=	nkf-1.4.tar.gz nkf-patches.tar.gz nkf-speedup-patch.gz
EXTRACT_ONLY=	nkf-1.4.tar.gz
WRKSRC=		${WRKDIR}/nkf

pre-patch: ${PATCH_COOKIE}
	@echo "===>  Applying unofficial patches for ${DISTNAME}"
	@(mkdir ${WRKDIR}/patches)
	@(tar -C ${WRKDIR}/patches -xzf ${DISTDIR}/nkf-patches.tar.gz)
	@(cd ${WRKSRC}; \
	  for i in 1 2 3; do \
	    patch -s nkf.c < ${WRKDIR}/patches/patch$$i; \
	  done; \
	  for i in 4 5; do \
	    patch -s < ${WRKDIR}/patches/patch$$i; \
	  done; \
	  zcat ${DISTDIR}/nkf-speedup-patch.gz | patch -s; \
	)
	@echo "===>  Installing custom Makefile for ${DISTNAME}"
	@(cp ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
