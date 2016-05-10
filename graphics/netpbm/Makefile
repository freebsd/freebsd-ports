# Created by: Jean-Marc Zucconi <jmz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netpbm
PORTVERSION=	10.35.98
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	SF/netpbm/super_stable/${PORTVERSION} \
		LOCAL/dinoex/:man

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for conversion of images between different formats

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libjbig.so:graphics/jbigkit \
		libjasper.so:graphics/jasper \
		libxml2.so:textproc/libxml2

USES=		tar:tgz gmake perl5 shebangfix jpeg
CFLAGS+=	-DPNG_DEPSTRUCT= -Iutil
MAKE_ENV=	LN="${LN}" RANLIB="${RANLIB}"
MAKEFILE=	GNUmakefile
MAKEFILE2=	Makefile
INSTALL_TARGET=	install.bin install.lib install.data install-dev
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

SHEBANG_FILES=	editor/pnmflip editor/pnmquant editor/ppmfade \
		editor/ppmquant editor/ppmshadow generator/ppmrainbow

OPTIONS_DEFINE=	X11 MANPAGES DOCS
OPTIONS_SUB=	yes

X11_USE=	xorg=x11
X11_MAKE_ENV=	WITH_X11=yes

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMANPAGES} || make(makesum) || defined(FETCH_ALL)
#DISTFILES+=	netpbm-manpages-2013-03-09${EXTRACT_SUFX}:man
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} netpbm-manpages-2013-03-09${EXTRACT_SUFX}:man

# lifted from ${WRKSRC}/buildtools/Makefile.manpage
HMAN1+=	411toppm.1 anytopnm.1 asciitopgm.1 atktopbm.1 bioradtopgm.1 \
	bmptopnm.1 bmptoppm.1 brushtopbm.1 cmuwmtopbm.1 ddbugtopbm.1 \
	escp2topbm.1 eyuvtoppm.1 fiascotopnm.1 fitstopnm.1 fstopgm.1 \
	g3topbm.1 gemtopbm.1 gemtopnm.1 giftopnm.1 gouldtoppm.1 hdifftopam.1 \
	hipstopgm.1 hpcdtoppm.1 icontopbm.1 ilbmtoppm.1 imgtoppm.1 \
	infotopam.1 jbigtopnm.1 jpeg2ktopam.1 jpegtopnm.1 leaftoppm.1 \
	lispmtopgm.1 macptopbm.1 mdatopbm.1 mgrtopbm.1 mrf.1 mrftopbm.1 \
	mtvtoppm.1 neotoppm.1 palmtopnm.1 pamarith.1 pamchannel.1 pamcomp.1 \
	pamcut.1 pamdeinterlace.1 pamdice.1 pamditherbw.1 pamedge.1 \
	pamendian.1 pamfile.1 pamflip.1 pamfunc.1 pamgauss.1 pamlookup.1 \
	pamoil.1 pamperspective.1 pampop9.1 pamscale.1 pamseq.1 pamsharpmap.1 \
	pamsharpness.1 pamslice.1 pamstack.1 pamstereogram.1 pamstretch-gen.1 \
	pamstretch.1 pamsummcol.1 pamsumm.1 pamtodjvurle.1 pamtohdiff.1 \
	pamtohtmltbl.1 pamtojpeg2k.1 pamtopfm.1 pamtopnm.1 pamtotga.1 \
	pamtouil.1 pbmclean.1 pbmlife.1 pbmmake.1 pbmmask.1 pbmpage.1 \
	pbmpscale.1 pbmreduce.1 pbmtext.1 pbmtextps.1 pbmto10x.1 pbmto4425.1 \
	pbmtoascii.1 pbmtoatk.1 pbmtobbnbg.1 pbmtocmuwm.1 pbmtodjvurle.1 \
	pbmtoepsi.1 pbmtoepson.1 pbmtoescp2.1 pbmtog3.1 pbmtogem.1 pbmtogo.1 \
	pbmtoicon.1 pbmtolj.1 pbmtoln03.1 pbmtolps.1 pbmtomacp.1 pbmtomda.1 \
	pbmtomgr.1 pbmtomrf.1 pbmtonokia.1 pbmtopgm.1 pbmtopi3.1 pbmtopk.1 \
	pbmtoplot.1 pbmtoppa.1 pbmtopsg3.1 pbmtoptx.1 pbmtowbmp.1 \
	pbmtox10bm.1 pbmtoxbm.1 pbmtoybm.1 pbmtozinc.1 pbmupc.1 pc1toppm.1 \
	pcdovtoppm.1 pcxtoppm.1 pfmtopam.1 pgmabel.1 pgmbentley.1 pgmcrater.1 \
	pgmedge.1 pgmenhance.1 pgmhist.1 pgmkernel.1 pgmminkowski.1 \
	pgmmorphconv.1 pgmnoise.1 pgmnorm.1 pgmoil.1 pgmramp.1 pgmslice.1 \
	pgmtexture.1 pgmtofs.1 pgmtolispm.1 pgmtopbm.1 pgmtopgm.1 pgmtoppm.1 \
	pi1toppm.1 pi3topbm.1 picttoppm.1 pjtoppm.1 pktopbm.1 pngtopnm.1 \
	pnmalias.1 pnmarith.1 pnmcat.1 pnmcolormap.1 pnmcomp.1 pnmconvol.1 \
	pnmcrop.1 pnmcut.1 pnmdepth.1 pnmfile.1 pnmgamma.1 pnmhisteq.1 \
	pnmhistmap.1 pnmindex.1 pnminterp.1 pnminvert.1 pnmmargin.1 \
	pnmmontage.1 pnmnlfilt.1 pnmnoraw.1 pnmnorm.1 pnmpad.1 pnmpaste.1 \
	pnmpsnr.1 pnmquant.1 pnmremap.1 pnmrotate.1 pnmscalefixed.1 \
	pnmscale.1 pnmshear.1 pnmsmooth.1 pnmsplit.1 pnmstitch.1 pnmtile.1 \
	pnmtoddif.1 pnmtofiasco.1 pnmtofits.1 pnmtojbig.1 pnmtojpeg.1 \
	pnmtopalm.1 pnmtopclxl.1 pnmtoplainpnm.1 pnmtopng.1 pnmtopnm.1 \
	pnmtops.1 pnmtorast.1 pnmtorle.1 pnmtosgi.1 pnmtosir.1 \
	pnmtotiffcmyk.1 pnmtotiff.1 pnmtoxwd.1 ppm3d.1 ppmbrighten.1 \
	ppmchange.1 ppmcie.1 ppmcolormask.1 ppmdim.1 ppmdist.1 ppmdither.1 \
	ppmfade.1 ppmflash.1 ppmforge.1 ppmglobe.1 ppmhist.1 ppmlabel.1 \
	ppmmake.1 ppmmix.1 ppmnorm.1 ppmntsc.1 ppmpat.1 ppmquantall.1 \
	ppmquant.1 ppmrainbow.1 ppmrelief.1 ppmrough.1 ppmshadow.1 \
	ppmshift.1 ppmspread.1 ppmsvgalib.1 ppmtoacad.1 ppmtoarbtxt.1 \
	ppmtobmp.1 ppmtoeyuv.1 ppmtogif.1 ppmtoicr.1 ppmtoilbm.1 ppmtojpeg.1 \
	ppmtoleaf.1 ppmtolj.1 ppmtomitsu.1 ppmtompeg.1 ppmtoneo.1 ppmtopcx.1 \
	ppmtopgm.1 ppmtopi1.1 ppmtopict.1 ppmtopj.1 ppmtopjxl.1 ppmtoppm.1 \
	ppmtopuzz.1 ppmtorgb3.1 ppmtosixel.1 ppmtoterm.1 ppmtotga.1 \
	ppmtouil.1 ppmtowinicon.1 ppmtoxpm.1 ppmtoyuv.1 ppmtoyuvsplit.1 \
	ppmtv.1 ppmwheel.1 psidtopgm.1 pstopnm.1 qrttoppm.1 rasttopnm.1 \
	rawtopgm.1 rawtoppm.1 rgb3toppm.1 rletopnm.1 sbigtopgm.1 sgitopnm.1 \
	sirtopnm.1 sldtoppm.1 spctoppm.1 spottopgm.1 sputoppm.1 tgatoppm.1 \
	thinkjettopbm.1 tifftopnm.1 vidtoppm.1 wbmptopbm.1 winicontoppm.1 \
	xbmtopbm.1 ximtoppm.1 xpmtoppm.1 xvminitoppm.1 xwdtopnm.1 ybmtopbm.1 \
	yuvsplittoppm.1 yuvtoppm.1 zeisstopnm.1
