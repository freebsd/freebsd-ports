# New ports collection makefile for:	netpbm
# Version required:	1mar1994
# Date created:		?
# Whom:			jmz (original)
#
# $Id: Makefile,v 1.14 1998/11/25 09:01:19 asami Exp $
#

DISTNAME=	netpbm
PKGNAME=	netpbm-94.3.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTFILES=	netpbm-1mar1994.tar.gz

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff34
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_IMAKE=	yes
MAN1=	anytopnm.1 asciitopgm.1 atktopbm.1 bioradtopgm.1 bmptoppm.1 \
	brushtopbm.1 cmuwmtopbm.1 fitstopnm.1 fstopgm.1 g3topbm.1 gemtopbm.1 \
	giftopnm.1 gouldtoppm.1 hipstopgm.1 hpcdtoppm.1 icontopbm.1 \
	ilbmtoppm.1 imgtoppm.1 lispmtopgm.1 macptopbm.1 mgrtopbm.1 mtvtoppm.1 \
	pbmclean.1 pbmlife.1 pbmmake.1 pbmmask.1 pbmpscale.1 pbmreduce.1 \
	pbmtext.1 pbmto10x.1 pbmto4425.1 pbmtoascii.1 pbmtoatk.1 pbmtobbnbg.1 \
	pbmtocmuwm.1 pbmtoepsi.1 pbmtoepson.1 pbmtog3.1 pbmtogem.1 pbmtogo.1 \
	pbmtoicon.1 pbmtolj.1 pbmtoln03.1 pbmtolps.1 pbmtomacp.1 pbmtomgr.1 \
	pbmtopgm.1 pbmtopi3.1 pbmtopk.1 pbmtoplot.1 pbmtoptx.1 pbmtox10bm.1 \
	pbmtoxbm.1 pbmtoybm.1 pbmtozinc.1 pbmupc.1 pcxtoppm.1 pgmbentley.1 \
	pgmcrater.1 pgmedge.1 pgmenhance.1 pgmhist.1 pgmkernel.1 pgmnoise.1 \
	pgmnorm.1 pgmoil.1 pgmramp.1 pgmtexture.1 pgmtofs.1 pgmtolispm.1 \
	pgmtopbm.1 pgmtoppm.1 pi1toppm.1 pi3topbm.1 picttoppm.1 pjtoppm.1 \
	pktopbm.1 pnmalias.1 pnmarith.1 pnmcat.1 pnmcomp.1 pnmconvol.1 \
	pnmcrop.1 pnmcut.1 pnmdepth.1 pnmenlarge.1 pnmfile.1 pnmflip.1 \
	pnmgamma.1 pnmhistmap.1 pnmindex.1 pnminvert.1 pnmmargin.1 \
	pnmnlfilt.1 pnmnoraw.1 pnmpad.1 pnmpaste.1 pnmrotate.1 pnmscale.1 \
	pnmshear.1 pnmsmooth.1 pnmtile.1 pnmtoddif.1 pnmtofits.1 pnmtops.1 \
	pnmtorast.1 pnmtosgi.1 pnmtosir.1 pnmtotiff.1 pnmtoxwd.1 ppm3d.1 \
	ppmbrighten.1 ppmchange.1 ppmdim.1 ppmdist.1 ppmdither.1 ppmflash.1 \
	ppmforge.1 ppmhist.1 ppmmake.1 ppmmix.1 ppmnorm.1 ppmntsc.1 ppmpat.1 \
	ppmquant.1 ppmquantall.1 ppmqvga.1 ppmrelief.1 ppmshift.1 ppmspread.1 \
	ppmtoacad.1 ppmtobmp.1 ppmtogif.1 ppmtoicr.1 ppmtoilbm.1 ppmtomap.1 \
	ppmtomitsu.1 ppmtopcx.1 ppmtopgm.1 ppmtopi1.1 ppmtopict.1 ppmtopj.1 \
	ppmtopjxl.1 ppmtopuzz.1 ppmtorgb3.1 ppmtosixel.1 ppmtotga.1 \
	ppmtouil.1 ppmtoxpm.1 ppmtoyuv.1 ppmtoyuvsplit.1 psidtopgm.1 \
	qrttoppm.1 rasttopnm.1 rawtopgm.1 rawtoppm.1 rgb3toppm.1 sgitopnm.1 \
	sirtopnm.1 sldtoppm.1 spctoppm.1 spottopgm.1 sputoppm.1 tgatoppm.1 \
	tifftopnm.1 xbmtopbm.1 ximtoppm.1 xpmtoppm.1 xvminitoppm.1 \
	xwdtopnm.1 ybmtopbm.1 yuvsplittoppm.1 yuvtoppm.1 zeisstopnm.1
MAN3=	libpbm.3 libpgm.3 libpnm.3 libppm.3
MAN5=	pbm.5 pgm.5 pnm.5 ppm.5

.include <bsd.port.mk>
