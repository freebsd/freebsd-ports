# Created by: Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
# $FreeBSD$

PORTNAME=	dvipsk
PORTVERSION=	5.95b
PORTREVISION=	14
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,hrs/teTeX,:S,$,:udvipspatch,}
#		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/:jpatch \
MASTER_SITE_SUBDIR=	obsolete/systems/unix/teTeX/3.0/distrib/
PKGNAMESUFFIX=	-tetex
DISTFILES=	${TETEX_SRC}${EXTRACT_SUFX} \
		dvipsk-${PORTVERSION}-p1.7a.tar.gz:udvipspatch
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	${TETEX_SRC}${EXTRACT_SUFX} \
		dvipsk-${PORTVERSION}-p1.7a.tar.gz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI to PostScript translator + Japanese patch

BUILD_DEPENDS=	${LOCALBASE}/${TEXMFDIR}/fonts/tfm/ptex/min10.tfm:${PORTSDIR}/japanese/ptex
RUN_DEPENDS=	${LOCALBASE}/${TEXMFDIR}/fonts/tfm/ptex/min10.tfm:${PORTSDIR}/japanese/ptex
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libwwwcore.so:${PORTSDIR}/www/libwww \
		libt1.so:${PORTSDIR}/devel/t1lib

PATCH_WRKSRC=	${WRKDIR}/${TETEX_SRC}/texk
EXTRA_PATCHES=	${WRKDIR}/dvipsk-${PORTVERSION}-p1.7a.diff
CONFIGURE_WRKSRC=${WRKDIR}/${TETEX_SRC}
BUILD_WRKSRC=	${WRKDIR}/${TETEX_SRC}/texk/dvipsk
INSTALL_WRKSRC=	${WRKDIR}/${TETEX_SRC}/texk/dvipsk

PLIST_SUB=	DVIPSDIR=${DVIPSDIR} \
		DVIPSCONFIGDIR=${DVIPSCONFIGDIR} \
		DVIPSCONFIGDIR_DIST=${DVIPSCONFIGDIR_DIST} \
		MKTEXLSR="${MKTEXLSR}" \
		TEXMFCONFIGDIR=${TEXMFCONFIGDIR} \
		FONTSMAPDIR=${FONTSMAPDIR} \
		UPDMAP_SYS="${UPDMAP_SYS}"
USE_TEX=	tetex base texmf
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-multiplatform \
		--without-texinfo \
		--without-dialog \
		--with-system-ncurses --with-system-zlib \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
		--with-pnglib-include=${LIBPNG_PREFIX}/include \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include \
		--without-xdvik --without-oxdvik
CONFLICTS=	dvipsk-tetex-[0-9]* \
		dvips-[0-9]* \
		texlive-[0-9]* tex-web2c-[0-9]* \
		tex-kpathsea-[0-9]* tex-xdvik-[0-9]* \
		tex-dvipsk-[0-9]* tex-dvipdfmx-[0-9]*

MAN1=		dvips.1 afm2tfm.1
MLINKS=		dvips.1 odvips.1
INFO=		dvips

TETEX_SRC=	tetex-src-3.0

MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr \
			${LOCALBASE}/${TEXMFDIR} \
			${LOCALBASE}/${TEXMFCONFIGDIR}
TEXMFDIR=	share/texmf
TEXMFDISTDIR=	share/texmf-dist
TEXMFLOCALDIR=	share/texmf-local
TEXMFCONFIGDIR=	share/texmf-config
TEXMFLOCAL_LSR?=${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
FONTSMAPDIR=	${TEXMFDIR}/fonts/map/ptex
DVIPSDIR?=	${TEXMFDIR}/dvips/ptex
DVIPSCONFIGDIR?=${TEXMFCONFIGDIR}/dvips/ptex
DVIPSCONFIGDIR_DIST?=${TEXMFDIR}/dvips/ptex
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

UPDMAP_SYS=	${LOCALBASE}/bin/updmap-sys --progname=ptex
TEXCONFIGBIN=	${SETENV} TEXCONFIGINPUTS=\$$TEXMF/texconfig/ptex/ \
			${LOCALBASE}/bin/texconfig-sys

NO_STAGE=	yes
post-configure:
	cd ${PATCH_WRKSRC} && \
		${RM} -rf udvipsk && ${CP} -R dvipsk udvipsk

do-build:
	cd ${WRKDIR}/${TETEX_SRC}/texk/dvipsk &&\
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET}
	cd ${WRKDIR}/${TETEX_SRC}/texk/udvipsk &&\
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} \
		program=udvips XDEFS=-DUDVIPS \
		${ALL_TARGET}

do-install:
	${MKDIR} ${PREFIX}/${DVIPSCONFIGDIR}/config
	cd ${WRKDIR}/${TETEX_SRC}/texk/dvipsk &&\
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET}
	${INSTALL_PROGRAM} \
		${PATCH_WRKSRC}/udvipsk/udvips \
		${PREFIX}/bin
	${INSTALL_DATA} \
		${FILESDIR}/ptex-kanji.map \
		${PREFIX}/${FONTSMAPDIR}/dvips/psfonts_jp.map
	${RM} -f ${PREFIX}/${FONTSMAPDIR}/../dvips/ptex/psfonts_jp.map
	${RMDIR} ${PREFIX}/${FONTSMAPDIR}/../dvips/ptex
	${MKTEXLSR}
	${SH} ${UPDMAP_SYS} --enable Map=psfonts_jp.map

post-install:
	${TEXCONFIGBIN} dvips printcmd -
	${MKTEXLSR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
