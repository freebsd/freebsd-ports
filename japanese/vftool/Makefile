# New ports collection makefile for: virtual fonts tools
# Version required:	1.2
# Date created:		12 September 1997
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.3 1998/03/22 07:58:44 asami Exp $
#

DISTNAME=	vftool-1.2
PKGNAME=	ja-vftool-1.2
CATEGORIES=	print japanese
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

BUILD_DEPENDS=	${JFMDIR}/goth10.tfm:${PORTSDIR}/japanese/ptex-${JACODE} \
		${AFMDIR}/GothicBBB-Medium-H:${PORTSDIR}/japanese/japaneseAFM \
		${GOTTFMDIR}/dgjgreek10.tfm:${PORTSDIR}/japanese/jtex209-${JTEX} \
		${PKDIR}/dmjsy10.${RESOLUTION}pk:${PORTSDIR}/japanese/pkfonts

ALL_TARGET=	n2a a2n a2bk p2pn tjsy tjsypk rot
SCRIPTS_ENV=	SED=${SED} \
		PKDIR=${PKDIR} WRKSRC=${WRKSRC} \
		AFMDIR=${AFMDIR} GOTTFMDIR=${GOTTFMDIR} \
		JFMDIR=${JFMDIR} MINTFMDIR=${MINTFMDIR}
MAKE_ENV=	AFM=${AFMDIR} GOTTFM=${GOTTFMDIR} JFM=${JFMDIR} \
		MINTFM=${MINTFMDIR} PK=${PKDIR}

AFMDIR=		${PREFIX}/share/fonts/afm
FONTSDIR=	${PREFIX}/share/fonts
GOTTFMDIR=	${PREFIX}/share/tex/jfonts/gothic
JFMDIR=		${PREFIX}/share/texmf/fonts/tfm/ptex
MINTFMDIR=	${PREFIX}/share/tex/jfonts/mincho
PKDIR=		${PREFIX}/lib/fonts/pk${RESOLUTION}J
PORTSDOCDIR=	${PREFIX}/share/doc/vftool
TARGETDIRS=	vf-n2a vf-a2n vf-a2bk vf-p2pn vf-tjsy pk-tjsy

pre-configure:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.tmpl

do-install:
	@(cd ${FONTSDIR}; ${MKDIR} ${TARGETDIRS})
	@(cd ${WRKSRC}; \
	${INSTALL_PROGRAM} mka2bkvf mka2nvf mkn2avf mkp2nvf mktjsyvf \
		mktjsygf mkrotvf mkrotgf ${PREFIX}/bin; \
	)
.for t in ${TARGETDIRS}
	@${INSTALL_DATA} ${WRKSRC}/${t}/* ${FONTSDIR}/${t}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/jfm/* ${FONTSDIR}/vf-a2bk
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTSDOCDIR}
	@(cd ${WRKSRC}; \
	${INSTALL_SCRIPT} MKASC2BKall MKASC2NTT MKNTT2ASC MKPTEX2PNTT \
		MKTJSY MKTJSYPK ${PORTSDOCDIR}; \
	${INSTALL_DATA} Makefile README vfdata.doc ${PORTSDOCDIR}; \
	)
.endif

.include "${.CURDIR}/Makefile.inc"
.include <bsd.port.mk>
