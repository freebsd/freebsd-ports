# New ports collection makefile for: virtual fonts tools(n2a,a2n,a2bk,p2pn)
# Version required:	1.2
# Date created:		12 September 1997
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.6 1998/08/24 00:39:46 steve Exp $
#

DISTNAME=	vftool-1.2
PKGNAME=	ja-vftool-1.2
CATEGORIES=	print japanese
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/ \
		ftp://bash.cc.keio.ac.jp/pub/TeX/ascii-ptex/ptex215/ \
		ftp://ftp.iis.u-tokyo.ac.jp/TeX/NTT-JTeX/:old/ \
		ftp://ftp.iis.u-tokyo.ac.jp/TeX/fonts/pk/ \
		ftp://ftp.waseda.ac.jp/pub/tex/ascii-OLD/
DISTFILES=	vftool-1.2.tar.gz plib13-euc.tar.gz jtex-1.52.tar.gz

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

BUILD_DEPENDS=	${AFMDIR}/GothicBBB-Medium-H:${PORTSDIR}/japanese/japaneseAFM

EXTRACT_ONLY=	vftool-1.2.tar.gz

ALL_TARGET=	n2a a2n a2bk p2pn
SCRIPTS_ENV=	MV=${MV} SED=${SED} AFMDIR=${AFMDIR} JFMDIR=${JFMDIR}
MAKE_ENV=	AFM=${AFMDIR} JFM=${JFMDIR}

AFMDIR=		${PREFIX}/share/fonts/afm
FONTSDIR=	${PREFIX}/share/fonts
JFMDIR=		${WRKDIR}/share/texmf/fonts/tfm/ptex
PORTSDOCDIR=	${PREFIX}/share/doc/vftool
TARGETDIRS=	vf-n2a vf-a2n vf-a2bk vf-p2pn

post-extract:
	(cd ${WRKDIR}; \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/plib13-euc.tar.gz \
			${EXTRACT_AFTER_ARGS} \
			share/texmf/fonts/tfm/ptex; \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/jtex-1.52.tar.gz \
			${EXTRACT_AFTER_ARGS} \
			jtex-1.52/JTeXfonts/dnpfonts/mincho/tfm \
			jtex-1.52/JTeXfonts/dnpfonts/gothic/tfm; \
	)

do-install:
	@(cd ${FONTSDIR}; ${MKDIR} ${TARGETDIRS})
	@(cd ${WRKSRC}; \
	${INSTALL_PROGRAM} mka2bkvf mka2nvf mkn2avf mkp2nvf ${PREFIX}/bin; \
	)
.for t in ${TARGETDIRS}
	@${INSTALL_DATA} ${WRKSRC}/${t}/* ${FONTSDIR}/${t}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/jfm/* ${FONTSDIR}/vf-a2bk
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTSDOCDIR}
	@(cd ${WRKSRC}; \
	${INSTALL_SCRIPT} MKASC2BKall MKASC2NTT MKNTT2ASC MKPTEX2PNTT ${PORTSDOCDIR}; \
	${INSTALL_DATA} Makefile README vfdata.doc ${PORTSDOCDIR}; \
	)
.endif

.include <bsd.port.mk>
