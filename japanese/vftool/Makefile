# Created by: KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	vftool
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/ \
		LOCAL/kiri
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		plib13-euc.tar.gz \
		jtex-1.52.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual font kit (n2a,a2n,a2bk,p2pn)

BUILD_DEPENDS=	${LOCALBASE}/share/fonts/afm/GothicBBB-Medium-H:japanese/japaneseAFM

ALL_TARGET=	n2a a2n a2bk p2pn
SCRIPTS_ENV=	MV=${MV} SED=${SED} AFMDIR=${AFMDIR} JFMDIR=${JFMDIR}
MAKE_ENV=	AFM=${AFMDIR} JFM=${JFMDIR}

AFMDIR=		${PREFIX}/share/fonts/afm
FONTSDIR=	${PREFIX}/share/fonts
JFMDIR=		${WRKDIR}/share/texmf/fonts/tfm/ptex
TARGETDIRS=	vf-n2a vf-a2n vf-a2bk vf-p2pn

BROKEN_ia64=	Coredump during build on ia64

OPTIONS_DEFINE=	DOCS

post-extract:
	(cd ${WRKDIR}; \
		${TAR} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/plib13-euc.tar.gz \
			${EXTRACT_AFTER_ARGS} \
			share/texmf/fonts/tfm/ptex; \
		${TAR} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/jtex-1.52.tar.gz \
			${EXTRACT_AFTER_ARGS} \
			jtex-1.52/JTeXfonts/dnpfonts/mincho/tfm \
			jtex-1.52/JTeXfonts/dnpfonts/gothic/tfm; \
	)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} mka2bkvf mka2nvf mkn2avf mkp2nvf \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${TARGETDIRS}" \
		${STAGEDIR}${FONTSDIR})
	${INSTALL_DATA} ${WRKSRC}/jfm/* ${STAGEDIR}${FONTSDIR}/vf-a2bk
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} MKASC2BKall MKASC2NTT MKNTT2ASC \
		MKPTEX2PNTT ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} Makefile README vfdata.doc \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
