# New ports collection makefile for:	pTeX-common
# Date created:		05 Oct 1997
# Whom:			max
#
# $FreeBSD$
#

PORTNAME=	ptex
PORTVERSION=	2.1.11
PORTREVISION=	2
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-common
DISTFILES=	${TETEX_SRC} ${TETEX_TEXMF} ${PTEX_TEXMF} ${DVIPSK_JPATCH}
EXTRACT_ONLY=	${TETEX_SRC} ${DVIPSK_JPATCH}

MAINTAINER=	max@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww

USE_XLIB=	yes
MANUAL_PACKAGE_BUILD=	can only build with empty /usr/local
DIST_SUBDIR=	teTeX
WRKSRC=		${WRKDIR}/teTeX-1.0
USE_GMAKE=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --disable-multiplatform \
		--without-texinfo --without-dialog \
		--without-xdvik --without-dvipsk \
		--with-system-ncurses --with-system-zlib \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
		--with-pnglib-include=${LIBPNG_PREFIX}/include
CONFIGURE_ENV=	INSTALL_PROGRAM="${BSD_INSTALL_SCRIPT}"
INSTALL_TARGET=	install strip
MLINKS=		mktexpk.1 MakeTeXPK.1 allcm.1 allec.1 pdftex.1 cont-de.1 \
		pdftex.1 cont-en.1 pdftex.1 cont-nl.1 etex.1 einitex.1 \
		etex.1 elatex.1 etex.1 evirtex.1 mf.1 inimf.1 \
		mpost.1 inimpost.1 omega.1 iniomega.1 tex.1 initex.1 \
		omega.1 lambda.1 pdftex.1 pdfinitex.1 pdftex.1 pdflatex.1 \
		pdftex.1 pdfvirtex.1 mktexlsr.1 texhash.1 mf.1 virmf.1 \
		mpost.1 virmpost.1 omega.1 viromega.1 tex.1 virtex.1
MAN1=				access.1 allcm.1 allneeded.1 amstex.1 \
		bibtex.1 dmp.1 dvicopy.1 dvilj.1 dvired.1 \
		dvitype.1 eplain.1 etex.1 fontexport.1 fontimport.1 \
		gftodvi.1 gftopk.1 gftype.1 gsftopk.1 kpsestat.1 \
		kpsewhich.1 latex.1 mag.1 makeindex.1 makempx.1 mf.1 \
		mft.1 mktexlsr.1 mktexmf.1 mktexpk.1 mktextfm.1 \
		mpost.1 mpto.1 newer.1 omega.1 patgen.1 pdftex.1 \
		pfb2pfa.1 pk2bm.1 pktogf.1 pktype.1 pltotf.1 \
		pooltype.1 ps2frag.1 ps2pk.1 readlink.1 tangle.1 tex.1 \
		texconfig.1 texi2html.1 tftopl.1 tie.1 vftovp.1 \
		vptovf.1 weave.1

TETEX_SRC=	teTeX-src-1.0.7.tar.gz
TETEX_TEXMF=	teTeX-texmf-1.0.2.tar.gz
PTEX_TEXMF=	ptex-texmf-1.10.tar.gz
DVIPSK_JPATCH=	dvipsk-jpatch-p1.5e.tar.gz
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
TEXMF_TREE=	${PREFIX}/share/texmf

pre-install:
	@${MKDIR} ${TEXMF_TREE}
	@${TAR} --exclude 'dvips/base/*' -zxf ${_DISTDIR}/${TETEX_TEXMF} -C ${TEXMF_TREE}
	@${TAR} -zxf ${_DISTDIR}/${PTEX_TEXMF} -C ${TEXMF_TREE}
	@${PATCH} -d ${TEXMF_TREE}/dvips/pstricks -E --quiet < ${WRKDIR}/PSTricks.patch
	@${RM} ${TEXMF_TREE}/dvips/pstricks/pst-text.pro.orig
# Following two commands are intended to be temporary until 
# the original distribution is updated.
	${MV} -f ${PREFIX}/share/texmf/tex/latex/base/latex.ltx ${WRKDIR}
	${SED} -e 's/\\ifnum\\count@>17/\\ifnum\\count@>57/' \
		${WRKDIR}/latex.ltx \
		> ${PREFIX}/share/texmf/tex/latex/base/latex.ltx

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/texinfo/util/texi2dvi ${PREFIX}/bin
	@${SED} -e "s|^TEXMFMAIN = .*|TEXMFMAIN = ${TEXMF_TREE}|g" \
		< ${WRKSRC}/texk/kpathsea/texmf.cnf \
		> ${TEXMF_TREE}/web2c/texmf.cnf
	@${CHMOD} 644 ${TEXMF_TREE}/web2c/texmf.cnf
	${SETENV} TEXMFMAIN=${TEXMF_TREE} PATH=${PREFIX}/bin:${PATH} \
		${PREFIX}/bin/texconfig font ro
	${SETENV} TEXMFMAIN=${TEXMF_TREE} PATH=${PREFIX}/bin:${PATH} \
		${PREFIX}/bin/texconfig font options appendonlydir varfonts
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
