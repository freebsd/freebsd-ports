PORTNAME=	wmicons
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	graphics windowmaker
MASTER_SITES=	LOCAL/kiri/wmicons \
		WINDOWMAKER/contrib/old/icons \
		PORTS_JP \
		http://www.itlb.te.noda.tus.ac.jp/~manome/wmaker/archive/
DISTFILES=	${EXTRACT_ONLY} isiconpack4.tgz
EXTRACT_ONLY=	DWiconpack1.tar.gz DWiconpack2.tar.gz IconFest-1.2.tgz \
		NeXT_XEmacs_tar.gz  wm_icons_png.tar.gz wm_icons_tif.tar.gz \
		japanese-step-icons1.1.tar.gz \
		KTermIcons-1.0.tar.gz \
		WindowMaker-extra-0.1.tar.gz

MAINTAINER=	gamato@users.sf.net
COMMENT=	Icons mainly for use in Window Maker

GNU_CONFIGURE=	yes
PORTDOCS=	*

WRKSRC=		${WRKDIR}/WindowMaker-extra-0.1
WMICONDIR=	${STAGEDIR}${PREFIX}/share/WindowMaker/Pixmaps

OPTIONS_DEFINE=	DOCS

post-extract:
	${MKDIR} ${WRKDIR}/isiconpack4
	${TAR} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/isiconpack4.tgz \
		${EXTRACT_AFTER_ARGS} -C ${WRKDIR}/isiconpack4

post-install:
	${MKDIR} ${WMICONDIR}
	cd ${WRKDIR}/IconFest-1.2; \
	${INSTALL_DATA} *.xpm *.tif ${WMICONDIR}
	cd ${WRKDIR}/Icons; \
	${INSTALL_DATA} *.xpm ${WMICONDIR}
	cd ${WRKDIR}/NeXT.XEmacs; \
	${INSTALL_DATA} ./*/*.xpm ${WMICONDIR}
	cd ${WRKDIR}/dwiconpack1; \
	${INSTALL_DATA} *.tif ${WMICONDIR}
	cd ${WRKDIR}/dwiconpack2; \
	${INSTALL_DATA} *.tif ${WMICONDIR}
	cd ${WRKDIR}/isiconpack4; \
	${INSTALL_DATA} *.xpm *.tif ${WMICONDIR}
	cd ${WRKDIR}/japanese-step-icons; \
	${INSTALL_DATA} *.xpm ${WMICONDIR}
	cd ${WRKDIR}/vf_png; \
	${INSTALL_DATA} *.png ${WMICONDIR}
	cd ${WRKDIR}/vf_tif; \
	${INSTALL_DATA} *.tif ${WMICONDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/IconFest-1.2/README \
		${STAGEDIR}${DOCSDIR}/README.IconFest
	${INSTALL_DATA} ${WRKDIR}/NeXT.XEmacs/README.NeXT.XEmacs \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dwiconpack1/dwiconpack1.README \
		${STAGEDIR}${DOCSDIR}/README.dwiconpack1
	${INSTALL_DATA} ${WRKDIR}/dwiconpack2/dwiconpack2.README \
		${STAGEDIR}${DOCSDIR}/README.dwiconpack2
	${INSTALL_DATA} ${WRKDIR}/isiconpack4/CREDITS \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/japanese-step-icons/README.txt \
		${STAGEDIR}${DOCSDIR}/README.japanese-step-icons.txt
	${INSTALL_DATA} ${WRKDIR}/vf_png/README \
		${STAGEDIR}${DOCSDIR}/README.vf_png
	${INSTALL_DATA} ${WRKDIR}/vf_tif/README \
		${STAGEDIR}${DOCSDIR}/README.vf_tif

.include <bsd.port.mk>