.if ${PORT_OPTIONS:MX11}
HMAN1+=	pamx.1
.endif
HMAN3=	libnetpbm.3 libnetpbm_image.3 libnetpbm_ug.3 libpbm.3 \
	libpgm.3 libpm.3 libpnm.3 libppm.3 libsystem.3 libtmpfile.3
HMAN5=	extendedopacity.5 pam.5 pbm.5 pgm.5 pnm.5 ppm.5
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|doc/USERDOC|${DOCSDIR}/USERDOC|g' \
		${WRKSRC}/doc/netpbm.1
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/pm_config.in.h
	${REINPLACE_CMD} -e 's|^SCRIPTS =.*|SCRIPTS =|' ${WRKSRC}/GNUmakefile
	${REINPLACE_CMD} -e 's|<shhopt.h>|<pm_shhopt.h>|g' ${WRKSRC}/lib/pm.h
	${REINPLACE_CMD} -e 's| jpeg2000||g' \
		${WRKSRC}/converter/other/Makefile
	${CP} ${PATCHDIR}/Makefile.config.FreeBSD ${WRKSRC}/Makefile.config
	${LN} -sf ${WRKSRC}/lib/util/shhopt.h ${WRKSRC}/lib/util/pm_shhopt.h
	${LN} -sf ${WRKSRC}/lib/util/nstring.h ${WRKSRC}/lib/util/pm_nstring.h
	cd ${WRKSRC} && buildtools/stamp-date > ${WRKSRC}/lib/compile.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/util/pm_c_util.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_MAN} ${WRKSRC}/doc/netpbm.1 ${STAGEDIR}${PREFIX}/man/man1/
.if ${PORT_OPTIONS:MMANPAGES}
	cd ${WRKDIR}/doc && ${INSTALL_MAN} ${HMAN1} ${STAGEDIR}${PREFIX}/man/man1/
	cd ${WRKDIR}/doc && ${INSTALL_MAN} ${HMAN3} ${STAGEDIR}${PREFIX}/man/man3/
	cd ${WRKDIR}/doc && ${INSTALL_MAN} ${HMAN5} ${STAGEDIR}${PREFIX}/man/man5/
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/USERDOC ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
