# New ports collection makefile for:	pTeX-base
# Date created:		05 Oct 1997
# Whom:			max
#
# $FreeBSD$
#

PORTNAME=	ptex
PORTVERSION=	3.1.2
PORTREVISION=	3
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/ \
		${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-base
DISTFILES=	${TETEX_SRC} ${TETEX_TEXMF} ${PTEX_TEXMF} ${DVIPSK_JPATCH}
EXTRACT_ONLY=	${TETEX_SRC} ${DVIPSK_JPATCH}

MAINTAINER=	max@FreeBSD.org
COMMENT=	Base files for ASCII Japanese pTeX

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

CONFLICTS=	teTeX-*
.if defined(WITH_DVIPSK)
CONFLICTS+=	ja-dvipsk-* dvips-*
.endif
USE_XLIB=	yes
MANUAL_PACKAGE_BUILD=	can only build with empty /usr/local
DIST_SUBDIR=	teTeX
WRKSRC=		${WRKDIR}/tetex-src-${TETEX_VERSION}
USE_GMAKE=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --disable-multiplatform \
		--without-texinfo --without-dialog \
		--without-xdvik --without-dvipdfm \
		--with-system-ncurses --with-system-zlib \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
		--with-pnglib-include=${LIBPNG_PREFIX}/include \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include
.if defined(WITH_DVIPSK)
PLIST_SUB+=	DVIPSK=""
.else
CONFIGURE_ARGS+=--without-dvipsk
PLIST_SUB+=	DVIPSK="@comment "
.endif
CONFIGURE_ENV=	INSTALL_PROGRAM="${BSD_INSTALL_SCRIPT}"
MLINKS=		mktexpk.1 MakeTeXPK.1 allcm.1 allec.1 pdftex.1 cont-de.1 \
		pdftex.1 cont-en.1 pdftex.1 cont-nl.1 etex.1 einitex.1 \
		etex.1 elatex.1 etex.1 evirtex.1 mf.1 inimf.1 \
		mpost.1 inimpost.1 omega.1 iniomega.1 tex.1 initex.1 \
		omega.1 lambda.1 pdftex.1 pdfinitex.1 pdftex.1 pdflatex.1 \
		pdftex.1 pdfvirtex.1 mktexlsr.1 texhash.1 mf.1 virmf.1 \
		mpost.1 virmpost.1 omega.1 viromega.1 tex.1 virtex.1 \
		kpsetool.1 kpsexpand.1
MAN1=		access.1 allcm.1 allneeded.1 amstex.1 bibtex.1 \
		cweb.1 dmp.1 dvi2fax.1 dvicopy.1 dvihp.1 dvilj.1 dvired.1 \
		dvitomp.1 dvitype.1 e2pall.1 eplain.1 epstopdf.1 etex.1 \
		fontexport.1 fontimport.1 fontinst.1 \
		gftodvi.1 gftopk.1 gftype.1 gsftopk.1 \
		kpsepath.1 kpsetool.1 kpsestat.1 kpsewhich.1 \
		latex.1 mag.1 makeindex.1 makempx.1 mf.1 mft.1 mkindex.1 \
		mktexlsr.1 mktexmf.1 mktexpk.1 \
		mktextfm.1 mpost.1 mpto.1 newer.1 omega.1 \
		patgen.1 pdfetex.1 pdftex.1 pfb2pfa.1 \
		pk2bm.1 pktogf.1 pktype.1 pltotf.1 \
		pooltype.1 ps2frag.1 ps2pk.1 pslatex.1 readlink.1 rubibtex.1 \
		rumakeindex.1 tangle.1 tex.1 \
		texconfig.1 texdoc.1 texdoctk.1 texexec.1 texi2html.1 \
		texi2pdf.1 texshow.1 texutil.1 tftopl.1 thumbpdf.1 tie.1 \
		updmap.1 vftovp.1 vptovf.1 weave.1
.if defined(WITH_DVIPSK)
MAN1+=		afm2tfm.1 dvips.1
.endif
MAN5=		fmtutil.cnf.5
MAN8=		fmtutil.8 mkfontdesc.8 texlinks.8

TETEX_VERSION=	2.0.2
TETEX_SRC=	tetex-src-${TETEX_VERSION}.tar.gz
TETEX_TEXMF=	tetex-texmf-${TETEX_VERSION}.tar.gz
PTEX_TEXMF=	ptex-texmf-2.1.tar.gz
DVIPSK_JPATCH=	dvipsk-jpatch-p1.6.tar.gz
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}
TEXMF_TREE=	${PREFIX}/share/texmf
.if defined(WITH_DVIPSK)
EXCLUDE_DVIPSK=	# none
.else
EXCLUDE_DVIPSK=	--exclude 'dvips/base/*'
.endif

