# New ports collection makefile for: Japanese Aladdin ghostscript + vector font library
# Version required:	4.0.3
# Date created:		23 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id$
#

DISTNAME=	ghostscript4.03
PKGNAME=	jp-vfghostscript-4.03
CATEGORIES+=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.iis.u-tokyo.ac.jp/GNU/ \
		ftp://ftp.ae.keio.ac.jp/pub/msdos/gnu/ghostscript/ \
		ftp://i1nws2.fukui-u.ac.jp/pub/TeX/dvipr/ \
		ftp://ftp.mei.co.jp/free/gnu/util/ghostscript/drivers/

MAINTAINER=	mita@jp.FreeBSD.org

GS_SOURCES=	ghostscript-4.03.tar.gz
GS_SOURCES+=	ghostscript-4.03gnu.tar.gz
GS_DRIVERS=	gs4.03-vflib.tar.gz
GS_DRIVERS+=	gdevlips4-1.0.1.tar.gz
GS_DRIVERS+=	gdevbitps-1.0.tar.gz
GS_DRIVERS+=	gdevmjc-0.7.tar.gz
GS_FONTS_STD=	ghostscript-fonts-std-4.01.tar.gz	# didn't change
GS_FONTS_OTHER=	ghostscript-fonts-other-4.01.tar.gz	# didn't change

DISTFILES=	${GS_SOURCES} ${GS_DRIVERS} ${GS_FONTS_STD} ${GS_FONTS_OTHER}

LIB_DEPENDS=	VFlib\\.2\\.:${PORTSDIR}/japanese/vflib

EXTRACT_ONLY=	ghostscript-4.03.tar.gz

WRKSRC=		${WRKDIR}/gs4.03
MAKEFILE=	unix-gcc.mak
CFLAGS+=	-DA4
DOC_DIR=	${PREFIX}/share/ghostscript/4.03vflib/doc 
PRINTER=	${WRKSRC}/jp-printers
MAKE_FLAGS=	prefix=${PREFIX} zlibc_=-lz CFLAGS="${CFLAGS}" -f
MAN1=		gs.1

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
	  tar xzf ${DISTDIR}/gdevbitps-1.0.tar.gz ; \
	  ${PATCH} -p0 < ${FILESDIR}/gdevep82.patch >/dev/null 2>&1 ; \
	  tar xzf ${DISTDIR}/gdevlips4-1.0.1.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevmjc-0.7.tar.gz ; \
	  ${CP} gdevmjc-0.7/gdevmjc.c gdevmjc-0.7/mjc.dev ${WRKSRC}; \
	  ${CP} gdevlips4-1.0.1/gdevlips4.c gdevlips4-1.0.1/gdevlips4.mak ${WRKSRC}; \
	  ${CP} gdevep82/gdevep82.c gdevep82/gdevep82.mak ${WRKSRC}; \
	  ${CP} gdevbitps/gdevbitps.c gdevbitps/bitps4.03.mak ${WRKSRC}; \
	  )
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevlips4.mak.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevlips4.c.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/mjc.dev.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevmjc.c.patch
	@${CAT} ${WRKSRC}/bitps4.03.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevep82.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevlips4.mak >> ${WRKSRC}/unix-gcc.mak
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
	@tar -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_STD}
	@tar -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_OTHER}


post-install:
	@strip ${PREFIX}/bin/gs ;
	@( \
	  ${CP} ${PRINTER}/gdevbitps/gdevbitps.jis ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevep82/gdevep82.jis ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevlips4-1.0.1/Readme ${DOC_DIR}/gdevlips4.euc ; \
	  ${CP} ${PRINTER}/gdevmjc-0.7/README.jis ${DOC_DIR}/gdevmjc.jis ; \
	  ${CP} ${PRINTER}/gdevmjc-0.7/MJ700V2C.FAQ ${DOC_DIR} ; \
	)

pre-clean:
	@(cd ${PORTSDIR}/graphics/jpeg ; ${MAKE} clean)
	@(cd ${PORTSDIR}/graphics/png  ; ${MAKE} clean)

.include <bsd.port.mk>
