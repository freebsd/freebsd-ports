# New ports collection makefile for: Japanese Aladdin ghostscript + vector font library
# Version required:	4.0.3
# Date created:		23 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.6 1997/03/05 09:20:07 asami Exp $
#

DISTNAME=	ghostscript-4.03
PKGNAME=	jp-vfghostscript-4.03
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/ \
		ftp://i1nws2.fukui-u.ac.jp/pub/TeX/dvipr/ \
		ftp://ftp.mei.co.jp/free/gnu/util/ghostscript/drivers/ \
		${MASTER_SITE_LOCAL} \
		http://www.jp.FreeBSD.org/~mita/LOCAL_PORTS/
DISTFILES=	${GS_SOURCES} ${GS_DRIVERS} ${GS_FONTS_STD} ${GS_FONTS_OTHER}

MAINTAINER=	mita@jp.FreeBSD.org

LIB_DEPENDS=	VFlib\\.2\\.:${PORTSDIR}/japanese/vflib

EXTRACT_ONLY=	ghostscript-4.03.tar.gz
WRKSRC=		${WRKDIR}/gs4.03
MAKEFILE=	unix-gcc.mak
MAKE_FLAGS=	prefix=${PREFIX} zlibc_=-lz CFLAGS="${CFLAGS}" -f
MAN1=		gs.1

CFLAGS+=	-DA4
DOC_DIR=	${PREFIX}/share/ghostscript/4.03vflib/doc 
PRINTER=	${WRKSRC}/jp-printers
GS_SOURCES=	ghostscript-4.03.tar.gz
GS_SOURCES+=	ghostscript-4.03gnu.tar.gz
GS_DRIVERS=	gs4.03-vflib.tar.gz
GS_DRIVERS+=	gdevlips4-1.0.1.tar.gz
GS_DRIVERS+=	gdevmjc-0.7.tar.gz
GS_DRIVERS+=	gdevrpdl.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-4.0.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-3.0.tar.gz

pre-extract:
	@(cd ${PORTSDIR}/graphics/jpeg ; ${MAKE} extract)
	@(cd ${PORTSDIR}/graphics/png  ; ${MAKE} extract)

pre-patch:
	@(cd ${WRKSRC} ; tar xzf ${DISTDIR}/gs4.03-vflib.tar.gz ) 
	@(cd ${WRKDIR} ; \
	  ${PATCH} -p < ${WRKSRC}/gs4.03-vflib/gs4.03-vflib.diff >/dev/null 2>&1; \
	)

post-patch:
	@( mkdir ${PRINTER} ; \
	  cd ${PRINTER} ; \
	  ${PATCH} -p0 < ${FILESDIR}/gdevep82.patch >/dev/null 2>&1 ; \
	  tar xzf ${DISTDIR}/gdevlips4-1.0.1.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevmjc-0.7.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevrpdl.tar.gz ; \
	  ${CP} gdevmjc-0.7/gdevmjc.c gdevmjc-0.7/mjc.dev ${WRKSRC}; \
	  ${CP} gdevlips4-1.0.1/gdevlips4.c gdevlips4-1.0.1/gdevlips4.mak ${WRKSRC}; \
	  ${CP} gdevep82/gdevep82.c gdevep82/gdevep82.mak ${WRKSRC}; \
	  ${CP} gdevrpdl/gdevrpdl.c gdevrpdl/gdevrpdl.mak ${WRKSRC}; \
	  )
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevlips4.mak.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevlips4.c.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/mjc.dev.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevmjc.c.patch
	@${CAT} ${WRKSRC}/gdevep82.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevlips4.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevrpdl.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/mjc.dev >> ${WRKSRC}/unix-gcc.mak


do-configure:
.if defined(BATCH)
	@${SETENV} PORTSDIR=${PORTSDIR} WRKSRC=${WRKSRC} \
		/bin/sh ${SCRIPTDIR}/configure.batch
.else
	@${SETENV} PORTSDIR=${PORTSDIR} WRKSRC=${WRKSRC} \
		/bin/sh ${SCRIPTDIR}/configure
.endif

pre-install:
	@mkdir -p ${PREFIX}/share/ghostscript
	@tar -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_STD}
	@tar -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_OTHER}

post-install:
	@strip ${PREFIX}/bin/gs
	@( \
	  ${CP} ${PRINTER}/gdevep82/gdevep82.jis ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevlips4-1.0.1/Readme ${DOC_DIR}/gdevlips4.euc ; \
	  ${CP} ${PRINTER}/gdevmjc-0.7/README.jis ${DOC_DIR}/gdevmjc.jis ; \
	  ${CP} ${PRINTER}/gdevmjc-0.7/MJ700V2C.FAQ ${DOC_DIR} ; \
	)

pre-clean:
	@(cd ${PORTSDIR}/graphics/jpeg ; ${MAKE} clean)
	@(cd ${PORTSDIR}/graphics/png  ; ${MAKE} clean)

.include <bsd.port.mk>