pre-extract:
.if !defined(WITH_DVIPSK)
	@${ECHO_MSG} "You can build and install Japanized dvipsk by defining WITH_DVIPSK, e.g.:"
	@${ECHO_MSG} "    make WITH_DVIPSK=yes"
.endif

post-extract:
	@${TAR} -zxf ${_DISTDIR}/${TETEX_TEXMF} -C ${WRKDIR} 'dvipdfm/*'

post-patch:
.if defined(WITH_DVIPSK)
	@${PATCH} -d ${WRKSRC}/texk -p0 -E --quiet < ${WRKDIR}/dvipsk-5.92b-p1.6.patch
.endif

pre-install:
	@${MKDIR} ${TEXMF_TREE}/dvips/base
	@${TAR} ${EXCLUDE_DVIPSK} --exclude 'dvipdfm/*' -zxf ${_DISTDIR}/${TETEX_TEXMF} -C ${TEXMF_TREE}
	@${TAR} -zxf ${_DISTDIR}/${PTEX_TEXMF} -C ${TEXMF_TREE}
	@${MKDIR} ${TEXMF_TREE}/dvipdfm-teTeX-dist
	@${CP} -pR ${WRKDIR}/dvipdfm/* ${TEXMF_TREE}/dvipdfm-teTeX-dist
	@if [ ! -d ${TEXMF_TREE}/dvipdfm ]; then \
	  ${LN} -fs ${TEXMF_TREE}/dvipdfm-teTeX-dist ${TEXMF_TREE}/dvipdfm; \
	  fi
	@if [ ! -e $TEXMF_TREE}/web2c/texmf.cnf ]; then \
	  ${LN} -fs ${TEXMF_TREE}/web2c/texmf.cnf-teTeX-dist ${TEXMF_TREE}/web2c/texmf.cnf; \
	  fi
	@${RM} ${TEXMF_TREE}/ls-R
	@${PATCH} -d ${TEXMF_TREE}/dvips/pstricks -E --quiet < ${WRKDIR}/PSTricks.patch
	@${RM} ${TEXMF_TREE}/dvips/pstricks/pst-text.pro.orig
.if defined(WITH_DVIPSK)
	@${INSTALL_DATA} ${FILESDIR}/kanji.map ${TEXMF_TREE}/dvips/config
	@${PATCH} -d ${TEXMF_TREE}/dvips/config -E --quiet < ${FILESDIR}/dvipsk-ja-cfg
	@${RM} ${TEXMF_TREE}/dvips/config/config.ps.orig
.endif

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/utils/texinfo/util/texi2dvi ${PREFIX}/bin
	@${SED} -e "s|^TEXMFMAIN = .*|TEXMFMAIN = ${TEXMF_TREE}|g" \
		< ${WRKSRC}/texk/kpathsea/texmf.cnf \
		> ${TEXMF_TREE}/web2c/texmf.cnf
	@${CHMOD} 644 ${TEXMF_TREE}/web2c/texmf.cnf
	@${SETENV} TEXMFMAIN=${TEXMF_TREE} PATH=${PREFIX}/bin:${PATH} \
	  ${PREFIX}/bin/texconfig font ro
	@${SETENV} TEXMFMAIN=${TEXMF_TREE} PATH=${PREFIX}/bin:${PATH} \
	  ${PREFIX}/bin/texconfig font options appendonlydir varfonts
	@${PREFIX}/bin/mktexlsr ${TEXMF_TREE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
